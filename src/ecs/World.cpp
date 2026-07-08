// Copyright © 2026 Stephan White
// Author: Stephan White <stephan.f.white@gmail.com>
// Phase 0 - ECS Foundation (modified original file)

#include "World.h"
#include "Archetype.h"

namespace ecs {

// Component bit positions (can be expanded later)
constexpr uint32_t TRANSFORM_BIT     = 1 << 0;
constexpr uint32_t PHYSICS_BIT       = 1 << 1;
constexpr uint32_t MODE_BIT          = 1 << 2;

World::World() {
    mEntityManager = std::make_unique<EntityManager>();
}

World::~World() = default;

void World::Initialize() {
    // Create the default empty archetype (signature 0)
    GetOrCreateStorage(0);
}

uint64_t World::CreateEntity() {
    uint64_t entity = mEntityManager->CreateEntity();

    // Place new entity in the default (empty) archetype
    ArchetypeStorage* defaultStorage = GetOrCreateStorage(0);
    defaultStorage->AddEntity(entity, {}, {}, {});  // Empty components for now

    return entity;
}

void World::AddTransform(uint64_t entity, const TransformComponent& component) {
    // For Phase 0 we do a simplified implementation.
    // In a full system we would move the entity between archetypes.
    // For now we just add it to a storage that has Transform.
    uint32_t newSignature = TRANSFORM_BIT;
    ArchetypeStorage* storage = GetOrCreateStorage(newSignature);
    storage->AddEntity(entity, component, {}, {});
}

void World::AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& component) {
    uint32_t newSignature = PHYSICS_BIT;
    ArchetypeStorage* storage = GetOrCreateStorage(newSignature);
    storage->AddEntity(entity, {}, component, {});
}

void World::AddMode(uint64_t entity, const ModeComponent& component) {
    uint32_t newSignature = MODE_BIT;
    ArchetypeStorage* storage = GetOrCreateStorage(newSignature);
    storage->AddEntity(entity, {}, {}, component);
}

ArchetypeStorage* World::GetOrCreateStorage(uint32_t signature) {
    auto it = mArchetypeStorages.find(signature);
    if (it != mArchetypeStorages.end()) {
        return it->second.get();
    }

    auto storage = std::make_unique<ArchetypeStorage>(Archetype(signature));
    ArchetypeStorage* ptr = storage.get();
    mArchetypeStorages[signature] = std::move(storage);
    return ptr;
}

} // namespace ecs
