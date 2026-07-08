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

// === Compile-time helpers to find index of a type in a parameter pack ===

template <typename T, typename... Ts>
struct index_of;

template <typename T, typename... Ts>
struct index_of<T, T, Ts...> : std::integral_constant<std::size_t, 0> {};

template <typename T, typename U, typename... Ts>
struct index_of<T, U, Ts...> : std::integral_constant<std::size_t, 1 + index_of<T, Ts...>::value> {};

/**
 * @brief Generic storage for one archetype using Structure-of-Arrays layout.
 *
 * This class is fully generic. It uses variadic templates so it can support
 * any combination of component types without modification.
 */
template <typename... Components>
class ArchetypeStorage {
public:
    ArchetypeStorage() = default;

    /**
     * @brief Adds an entity with its component data to this storage.
     */
    void addEntity(Entity entity, Components... comps) {
        entities.push_back(entity);
        addToArrays(std::index_sequence_for<Components...>{}, std::forward<Components>(comps)...);
    }

    /**
     * @brief Returns how many entities are in this storage.
     */
    size_t size() const noexcept { return entities.size(); }

    /**
     * @brief Returns the entity ID array.
     */
    const std::vector<Entity>& getEntities() const noexcept { return entities; }

    /**
     * @brief Returns a reference to the component array for type T.
     *
     * @tparam T The component type to access.
     * @return Reference to the internal std::vector<T>.
     */
    template <typename T>
    std::vector<T>& getComponentArray() {
        constexpr std::size_t Index = index_of<T, Components...>::value;
        return std::get<Index>(componentArrays);
    }

    template <typename T>
    const std::vector<T>& getComponentArray() const {
        constexpr std::size_t Index = index_of<T, Components...>::value;
        return std::get<Index>(componentArrays);
    }

private:
    std::vector<Entity> entities;
    std::tuple<std::vector<Components>...> componentArrays;

    template <std::size_t... Is>
    void addToArrays(std::index_sequence<Is...>, Components&&... comps) {
        (std::get<Is>(componentArrays).push_back(std::forward<Components>(comps)), ...);
    }
};

} // namespace ecs
