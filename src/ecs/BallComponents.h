// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation

#pragma once

#include "Vector3d.h"
#include "Quaternion.h"
#include <vector>
#include <cstdint>

namespace ecs {

// ============================================================================
// Core Motion / Transform Data
// ============================================================================

/**
 * @brief Position, velocity, rotation and angular velocity (current + previous frame).
 * This is the core 6DOF state used for integration and interpolation.
 */
struct TransformComponent {
    Vector3d position;
    Vector3d velocity;
    Quaternion rotation;
    Vector3d angularVelocity;

    Vector3d oldPosition;
    Vector3d oldVelocity;
    Quaternion oldRotation;
    Vector3d oldAngularVelocity;
};

// ============================================================================
// Physics Properties
// ============================================================================

/**
 * @brief Physical properties that govern movement and collision response.
 */
struct PhysicsPropertiesComponent {
    double mass = 0.0;
    float radius = 0.0f;
    float agility = 0.0f;
    float maxVelocity = 0.0f;
    float maxAngularVelocity = 0.0f;
    float rollAgility = 0.0f;
    bool isMassive = false;
    bool isFixed = false;
    bool isCollidable = true;
};

// ============================================================================
// Behavioral Mode
// ============================================================================

enum class BallMode : uint8_t {
    Stop = 0,
    Goto,
    Follow,
    Orbit,
    Missile,
    // Add other modes from DSTBALLMODE as needed
};

/**
 * @brief Current behavioral mode and mode-specific parameters.
 */
struct BallModeComponent {
    BallMode mode = BallMode::Stop;

    // Mode-specific data (can be expanded or split into separate components later)
    Vector3d targetPosition;
    uint64_t targetEntity = 0;
    float orbitRadius = 0.0f;
    float orbitSpeed = 0.0f;
};

// ============================================================================
// Compound Collision Shapes (Mini* primitives)
// ============================================================================

/**
 * @brief Lightweight collision primitives attached to a Ball (drones, missiles, etc.).
 */
struct CompoundShapeComponent {
    // For Phase 0 we store counts. Full Mini* data can be added later.
    uint32_t miniBallCount = 0;
    uint32_t miniBoxCount = 0;
    uint32_t miniCapsuleCount = 0;
};

// ============================================================================
// Proximity / Sensor Data
// ============================================================================

/**
 * @brief Proximity sensor configuration and state.
 */
struct ProximityComponent {
    float range = 0.0f;
    double period = 2.0;
    double elapsed = 0.0;
    bool active = false;
    bool onlyInteractives = false;
};

// ============================================================================
// Ownership & Identity
// ============================================================================

/**
 * @brief Ownership and alliance information.
 */
struct OwnershipComponent {
    uint64_t ownerId = 0;
    uint32_t allianceId = 0;
    uint32_t corporationId = 0;
};

// ============================================================================
// Formation
// ============================================================================

/**
 * @brief Formation membership and slot information.
 */
struct FormationComponent {
    uint64_t formationLeader = 0;
    uint32_t formationSlot = 0;
    bool inFormation = false;
};

// ============================================================================
// Cloaking & Harmonics
// ============================================================================

/**
 * @brief Cloaking state.
 */
struct CloakComponent {
    bool isCloaked = false;
    float cloakStrength = 0.0f;
    double cloakTimer = 0.0;
};

/**
 * @brief Harmonics / special effect state.
 */
struct HarmonicsComponent {
    uint32_t harmonicState = 0;
    double harmonicTimer = 0.0;
};

// ============================================================================
// Spatial Partitioning Data (for the grid system)
// ============================================================================

/**
 * @brief Data related to the hierarchical grid / partition system.
 */
struct SpatialPartitionComponent {
    // Placeholder for active partition boxes or grid cell info.
    // Can be expanded when the data-oriented Partition system is implemented.
    uint32_t activeBoxCount = 0;
};

} // namespace ecs
