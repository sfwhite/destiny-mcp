// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation

#include "ComponentRegistry.h"

namespace ecs {

std::unordered_map<std::type_index, uint32_t> ComponentRegistry::sTypeToId;
uint32_t ComponentRegistry::sNextId = 1; // Start from 1 (0 can mean "not registered")

} // namespace ecs
