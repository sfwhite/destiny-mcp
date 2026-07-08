// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation

#include "EntityManager.h"

namespace ecs {

EntityManager::EntityManager() = default;
EntityManager::~EntityManager() = default;

uint64_t EntityManager::CreateEntity() {
    uint64_t id = mNextEntityId++;
    if (mGenerations.size() < id) {
        mGenerations.resize(id + 1, 0);
    }
    return id;
}

void EntityManager::DestroyEntity(uint64_t entity) {}

bool EntityManager::IsAlive(uint64_t entity) const {
    return entity > 0 && entity < mNextEntityId;
}

} // namespace ecs
