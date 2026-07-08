// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#include "SimulationCore.h"

namespace ecs {

SimulationCore::SimulationCore() = default;
SimulationCore::~SimulationCore() = default;

uint64_t SimulationCore::CreateEntity() {
    // TODO(Phase 1): Proper entity ID allocation with generation
    static uint64_t nextId = 1;
    return nextId++;
}

void SimulationCore::DestroyEntity(uint64_t entity) {
    // TODO
}

void SimulationCore::AddTransform(uint64_t entity, const TransformComponent& transform) {
    // TODO(Phase 1)
}

void SimulationCore::AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& props) {
    // TODO(Phase 1)
}

void SimulationCore::AddMode(uint64_t entity, const ModeComponent& mode) {
    // TODO(Phase 1)
}

void SimulationCore::Evolve(double dt) {
    // TODO(Phase 1+): Run systems
}

} // namespace ecs
