// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation

#pragma once

#include "Vector3d.h"
#include "Quaternion.h"
#include <cstdint>

namespace ecs {

// ============================================================================
// TRANSFORM / MOTION STATE
// Source: Ball.h
// ============================================================================

struct TransformComponent {
    // Current frame
    Vector3d position;             // From Ball::mNewPos
    Vector3d velocity;             // From Ball::mNewVel
    Quaternion rotation;           // From Ball::mNewRot
    Vector3d angularVelocity;      // From Ball::mNewAngVel

    // Previous frame (for integration / interpolation)
    Vector3d oldPosition;          // From Ball::mOldPos
    Vector3d oldVelocity;          // From Ball::mOldVel
    Quaternion oldRotation;        // From Ball::mOldRot
    Vector3d oldAngularVelocity;   // From Ball::mOldAngVel
};

// ============================================================================
// KINEMATIC (Movement Physics Parameters)
// Source: Ball.h - physics parameters used for movement simulation
// ============================================================================

struct KinematicComponent {
    double mass = 0.0;               // From Ball physics parameters (mass)
    float agility = 0.0f;            // From Ball physics parameters (agility)
    float maxVelocity = 0.0f;        // From Ball physics parameters (maxVelocity)
    float maxAngularVelocity = 0.0f; // From Ball physics parameters (maxAngularVelocity)
    float rollAgility = 0.0f;        // From Ball physics parameters (rollAgility)
};

// ============================================================================
// COLLIDABLE
// Source: Ball collision participation + radius + Mini* shapes
// ============================================================================

struct CollidableComponent {
    float radius = 0.0f;             // From Ball radius and compound Mini* collision data
};

// ============================================================================
// COLLISION SHAPE PRIMITIVES (Mini* shapes)
// Source: Ball.h - mMiniBalls, mMiniBoxes, mMiniCapsules
// ============================================================================

struct SphereComponent {
    Vector3d localPosition;          // Local offset from parent entity (MiniBall data)
    float radius = 0.0f;             // Radius of the spherical primitive (MiniBall)
};

struct BoxComponent {
    Vector3d localPosition;          // Local offset from parent entity (MiniBox data)
    Vector3d halfExtents;            // Half-extents of the box (MiniBox data)
    Quaternion orientation;          // Orientation of the box primitive
};

struct CapsuleComponent {
    Vector3d localPosition;          // Local offset from parent entity (MiniCapsule data)
    Vector3d axis;                   // Direction of the capsule axis
    float radius = 0.0f;             // Radius of the capsule
    float halfLength = 0.0f;         // Half-length of the capsule
};

// ============================================================================
// BEHAVIORAL MODE
// Source: Ball.h - mMode (DSTBALLMODE) and mode-specific data
// ============================================================================

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
};

struct BallModeComponent {
    BallMode mode = BallMode::Stop;  // From Ball::mMode (DSTBALLMODE)

    // Mode-specific parameters
    Vector3d targetPosition;         // Target position (Goto / Approach / Warp modes)
    uint64_t targetEntity = 0;       // Target entity (Follow / Orbit modes)
    float orbitRadius = 0.0f;        // Orbit radius (Orbit mode)
    float orbitSpeed = 0.0f;         // Orbit speed (Orbit mode)
};

// ============================================================================
// PROXIMITY SENSOR
// Source: Ball.h - ProximitySensor struct (mSensor)
// ============================================================================

struct ProximityComponent {
    float range = 0.0f;              // From ProximitySensor::range
    double period = 2.0;             // From ProximitySensor::period
    double elapsed = 0.0;            // From ProximitySensor::elapsed
    bool active = false;             // From ProximitySensor::active
    bool onlyInteractives = false;   // From ProximitySensor::onlyInteractives
};

// ============================================================================
// OWNERSHIP & IDENTITY
// Source: Ball ownership, alliance, and corporation data
// ============================================================================

struct OwnershipComponent {
    uint64_t ownerId = 0;            // Owner entity ID
    uint32_t allianceId = 0;         // Alliance ID
    uint32_t corporationId = 0;      // Corporation ID
};

// ============================================================================
// FORMATION
// Source: Ball formation membership data
// ============================================================================

struct FormationComponent {
    uint64_t formationLeader = 0;    // Formation leader entity ID
    uint32_t formationSlot = 0;      // Slot index in formation
    bool inFormation = false;        // Whether currently in formation
};

// ============================================================================
// CLOAKING
// Source: Ball cloaking state and timers
// ============================================================================

struct CloakComponent {
    bool isCloaked = false;          // Current cloaked state
    float cloakStrength = 0.0f;      // Cloak strength / effectiveness
    double cloakTimer = 0.0;         // Cloak timer
};

// ============================================================================
// HARMONICS / SPECIAL EFFECTS
// Source: Ball harmonics and effect state
// ============================================================================

struct HarmonicsComponent {
    uint32_t harmonicState = 0;      // Current harmonics state
    double harmonicTimer = 0.0;      // Harmonics timer
};

// ============================================================================
// SPATIAL PARTITIONING
// Source: Ball grid/partition data and Ballpark spatial system
// ============================================================================

struct SpatialPartitionComponent {
    uint32_t activeBoxCount = 0;     // Number of currently active partition boxes
};

// ============================================================================
// BUBBLE (Spatial Interest Region)
// Source: Destiny spatial partitioning and interest management bubbles
// ============================================================================

struct BubbleComponent {
    Vector3d center;                 // Center of the bubble region
    float radius = 0.0f;             // Radius of the bubble
    uint32_t gridLevel = 0;          // Hierarchical grid level
    uint32_t bubbleId = 0;           // Unique bubble identifier
    bool active = true;              // Whether bubble is active
};

// ============================================================================
// WRECK / DEBRIS
// Source: Wreck and debris entities managed by Ballpark
// ============================================================================

struct WreckComponent {
    uint32_t wreckType = 0;          // Type of wreck
    double decayTimer = 0.0;         // Decay / lifetime timer
    bool hasLoot = false;            // Whether wreck has loot
};

} // namespace ecs
