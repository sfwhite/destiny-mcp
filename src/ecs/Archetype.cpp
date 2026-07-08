// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation

#include "Archetype.h"

namespace ecs {

Archetype::Archetype() : mSignature(0) {}

Archetype::Archetype(uint32_t signature) : mSignature(signature) {}

bool Archetype::HasComponent(uint32_t componentBit) const {
    return (mSignature & componentBit) != 0;
}

} // namespace ecs
