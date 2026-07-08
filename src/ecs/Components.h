// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation

#pragma once

#include "Vector3d.h"
#include "Quaternion.h"
#include <cstdint>

namespace ecs {

// ============================================================================
// Transform / Motion State
// ============================================================================

/**
 * @brief Core 6DOF spatial and motion state.
 * Contains current and previous frame values for integration and interpolation.
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
// Kinematic (Movement Physics)
// ============================================================================

/**
 * @brief Physics parameters for entities that participate in movement simulation.
 * Presence of this component implies the entity is kinematic (can move via physics).
 * Mass and agility-related attributes live here.
 */
struct KinematicComponent {
    double mass = 0.0;
    float agility = 0.0f;
    float maxVelocity = 0.0f;
    float maxAngularVelocity = 0.0f;
    float rollAgility = 0.0f;
};

// ============================================================================
// Collidable (Collision Participation)
// ============================================================================

/**
 * @brief Collision-relevant data.
 * Presence of this component means the entity participates in collision detection.
 * Bounding volume data lives here.
 */
struct CollidableComponent {
    float radius = 0.0f;
    // Future: collision layer/mask, shape type, etc.
};

// ============================================================================
// Collision Shape Primitives (Mini* shapes)
// ============================================================================

/**
 * @brief Spherical collision primitive (MiniBall).
 * Simple sphere with local offset and radius.
 */
struct SphereComponent {
    Vector3d localPosition;
    float radius = 0.0f;
};

/**
 * @brief Box-shaped collision primitive (MiniBox).
 * Defined by local position, half-extents, and optional orientation.
 */
struct BoxComponent {
    Vector3d localPosition;
    Vector3d halfExtents;
    Quaternion orientation;
};

/**
 * @brief Capsule-shaped collision primitive (MiniCapsule).
 * Defined by local position, axis direction, radius, and half-length.
 */
struct CapsuleComponent {
    Vector3d localPosition;
    Vector3d axis;           // Should be normalized
    float radius = 0.0f;
    float halfLength = 0.0f;
};

// ============================================================================
// Behavioral Mode (from DSTBALLMODE)
// ============================================================================

/**
 * @brief Complete set of behavioral modes from the original DSTBALLMODE constants.
 * This enum should be kept in sync with the original DSTBALLMODE definition.
 */
enum class BallMode : uint8_t {
    Stop      = 0,
    Goto,
    Follow,
    Orbit,
    Missile,
    Warp,
    Approach,
    Flee,
    Stopped,
    Boost,
    Hold,
    Warping,
    Milling,
    Evade,
    Dock,
    Undock,
    // Additional modes from DSTBALLMODE should be added here as identified
};

/**
 * @brief Current behavioral mode and associated parameters.
 */
struct BallModeComponent {
    BallMode mode = BallMode::Stop;

    // Mode-specific targeting / orbit data
    Vector3d targetPosition;
    uint64_t targetEntity = 0;
    float orbitRadius = 0.0f;
    float orbitSpeed = 0.0f;
};

// ============================================================================
// Proximity Sensor
// ============================================================================

/**
 * @brief Proximity sensor configuration and runtime state.
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
 * @brief Formation membership and slot assignment.
 */
struct FormationComponent {
    uint64_t formationLeader = 0;
    uint32_t formationSlot = 0;
    bool inFormation = false;
};

// ============================================================================
// Cloaking
// ============================================================================

/**
 * @brief Cloaking state and timers.
 */
struct CloakComponent {
    bool isCloaked = false;
    float cloakStrength = 0.0f;
    double cloakTimer = 0.0;
};

// ============================================================================
// Harmonics / Effects
// ============================================================================

/**
 * @brief Harmonics and special effect state.
 */
struct HarmonicsComponent {
    uint32_t harmonicState = 0;
    double harmonicTimer = 0.0;
};

// ============================================================================
// Spatial Partitioning
// ============================================================================

/**
 * @brief Data related to the hierarchical grid / spatial partition system.
 */
struct SpatialPartitionComponent {
    uint32_t activeBoxCount = 0;
    // Can be expanded when a data-oriented Partition system is implemented.
};

} // namespace ecs
