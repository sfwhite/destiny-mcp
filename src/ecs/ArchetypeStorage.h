// Copyright © 2026 Stephan White
// Author: Stephan White <stephan.f.white@gmail.com>
// Phase 0 - ECS Foundation

#pragma once

#include "Archetype.h"
#include "Components.h"
#include <vector>
#include <cstdint>

namespace ecs {

/**
 * @brief Stores all entities that belong to one specific archetype in Structure-of-Arrays (SoA) layout.
 *
 * This is the core storage unit in an archetype-based ECS. All entities in one ArchetypeStorage
 * have exactly the same components, allowing us to iterate over them very efficiently.
 *
 * For Phase 0 we support a fixed set of components. In later phases this can be made fully generic.
 */
class ArchetypeStorage {
public:
    /**
     * @brief Constructs storage for a given archetype.
     * @param archetype The archetype this storage is responsible for.
     */
    explicit ArchetypeStorage(const Archetype& archetype);

    /**
     * @brief Returns the archetype associated with this storage.
     */
    const Archetype& GetArchetype() const { return mArchetype; }

    /**
     * @brief Adds a new entity to this storage with the given components.
     *        All required components for the archetype must be provided.
     */
    void AddEntity(uint64_t entity,
                   const TransformComponent& transform,
                   const PhysicsPropertiesComponent& physics,
                   const ModeComponent& mode);

    /**
     * @brief Returns the number of entities currently stored in this archetype.
     */
    size_t GetEntityCount() const { return mEntities.size(); }

    // Accessors for component arrays (SoA layout)
    std::vector<uint64_t>& GetEntities() { return mEntities; }
    std::vector<TransformComponent>& GetTransforms() { return mTransforms; }
    std::vector<PhysicsPropertiesComponent>& GetPhysicsProperties() { return mPhysicsProperties; }
    std::vector<ModeComponent>& GetModes() { return mModes; }

private:
    /// The archetype this storage represents
    Archetype mArchetype;

    /// Entity IDs stored in this archetype
    std::vector<uint64_t> mEntities;

    /// Component arrays (Structure of Arrays)
    std::vector<TransformComponent> mTransforms;
    std::vector<PhysicsPropertiesComponent> mPhysicsProperties;
    std::vector<ModeComponent> mModes;
};

} // namespace ecs
