// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation (modified)

#pragma once

#include "EntityManager.h"
#include "ArchetypeStorage.h"
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

    uint64_t CreateEntity();

    void AddKinematic(uint64_t entity, const KinematicComponent& component);
    void AddCollidable(uint64_t entity, const CollidableComponent& component);
    void AddBallMode(uint64_t entity, const BallModeComponent& component);

    /**
     * @brief Moves an entity from its current archetype to a new one.
     *        This is the beginning of proper archetype transition support.
     *
     * Note: Full data copying between storages is not yet implemented.
     */
    void MoveEntityToArchetype(uint64_t entity, uint32_t newSignature);

private:
    std::unique_ptr<EntityManager> mEntityManager;

    std::unordered_map<uint32_t, std::unique_ptr<class IArchetypeStorage>> mStorages;
    std::unordered_map<uint64_t, uint32_t> mEntityToSignature;

    IArchetypeStorage* GetOrCreateStorage(uint32_t signature);
};

} // namespace ecs
