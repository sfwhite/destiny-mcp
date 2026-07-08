// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#pragma once

#include <cstdint>
#include <vector>

namespace ecs {

/**
 * EntityManager - Responsible for creating and destroying entity IDs.
 * Uses a simple generation counter for basic safety.
 */
class EntityManager {
public:
    EntityManager();
    ~EntityManager();

    uint64_t CreateEntity();
    void DestroyEntity(uint64_t entity);

    bool IsAlive(uint64_t entity) const;

private:
    uint64_t mNextEntityId = 1;
    std::vector<uint32_t> mGenerations; // generation per entity slot
};

} // namespace ecs
