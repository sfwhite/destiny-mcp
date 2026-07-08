// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#pragma once

#include "EntityManager.h"
#include "Components.h"
#include <unordered_map>
#include <memory>

namespace ecs {

class World {
public:
    World();
    ~World();

    void Initialize();

    EntityManager& GetEntityManager() { return *mEntityManager; }
    const EntityManager& GetEntityManager() const { return *mEntityManager; }

    // Entity creation convenience
    uint64_t CreateEntity();

    // Component management (basic storage for Phase 0)
    void AddTransform(uint64_t entity, const TransformComponent& component);
    TransformComponent* GetTransform(uint64_t entity);
    bool HasTransform(uint64_t entity) const;

    void AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& component);
    PhysicsPropertiesComponent* GetPhysicsProperties(uint64_t entity);

    void AddMode(uint64_t entity, const ModeComponent& component);
    ModeComponent* GetMode(uint64_t entity);

private:
    std::unique_ptr<EntityManager> mEntityManager;

    // Basic component storage (will be replaced with better archetype storage later)
    std::unordered_map<uint64_t, TransformComponent> mTransforms;
    std::unordered_map<uint64_t, PhysicsPropertiesComponent> mPhysicsProperties;
    std::unordered_map<uint64_t, ModeComponent> mModes;
};

} // namespace ecs
