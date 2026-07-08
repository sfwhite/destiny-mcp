// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation (modified)

#pragma once

#include "EntityManager.h"
#include "ArchetypeStorage.h"
#include <unordered_map>
#include <memory>

namespace ecs {

/**
 * @brief The main ECS container.
 *
 * World is responsible for:
 * - Managing entity lifecycle via EntityManager
 * - Creating and looking up ArchetypeStorage instances
 * - Tracking which archetype each entity currently belongs to
 *
 * This class is still evolving. Full generic archetype management will improve in later steps.
 */
class World {
public:
    World();
    ~World();

    /**
     * @brief Initializes internal structures (e.g. default empty archetype).
     */
    void Initialize();

    EntityManager& GetEntityManager() { return *mEntityManager; }
    const EntityManager& GetEntityManager() const { return *mEntityManager; }

    /**
     * @brief Creates a new entity and places it in the default (empty) archetype.
     * @return The newly created entity ID.
     */
    uint64_t CreateEntity();

    /**
     * @brief Adds a TransformComponent to an entity.
     *        May move the entity to a different archetype.
     */
    void AddTransform(uint64_t entity, const TransformComponent& component);

    /**
     * @brief Adds a PhysicsPropertiesComponent to an entity.
     */
    void AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& component);

    /**
     * @brief Adds a ModeComponent to an entity.
     */
    void AddMode(uint64_t entity, const ModeComponent& component);

private:
    std::unique_ptr<EntityManager> mEntityManager;

    /// Maps archetype signature (bitmask) to its storage.
    /// Using type erasure via base class for now to manage different template instantiations.
    std::unordered_map<uint32_t, std::unique_ptr<class IArchetypeStorage>> mStorages;

    /// Tracks which archetype (by signature) each entity currently belongs to.
    std::unordered_map<uint64_t, uint32_t> mEntityToSignature;

    /**
     * @brief Gets or creates an ArchetypeStorage for the given signature.
     */
    IArchetypeStorage* GetOrCreateStorage(uint32_t signature);
};

} // namespace ecs
