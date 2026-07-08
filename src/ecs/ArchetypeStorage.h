// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation

#pragma once

#include <vector>
#include <tuple>
#include <cstdint>
#include <type_traits>

namespace ecs {

using Entity = uint64_t;

/**
 * @brief A generic storage container for one archetype using Structure-of-Arrays layout.
 *
 * This class is fully generic via variadic templates. It can hold any combination
 * of component types without hardcoding specific components.
 *
 * Each instantiation of ArchetypeStorage<Components...> represents entities that
 * have exactly the components listed in the template parameter pack.
 *
 * Data is stored in contiguous arrays (SoA) for cache-friendly iteration.
 */
template <typename... Components>
class ArchetypeStorage {
public:
    /**
     * @brief Default constructor.
     */
    ArchetypeStorage() = default;

    /**
     * @brief Adds a new entity along with its component data.
     *
     * @param entity   The entity ID to add.
     * @param comps    The component values for this entity (in the same order as the template parameters).
     */
    void addEntity(Entity entity, Components... comps) {
        entities.push_back(entity);
        addToArrays(std::index_sequence_for<Components...>{}, std::forward<Components>(comps)...);
    }

    /**
     * @brief Returns the number of entities currently stored.
     */
    size_t size() const noexcept { return entities.size(); }

    /**
     * @brief Returns a const reference to the entity ID array.
     */
    const std::vector<Entity>& getEntities() const noexcept { return entities; }

    /**
     * @brief Returns a reference to the component array for a specific type.
     *
     * @tparam T The component type to retrieve the array for.
     * @return Reference to the internal vector storing components of type T.
     */
    template <typename T>
    std::vector<T>& getComponentArray();

    template <typename T>
    const std::vector<T>& getComponentArray() const;

private:
    /// Entity IDs in this archetype
    std::vector<Entity> entities;

    /// Component data stored as a tuple of vectors (Structure of Arrays)
    std::tuple<std::vector<Components>...> componentArrays;

    /**
     * @brief Helper to push components into the correct vectors using index sequence.
     */
    template <std::size_t... Is>
    void addToArrays(std::index_sequence<Is...>, Components&&... comps) {
        (std::get<Is>(componentArrays).push_back(std::forward<Components>(comps)), ...);
    }
};

// Note: Full implementation of getComponentArray<T>() requires additional metaprogramming.
// It will be completed in a follow-up step.

} // namespace ecs
