// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation

#pragma once

#include <vector>
#include <tuple>
#include <cstdint>

namespace ecs {

using Entity = uint64_t;

/**
 * @brief Stores entities and their components for one specific archetype using Structure-of-Arrays.
 *
 * This version is fully generic via variadic templates. Each instantiation of
 * ArchetypeStorage<Components...> corresponds to one unique combination of components.
 *
 * Example:
 *   ArchetypeStorage<TransformComponent, VelocityComponent>
 */
template <typename... Components>
class ArchetypeStorage {
public:
    /**
     * @brief Adds a new entity along with its component data to this storage.
     */
    void addEntity(Entity entity, Components... components) {
        entities.push_back(entity);
        addComponentsToTuple(std::index_sequence_for<Components...>{}, std::forward<Components>(components)...);
    }

    /**
     * @brief Returns the number of entities in this archetype storage.
     */
    size_t size() const { return entities.size(); }

    /**
     * @brief Returns the list of entity IDs in this storage.
     */
    const std::vector<Entity>& getEntities() const { return entities; }

    /**
     * @brief Returns a reference to the component array for a specific component type.
     * @tparam T The component type to retrieve.
     */
    template <typename T>
    std::vector<T>& getComponentArray();

    template <typename T>
    const std::vector<T>& getComponentArray() const;

private:
    std::vector<Entity> entities;
    std::tuple<std::vector<Components>...> componentArrays;

    template <std::size_t... Is>
    void addComponentsToTuple(std::index_sequence<Is...>, Components&&... comps) {
        (std::get<Is>(componentArrays).push_back(std::forward<Components>(comps)), ...);
    }
};

// Partial specialization for getComponentArray
// (Implementation would go in .cpp or be defined here with more metaprogramming)

} // namespace ecs
