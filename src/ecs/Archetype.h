// Copyright © 2026 Stephan White
// Author: Stephan White <stephan.f.white@gmail.com>
// Phase 0 - ECS Foundation

#pragma once

#include <cstdint>

namespace ecs {

/**
 * @brief Represents a unique combination of component types (an "archetype").
 *
 * In an ECS, entities that have the exact same set of components belong to the same archetype.
 * This allows us to store their data contiguously for excellent cache performance.
 *
 * For Phase 0, we use a simple 32-bit bitmask to represent which components an archetype contains.
 * Each bit position corresponds to a specific component type.
 */
class Archetype {
public:
    /**
     * @brief Default constructor. Creates an empty archetype (no components).
     */
    Archetype();

    /**
     * @brief Constructs an archetype from a component signature bitmask.
     * @param signature A bitmask where each set bit represents a component type present in this archetype.
     */
    explicit Archetype(uint32_t signature);

    /**
     * @brief Returns the component signature bitmask of this archetype.
     */
    uint32_t GetSignature() const { return mSignature; }

    /**
     * @brief Checks whether this archetype contains a specific component type.
     * @param componentBit The bit position corresponding to the component (e.g. 1 << 0 for Transform).
     * @return true if the component is part of this archetype.
     */
    bool HasComponent(uint32_t componentBit) const;

private:
    /// Bitmask representing the set of components in this archetype.
    uint32_t mSignature;
};

} // namespace ecs
