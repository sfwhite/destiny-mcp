// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#include "SimulationCore.h"
#include <iostream>

namespace ecs {

SimulationCore::SimulationCore() = default;
SimulationCore::~SimulationCore() = default;

void SimulationCore::Initialize() {
    if (mInitialized) return;

    // TODO(Phase 1): Initialize entity storage, archetype chunks, spatial system, etc.
    std::cout << "[SimulationCore] Initialized new high-performance core.\n";

    mInitialized = true;
}

uint64_t SimulationCore::CreateEntity() {
    static uint64_t nextId = 1;
    return nextId++;
}

void SimulationCore::DestroyEntity(uint64_t entity) {
    // TODO
}

void SimulationCore::AddTransform(uint64_t entity, const TransformComponent& transform) {}
void SimulationCore::AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& props) {}
void SimulationCore::AddMode(uint64_t entity, const ModeComponent& mode) {}

void SimulationCore::Evolve(double dt) {
    if (!mInitialized) return;
    // TODO(Phase 1+): Run all registered Systems
}

} // namespace ecs
