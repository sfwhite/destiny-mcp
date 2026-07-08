// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation

#pragma once

#include <cstdint>
#include <vector>

namespace ecs {

/**
 * @brief Manages creation and destruction of entity IDs.
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
    std::vector<uint32_t> mGenerations;
};

} // namespace ecs
