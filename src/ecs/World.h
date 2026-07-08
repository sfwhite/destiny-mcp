// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation (modified)

#pragma once

#include "EntityManager.h"
#include "ArchetypeStorage.h"
#include <vector>
#include <memory>
#include <unordered_map>

namespace ecs {

class World {
public:
    World();
    ~World();

    void Initialize();

    EntityManager& GetEntityManager() { return *mEntityManager; }
    const EntityManager& GetEntityManager() const { return *mEntityManager; }

    uint64_t CreateEntity();

    void AddTransform(uint64_t entity, const TransformComponent& component);
    void AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& component);
    void AddMode(uint64_t entity, const ModeComponent& component);

private:
    std::unique_ptr<EntityManager> mEntityManager;
    std::unordered_map<uint32_t, std::unique_ptr<ArchetypeStorage>> mArchetypeStorages;

    ArchetypeStorage* GetOrCreateStorage(uint32_t signature);
};

} // namespace ecs
