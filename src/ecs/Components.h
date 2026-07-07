// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#pragma once

#include "Vector3d.h"
#include "Quaternion.h"
#include <cstdint>

namespace ecs {

// Core transform data (position, velocity, rotation, angular velocity)
struct TransformComponent {
    Vector3d position;
    Vector3d velocity;
    Quaternion rotation;
    Vector3d angularVelocity;

    // Previous frame state for integration / determinism
    Vector3d oldPosition;
    Vector3d oldVelocity;
    Quaternion oldRotation;
    Vector3d oldAngularVelocity;
};

// Basic physics properties extracted from Ball
struct PhysicsPropertiesComponent {
    double mass = 0.0;
    float radius = 0.0f;
    float maxVelocity = 0.0f;
    float agility = 0.0f;
    float maxAngularVelocity = 0.0f;
    float rollAgility = 0.0f;
};

// Mode / behavioral state (will be expanded in later phases)
enum class BallMode : uint8_t {
    Stop = 0,
    Goto,
    Follow,
    Orbit,
    Missile,
    // ... other modes from DSTBALLMODE
};

struct ModeComponent {
    BallMode mode = BallMode::Stop;
    // Mode-specific data will be added in Phase 3
};

} // namespace ecs
