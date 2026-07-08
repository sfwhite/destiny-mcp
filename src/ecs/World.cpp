// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation (modified)

#include "World.h"
#include "Archetype.h"
#include "Components.h"

namespace ecs {

constexpr uint32_t KINEMATIC_BIT  = 1u << 0;
constexpr uint32_t COLLIDABLE_BIT = 1u << 1;
constexpr uint32_t MODE_BIT       = 1u << 2;

class IArchetypeStorage {
public:
    virtual ~IArchetypeStorage() = default;
    virtual size_t size() const = 0;
};

template <typename... Components>
class ArchetypeStorageWrapper : public IArchetypeStorage {
public:
    ArchetypeStorage<Components...> storage;
    size_t size() const override { return storage.size(); }
};

World::World() {
    mEntityManager = std::make_unique<EntityManager>();
}

World::~World() = default;

void World::Initialize() {
    GetOrCreateStorage(0);
}

uint64_t World::CreateEntity() {
    uint64_t entity = mEntityManager->CreateEntity();
    mEntityToSignature[entity] = 0;
    GetOrCreateStorage(0);
    return entity;
}

void World::AddKinematic(uint64_t entity, const KinematicComponent& component) {
    uint32_t oldSig = mEntityToSignature[entity];
    uint32_t newSig = oldSig | KINEMATIC_BIT;

    if (newSig != oldSig) {
        MoveEntityToArchetype(entity, newSig);
    }
}

void World::AddCollidable(uint64_t entity, const CollidableComponent& component) {
    uint32_t oldSig = mEntityToSignature[entity];
    uint32_t newSig = oldSig | COLLIDABLE_BIT;

    if (newSig != oldSig) {
        MoveEntityToArchetype(entity, newSig);
    }
}

void World::AddBallMode(uint64_t entity, const BallModeComponent& component) {
    uint32_t oldSig = mEntityToSignature[entity];
    uint32_t newSig = oldSig | MODE_BIT;

    if (newSig != oldSig) {
        MoveEntityToArchetype(entity, newSig);
    }
}

void World::MoveEntityToArchetype(uint64_t entity, uint32_t newSignature) {
    uint32_t oldSignature = mEntityToSignature[entity];

    if (oldSignature == newSignature) return;

    mEntityToSignature[entity] = newSignature;
    GetOrCreateStorage(newSignature);
}

IArchetypeStorage* World::GetOrCreateStorage(uint32_t signature) {
    auto it = mStorages.find(signature);
    if (it != mStorages.end()) {
        return it->second.get();
    }

    auto wrapper = std::make_unique<ArchetypeStorageWrapper<KinematicComponent, CollidableComponent, BallModeComponent>>();
    IArchetypeStorage* ptr = wrapper.get();
    mStorages[signature] = std::move(wrapper);
    return ptr;
}

} // namespace ecs
