// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#pragma once

#include "EntityManager.h"
#include <memory>

namespace ecs {

/**
 * World - The central ECS container.
 * Owns the EntityManager and will eventually own all component storage
 * and registered Systems.
 */
class World {
public:
    World();
    ~World();

    void Initialize();

    EntityManager& GetEntityManager() { return *mEntityManager; }
    const EntityManager& GetEntityManager() const { return *mEntityManager; }

    // Future: AddComponent, RemoveComponent, GetComponent, etc.

private:
    std::unique_ptr<EntityManager> mEntityManager;
};

} // namespace ecs
