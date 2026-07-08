// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation (modified)

#include "World.h"
#include "Archetype.h"

namespace ecs {

constexpr uint32_t TRANSFORM_BIT = 1 << 0;
constexpr uint32_t PHYSICS_BIT   = 1 << 1;
constexpr uint32_t MODE_BIT      = 1 << 2;

World::World() {
    mEntityManager = std::make_unique<EntityManager>();
}

World::~World() = default;

void World::Initialize() {
    GetOrCreateStorage(0);
}

uint64_t World::CreateEntity() {
    uint64_t entity = mEntityManager->CreateEntity();
    ArchetypeStorage* storage = GetOrCreateStorage(0);
    storage->AddEntity(entity, {}, {}, {});
    return entity;
}

void World::AddTransform(uint64_t entity, const TransformComponent& component) {
    uint32_t sig = TRANSFORM_BIT;
    ArchetypeStorage* storage = GetOrCreateStorage(sig);
    storage->AddEntity(entity, component, {}, {});
}

void World::AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& component) {
    uint32_t sig = PHYSICS_BIT;
    ArchetypeStorage* storage = GetOrCreateStorage(sig);
    storage->AddEntity(entity, {}, component, {});
}

void World::AddMode(uint64_t entity, const ModeComponent& component) {
    uint32_t sig = MODE_BIT;
    ArchetypeStorage* storage = GetOrCreateStorage(sig);
    storage->AddEntity(entity, {}, {}, component);
}

ArchetypeStorage* World::GetOrCreateStorage(uint32_t signature) {
    auto it = mArchetypeStorages.find(signature);
    if (it != mArchetypeStorages.end()) return it->second.get();

    auto storage = std::make_unique<ArchetypeStorage>(Archetype(signature));
    ArchetypeStorage* ptr = storage.get();
    mArchetypeStorages[signature] = std::move(storage);
    return ptr;
}

} // namespace ecs
