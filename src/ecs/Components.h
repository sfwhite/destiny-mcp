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
    double mass = 0.0;               // From Ball::mass
    float agility = 0.0f;            // From Ball::agility
    float maxVelocity = 0.0f;        // From Ball::maxVelocity
    float maxAngularVelocity = 0.0f; // From Ball::maxAngularVelocity
    float rollAgility = 0.0f;        // From Ball::rollAgility
};

// ============================================================================
// COLLIDABLE
// ============================================================================

struct CollidableComponent {
    float radius = 0.0f;             // From Ball::radius
};

// ============================================================================
// COLLISION SHAPE PRIMITIVES (Mini* shapes)
// ============================================================================

struct SphereComponent {
    Vector3d localPosition;          // From MiniBall::localPosition
    float radius = 0.0f;             // From MiniBall::radius
};

struct BoxComponent {
    Vector3d localPosition;          // From MiniBox::localPosition
    Vector3d halfExtents;            // From MiniBox::halfExtents
    Quaternion orientation;          // From MiniBox::orientation
};

struct CapsuleComponent {
    Vector3d localPosition;          // From MiniCapsule::localPosition
    Vector3d axis;                   // From MiniCapsule::axis
    float radius = 0.0f;             // From MiniCapsule::radius
    float halfLength = 0.0f;         // From MiniCapsule::halfLength
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

    Vector3d targetPosition;         // From Ball::targetPosition
    uint64_t targetEntity = 0;       // From Ball::targetEntity
    float orbitRadius = 0.0f;        // From Ball::orbitRadius
    float orbitSpeed = 0.0f;         // From Ball::orbitSpeed
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
    uint64_t ownerId = 0;            // From Ball::ownerId
    uint32_t allianceId = 0;         // From Ball::allianceId
    uint32_t corporationId = 0;      // From Ball::corporationId
};

// ============================================================================
// FORMATION
// ============================================================================

struct FormationComponent {
    uint64_t formationLeader = 0;    // From Ball::formationLeader
    uint32_t formationSlot = 0;      // From Ball::formationSlot
    bool inFormation = false;        // From Ball::inFormation
};

// ============================================================================
// CLOAKING
// ============================================================================

struct CloakComponent {
    bool isCloaked = false;          // From Ball::isCloaked
    float cloakStrength = 0.0f;      // From Ball::cloakStrength
    double cloakTimer = 0.0;         // From Ball::cloakTimer
};

// ============================================================================
// HARMONICS / SPECIAL EFFECTS
// ============================================================================

struct HarmonicsComponent {
    uint32_t harmonicState = 0;      // From Ball::harmonicState
    double harmonicTimer = 0.0;      // From Ball::harmonicTimer
};

// ============================================================================
// SPATIAL PARTITIONING
// ============================================================================

struct SpatialPartitionComponent {
    uint32_t activeBoxCount = 0;     // From Ball::activeBoxCount
};

// ============================================================================
// BUBBLE
// ============================================================================

struct BubbleComponent {
    Vector3d center;                 // From Bubble::center
    float radius = 0.0f;             // From Bubble::radius
    uint32_t gridLevel = 0;          // From Bubble::gridLevel
    uint32_t bubbleId = 0;           // From Bubble::bubbleId
    bool active = true;              // From Bubble::active
};

// ============================================================================
// WRECK / DEBRIS
// ============================================================================

struct WreckComponent {
    uint32_t wreckType = 0;          // From Wreck::wreckType
    double decayTimer = 0.0;         // From Wreck::decayTimer
    bool hasLoot = false;            // From Wreck::hasLoot
};

} // namespace ecs
