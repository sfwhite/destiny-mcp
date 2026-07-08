// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation (modified)

#pragma once

#include <cstdint>
#include <memory>

namespace ecs {

class World;
struct TransformComponent;
struct KinematicComponent;
struct CollidableComponent;
struct BallModeComponent;

class SimulationCore {
public:
    SimulationCore();
    ~SimulationCore();

    void Initialize();
    bool IsInitialized() const;

    World& GetWorld();
    const World& GetWorld() const;

    uint64_t CreateEntity();
    void DestroyEntity(uint64_t entity);

    void AddTransform(uint64_t entity, const TransformComponent& transform);
    void AddKinematic(uint64_t entity, const KinematicComponent& component);
    void AddCollidable(uint64_t entity, const CollidableComponent& component);
    void AddBallMode(uint64_t entity, const BallModeComponent& component);

    void Evolve(double dt);

private:
    bool mInitialized = false;
    std::unique_ptr<World> mWorld;
};

} // namespace ecs
