// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation

#pragma once

#include "Vector3d.h"
#include "Quaternion.h"
#include <cstdint>

namespace ecs {

// ============================================================================
// CORE TRANSFORM / MOTION (derived from Ball::mNewPos, mNewVel, mNewRot, etc. in Ball.h)
// ============================================================================

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
// KINEMATIC (Movement Physics) - derived from Ball physics parameters (mass, agility, maxVelocity, etc.)
// ============================================================================

struct KinematicComponent {
    double mass = 0.0;
    float agility = 0.0f;
    float maxVelocity = 0.0f;
    float maxAngularVelocity = 0.0f;
    float rollAgility = 0.0f;
};

// ============================================================================
// COLLIDABLE - derived from Ball collision participation (radius + Mini* shapes)
// ============================================================================

struct CollidableComponent {
    float radius = 0.0f;
};

// ============================================================================
// COLLISION SHAPE PRIMITIVES (derived from Ball::mMiniBalls, mMiniBoxes, mMiniCapsules)
// ============================================================================

struct SphereComponent {
    Vector3d localPosition;
    float radius = 0.0f;
};

struct BoxComponent {
    Vector3d localPosition;
    Vector3d halfExtents;
    Quaternion orientation;
};

struct CapsuleComponent {
    Vector3d localPosition;
    Vector3d axis;
    float radius = 0.0f;
    float halfLength = 0.0f;
};

// ============================================================================
// BUBBLE (derived from Destiny spatial partitioning / interest management bubbles)
// ============================================================================

struct BubbleComponent {
    Vector3d center;
    float radius = 0.0f;
    uint32_t gridLevel = 0;
    uint32_t bubbleId = 0;
    bool active = true;
};

// ============================================================================
// WRECK / DEBRIS (derived from wreck entities managed by Ballpark)
// ============================================================================

struct WreckComponent {
    uint32_t wreckType = 0;
    double decayTimer = 0.0;
    bool hasLoot = false;
};

// ============================================================================
// BEHAVIORAL MODE (derived from Ball::mMode and DSTBALLMODE constants in Ball.h)
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
    BallMode mode = BallMode::Stop;
    Vector3d targetPosition;
    uint64_t targetEntity = 0;
    float orbitRadius = 0.0f;
    float orbitSpeed = 0.0f;
};

// ============================================================================
// PROXIMITY SENSOR (derived from Ball::mSensor / ProximitySensor in Ball.h)
// ============================================================================

struct ProximityComponent {
    float range = 0.0f;
    double period = 2.0;
    double elapsed = 0.0;
    bool active = false;
    bool onlyInteractives = false;
};

// ============================================================================
// OWNERSHIP (derived from Ball ownership/alliance data)
// ============================================================================

struct OwnershipComponent {
    uint64_t ownerId = 0;
    uint32_t allianceId = 0;
    uint32_t corporationId = 0;
};

// ============================================================================
// FORMATION (derived from Ball formation data)
// ============================================================================

struct FormationComponent {
    uint64_t formationLeader = 0;
    uint32_t formationSlot = 0;
    bool inFormation = false;
};

// ============================================================================
// CLOAKING (derived from Ball cloaking state)
// ============================================================================

struct CloakComponent {
    bool isCloaked = false;
    float cloakStrength = 0.0f;
    double cloakTimer = 0.0;
};

// ============================================================================
// HARMONICS / EFFECTS (derived from Ball harmonics and effect state)
// ============================================================================

struct HarmonicsComponent {
    uint32_t harmonicState = 0;
    double harmonicTimer = 0.0;
};

// ============================================================================
// SPATIAL PARTITIONING (derived from Ball grid/partition data in Ball.h)
// ============================================================================

struct SpatialPartitionComponent {
    uint32_t activeBoxCount = 0;
};

// ============================================================================
// GENERAL EFFECT / TIMED EVENT
// ============================================================================

struct EffectComponent {
    uint32_t effectType = 0;
    double duration = 0.0;
    double elapsed = 0.0;
};

// ============================================================================
// SIGNATURE (derived from ship/sensor signature data)
// ============================================================================

struct SignatureComponent {
    float signatureRadius = 0.0f;
    uint32_t signatureType = 0;
};

// ============================================================================
// DAMAGE STATE
// ============================================================================

struct DamageComponent {
    double hull = 0.0;
    double armor = 0.0;
    double shield = 0.0;
};

// ============================================================================
// SHIELD
// ============================================================================

struct ShieldComponent {
    double hitpoints = 0.0;
    double rechargeRate = 0.0;
};

// ============================================================================
// ARMOR
// ============================================================================

struct ArmorComponent {
    double hitpoints = 0.0;
    double repairRate = 0.0;
};

// ============================================================================
// CONTAINER / CARGO
// ============================================================================

struct ContainerComponent {
    uint32_t capacity = 0;
    uint32_t used = 0;
};

// ============================================================================
// INTERPOLATION (for ClientBall / client-side prediction)
// ============================================================================

struct InterpolationComponent {
    double interpolationFactor = 0.0;
    bool isInterpolating = false;
};

// ============================================================================
// SENSOR
// ============================================================================

struct SensorComponent {
    float strength = 0.0f;
    float range = 0.0f;
    float resolution = 0.0f;
};

// ============================================================================
// GENERAL STATE / FLAGS
// ============================================================================

struct StateComponent {
    uint32_t flags = 0;
    double timer = 0.0;
};

} // namespace ecs
