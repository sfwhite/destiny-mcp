// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#pragma once

#include "EntityManager.h"
#include "ArchetypeStorage.h"
#include <vector>
#include <memory>
#include <unordered_map>

namespace ecs {

/**
 * @brief The central container of the ECS.
 *
 * The World owns the EntityManager and manages all ArchetypeStorage instances.
 * It is responsible for creating entities and moving them between archetypes
 * when components are added or removed.
 */
class World {
public:
    World();
    ~World();

    /**
     * @brief Initializes the World and creates default archetype storages.
     */
    void Initialize();

    EntityManager& GetEntityManager() { return *mEntityManager; }
    const EntityManager& GetEntityManager() const { return *mEntityManager; }

    /**
     * @brief Creates a new entity and places it in the default (empty) archetype.
     * @return The ID of the newly created entity.
     */
    uint64_t CreateEntity();

    /**
     * @brief Adds a TransformComponent to an entity.
     *        This may move the entity to a different archetype.
     */
    void AddTransform(uint64_t entity, const TransformComponent& component);

    /**
     * @brief Adds PhysicsPropertiesComponent to an entity.
     */
    void AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& component);

    /**
     * @brief Adds ModeComponent to an entity.
     */
    void AddMode(uint64_t entity, const ModeComponent& component);

    // TODO(Phase 1): Add GetComponent<T>, HasComponent<T>, RemoveComponent, etc.

private:
    std::unique_ptr<EntityManager> mEntityManager;

    /// All archetype storages managed by this world.
    /// Keyed by the archetype's signature for quick lookup.
    std::unordered_map<uint32_t, std::unique_ptr<ArchetypeStorage>> mArchetypeStorages;

    /**
     * @brief Helper to get or create an ArchetypeStorage for a given signature.
     */
    ArchetypeStorage* GetOrCreateStorage(uint32_t signature);
};

} // namespace ecs
