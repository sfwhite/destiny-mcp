// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation (modified)

#include "World.h"
#include "Archetype.h"
#include "ArchetypeStorage.h"

namespace ecs {

// Component bit flags
constexpr uint32_t TRANSFORM_BIT = 1u << 0;
constexpr uint32_t PHYSICS_BIT   = 1u << 1;
constexpr uint32_t MODE_BIT      = 1u << 2;

// Forward declaration of interface
class IArchetypeStorage {
public:
    virtual ~IArchetypeStorage() = default;
    virtual size_t size() const = 0;
};

// Concrete wrapper so we can store different ArchetypeStorage<...> in one map
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
    // Ensure the default empty archetype exists
    GetOrCreateStorage(0);
}

uint64_t World::CreateEntity() {
    uint64_t entity = mEntityManager->CreateEntity();

    // New entities start in the empty archetype (signature 0)
    mEntityToSignature[entity] = 0;

    auto* storage = GetOrCreateStorage(0);
    // We can't easily add components here without knowing the template type.
    // For now we just track the entity.

    return entity;
}

void World::AddTransform(uint64_t entity, const TransformComponent& component) {
    uint32_t oldSig = mEntityToSignature[entity];
    uint32_t newSig = oldSig | TRANSFORM_BIT;

    mEntityToSignature[entity] = newSig;

    auto* storage = GetOrCreateStorage(newSig);
    // Note: Proper data movement between storages will be implemented later.
}

void World::AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& component) {
    uint32_t oldSig = mEntityToSignature[entity];
    uint32_t newSig = oldSig | PHYSICS_BIT;

    mEntityToSignature[entity] = newSig;
    GetOrCreateStorage(newSig);
}

void World::AddMode(uint64_t entity, const ModeComponent& component) {
    uint32_t oldSig = mEntityToSignature[entity];
    uint32_t newSig = oldSig | MODE_BIT;

    mEntityToSignature[entity] = newSig;
    GetOrCreateStorage(newSig);
}

IArchetypeStorage* World::GetOrCreateStorage(uint32_t signature) {
    auto it = mStorages.find(signature);
    if (it != mStorages.end()) {
        return it->second.get();
    }

    // For Phase 0 we create a wrapper for a common archetype.
    // In a more complete implementation we would use a registry to construct the right type.
    auto wrapper = std::make_unique<ArchetypeStorageWrapper<TransformComponent, PhysicsPropertiesComponent, ModeComponent>>();
    IArchetypeStorage* ptr = wrapper.get();
    mStorages[signature] = std::move(wrapper);
    return ptr;
}

} // namespace ecs
