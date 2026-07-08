// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#include "EntityManager.h"

namespace ecs {

EntityManager::EntityManager() = default;
EntityManager::~EntityManager() = default;

uint64_t EntityManager::CreateEntity() {
    uint64_t id = mNextEntityId++;
    // Simple generation tracking (expand later)
    if (mGenerations.size() < id) {
        mGenerations.resize(id + 1, 0);
    }
    return id;
}

void EntityManager::DestroyEntity(uint64_t entity) {
    // TODO(Phase 1): Increment generation, mark as dead
}

bool EntityManager::IsAlive(uint64_t entity) const {
    // TODO(Phase 1): Check generation
    return entity > 0 && entity < mNextEntityId;
}

} // namespace ecs
