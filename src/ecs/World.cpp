// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#include "World.h"

namespace ecs {

World::World() {
    mEntityManager = std::make_unique<EntityManager>();
}

World::~World() = default;

void World::Initialize() {
    // TODO(Phase 1): Initialize component storage, archetype registry, etc.
}

} // namespace ecs
