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
// ============================================================================

struct TransformComponent {
    Vector3d position;             // From Ball::mNewPos
    Vector3d velocity;             // From Ball::mNewVel
    Quaternion rotation;           // From Ball::mNewRot
    Vector3d angularVelocity;      // From Ball::mNewAngVel

    Vector3d oldPosition;          // From Ball::mOldPos
    Vector3d oldVelocity;          // From Ball::mOldVel
    Quaternion oldRotation;        // From Ball::mOldRot
    Vector3d oldAngularVelocity;   // From Ball::mOldAngVel
};

// ============================================================================
// KINEMATIC (Movement Physics Parameters)
// ============================================================================

struct KinematicComponent {
    double mass = 0.0;               // From Ball physics parameters
    float agility = 0.0f;            // From Ball physics parameters
    float maxVelocity = 0.0f;        // From Ball physics parameters
    float maxAngularVelocity = 0.0f; // From Ball physics parameters
    float rollAgility = 0.0f;        // From Ball physics parameters
};

// ============================================================================
// COLLIDABLE
// ============================================================================

struct CollidableComponent {
    float radius = 0.0f;             // From Ball radius + Mini* shapes
};

// ============================================================================
// COLLISION SHAPE PRIMITIVES (Mini* shapes)
// ============================================================================

struct SphereComponent {
    Vector3d localPosition;          // From MiniBall local position
    float radius = 0.0f;             // From MiniBall radius
};

struct BoxComponent {
    Vector3d localPosition;          // From MiniBox local position
    Vector3d halfExtents;            // From MiniBox halfExtents
    Quaternion orientation;          // From MiniBox orientation
};

struct CapsuleComponent {
    Vector3d localPosition;          // From MiniCapsule local position
    Vector3d axis;                   // From MiniCapsule axis
    float radius = 0.0f;             // From MiniCapsule radius
    float halfLength = 0.0f;         // From MiniCapsule halfLength
};

// ============================================================================
// BEHAVIORAL MODE
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
    BallMode mode = BallMode::Stop;  // From Ball::mMode

    Vector3d targetPosition;         // From mode target position data
    uint64_t targetEntity = 0;       // From mode target entity data
    float orbitRadius = 0.0f;        // From Orbit mode data
    float orbitSpeed = 0.0f;         // From Orbit mode data
};

// ============================================================================
// PROXIMITY SENSOR
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
// ============================================================================

struct OwnershipComponent {
    uint64_t ownerId = 0;            // From Ball ownership data
    uint32_t allianceId = 0;         // From Ball alliance data
    uint32_t corporationId = 0;      // From Ball corporation data
};

// ============================================================================
// FORMATION
// ============================================================================

struct FormationComponent {
    uint64_t formationLeader = 0;    // From Ball formation leader
    uint32_t formationSlot = 0;      // From Ball formation slot
    bool inFormation = false;        // From Ball formation state
};

// ============================================================================
// CLOAKING
// ============================================================================

struct CloakComponent {
    bool isCloaked = false;          // From Ball cloaking state
    float cloakStrength = 0.0f;      // From Ball cloak strength
    double cloakTimer = 0.0;         // From Ball cloak timer
};

// ============================================================================
// HARMONICS / SPECIAL EFFECTS
// ============================================================================

struct HarmonicsComponent {
    uint32_t harmonicState = 0;      // From Ball harmonics state
    double harmonicTimer = 0.0;      // From Ball harmonics timer
};

// ============================================================================
// SPATIAL PARTITIONING
// ============================================================================

struct SpatialPartitionComponent {
    uint32_t activeBoxCount = 0;     // From Ball partition data
};

// ============================================================================
// BUBBLE
// ============================================================================

struct BubbleComponent {
    Vector3d center;                 // From Bubble center
    float radius = 0.0f;             // From Bubble radius
    uint32_t gridLevel = 0;          // From Bubble grid level
    uint32_t bubbleId = 0;           // From Bubble ID
    bool active = true;              // From Bubble active state
};

// ============================================================================
// WRECK / DEBRIS
// ============================================================================

struct WreckComponent {
    uint32_t wreckType = 0;          // From Wreck type
    double decayTimer = 0.0;         // From Wreck decay timer
    bool hasLoot = false;            // From Wreck loot flag
};

} // namespace ecs
