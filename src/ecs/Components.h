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
// Source: Ball.h - mNewPos, mOldPos, mNewVel, mOldVel, mNewRot, mOldRot,
//                  mNewAngVel, mOldAngVel and related derivatives
// ============================================================================

struct TransformComponent {
    // Current frame
    Vector3d position;        // From Ball::mNewPos
    Vector3d velocity;        // From Ball::mNewVel
    Quaternion rotation;      // From Ball::mNewRot
    Vector3d angularVelocity; // From Ball::mNewAngVel

    // Previous frame (for integration / interpolation)
    Vector3d oldPosition;     // From Ball::mOldPos
    Vector3d oldVelocity;     // From Ball::mOldVel
    Quaternion oldRotation;   // From Ball::mOldRot
    Vector3d oldAngularVelocity; // From Ball::mOldAngVel
};

// ============================================================================
// KINEMATIC (Movement Physics Parameters)
// Source: Ball.h - physics parameters used for movement simulation
// ============================================================================

struct KinematicComponent {
    double mass = 0.0;              // From Ball physics data
    float agility = 0.0f;           // From Ball physics data
    float maxVelocity = 0.0f;       // From Ball physics data
    float maxAngularVelocity = 0.0f;// From Ball physics data
    float rollAgility = 0.0f;       // From Ball physics data
};

// ============================================================================
// COLLIDABLE
// Source: Ball collision participation + radius + Mini* shapes
// ============================================================================

struct CollidableComponent {
    float radius = 0.0f;            // From Ball radius + compound shapes
};

// ============================================================================
// COLLISION SHAPE PRIMITIVES (Mini* shapes)
// Source: Ball.h - mMiniBalls, mMiniBoxes, mMiniCapsules
// ============================================================================

struct SphereComponent {
    Vector3d localPosition;         // Local offset (from MiniBall data)
    float radius = 0.0f;            // From MiniBall radius
};

struct BoxComponent {
    Vector3d localPosition;         // Local offset (from MiniBox data)
    Vector3d halfExtents;           // From MiniBox extents
    Quaternion orientation;         // Orientation of the box
};

struct CapsuleComponent {
    Vector3d localPosition;         // Local offset (from MiniCapsule data)
    Vector3d axis;                  // Direction of capsule axis
    float radius = 0.0f;            // Capsule radius
    float halfLength = 0.0f;        // Half length of capsule
};

// ============================================================================
// BEHAVIORAL MODE
// Source: Ball.h - mMode (DSTBALLMODE) and mode-specific parameters
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
    BallMode mode = BallMode::Stop; // From Ball::mMode

    // Mode-specific data (from various Ball mode structs)
    Vector3d targetPosition;        // Target position for Goto/Approach modes
    uint64_t targetEntity = 0;      // Target entity for Follow/Orbit modes
    float orbitRadius = 0.0f;       // From Orbit mode data
    float orbitSpeed = 0.0f;        // From Orbit mode data
};

// ============================================================================
// PROXIMITY SENSOR
// Source: Ball.h - ProximitySensor struct (mSensor)
// ============================================================================

struct ProximityComponent {
    float range = 0.0f;             // From ProximitySensor::range
    double period = 2.0;            // From ProximitySensor::period
    double elapsed = 0.0;           // From ProximitySensor::elapsed
    bool active = false;            // From ProximitySensor::active
    bool onlyInteractives = false;  // From ProximitySensor::onlyInteractives
};

// ============================================================================
// OWNERSHIP & IDENTITY
// Source: Ball ownership / alliance data
// ============================================================================

struct OwnershipComponent {
    uint64_t ownerId = 0;           // Owner entity ID
    uint32_t allianceId = 0;        // Alliance ID
    uint32_t corporationId = 0;     // Corporation ID
};

// ============================================================================
// FORMATION
// Source: Ball formation data
// ============================================================================

struct FormationComponent {
    uint64_t formationLeader = 0;   // Formation leader entity
    uint32_t formationSlot = 0;     // Slot within formation
    bool inFormation = false;       // Whether currently in formation
};

// ============================================================================
// CLOAKING
// Source: Ball cloaking state
// ============================================================================

struct CloakComponent {
    bool isCloaked = false;         // Cloak active state
    float cloakStrength = 0.0f;     // Cloak strength / effectiveness
    double cloakTimer = 0.0;        // Cloak timer
};

// ============================================================================
// HARMONICS / SPECIAL EFFECTS
// Source: Ball harmonics and effect state
// ============================================================================

struct HarmonicsComponent {
    uint32_t harmonicState = 0;     // Current harmonics state
    double harmonicTimer = 0.0;     // Harmonics timer
};

// ============================================================================
// SPATIAL PARTITIONING
// Source: Ball grid / partition data and Ballpark spatial system
// ============================================================================

struct SpatialPartitionComponent {
    uint32_t activeBoxCount = 0;    // Number of active partition boxes
};

// ============================================================================
// BUBBLE (Spatial Interest Region)
// Source: Destiny spatial partitioning / interest management bubbles
// ============================================================================

struct BubbleComponent {
    Vector3d center;                // Center of the bubble
    float radius = 0.0f;            // Radius of the bubble
    uint32_t gridLevel = 0;         // Hierarchical grid level
    uint32_t bubbleId = 0;          // Unique bubble identifier
    bool active = true;             // Whether the bubble is active
};

// ============================================================================
// WRECK / DEBRIS
// Source: Wreck and debris entities managed by Ballpark
// ============================================================================

struct WreckComponent {
    uint32_t wreckType = 0;         // Type of wreck
    double decayTimer = 0.0;        // Decay / despawn timer
    bool hasLoot = false;           // Whether the wreck has loot
};

} // namespace ecs
