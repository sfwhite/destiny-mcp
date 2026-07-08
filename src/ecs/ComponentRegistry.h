// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation

#pragma once

#include <cstdint>
#include <unordered_map>
#include <string>
#include <typeindex>

namespace ecs {

/**
 * @brief Basic Component Registry.
 *
 * Assigns stable runtime IDs to component types.
 * This is the foundation for making the ECS more generic.
 * In later phases this can be extended with size, alignment, construction/destruction functions, etc.
 */
class ComponentRegistry {
public:
    /**
     * @brief Registers a component type and returns its assigned ID.
     *        If the type is already registered, returns the existing ID.
     *
     * @tparam T The component type to register.
     * @return The stable runtime ID for this component type.
     */
    template <typename T>
    static uint32_t registerComponent();

    /**
     * @brief Gets the runtime ID for a previously registered component type.
     *
     * @tparam T The component type.
     * @return The ID, or 0 if not registered.
     */
    template <typename T>
    static uint32_t getComponentId();

    /**
     * @brief Gets the total number of registered component types.
     */
    static uint32_t getRegisteredComponentCount();

private:
    static std::unordered_map<std::type_index, uint32_t> sTypeToId;
    static uint32_t sNextId;
};

// --- Template implementations ---

template <typename T>
uint32_t ComponentRegistry::registerComponent() {
    std::type_index typeIdx(typeid(T));

    auto it = sTypeToId.find(typeIdx);
    if (it != sTypeToId.end()) {
        return it->second;
    }

    uint32_t newId = sNextId++;
    sTypeToId[typeIdx] = newId;
    return newId;
}

template <typename T>
uint32_t ComponentRegistry::getComponentId() {
    std::type_index typeIdx(typeid(T));
    auto it = sTypeToId.find(typeIdx);
    return (it != sTypeToId.end()) ? it->second : 0;
}

} // namespace ecs
