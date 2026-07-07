// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#pragma once

// Feature flag to enable the new high-performance internal core.
// When enabled, Ballpark will route to the new SimulationCore instead of the legacy implementation.
// Default: disabled (legacy path) for safety during development.
#ifndef DESTINY_USE_NEW_CORE
#define DESTINY_USE_NEW_CORE 0
#endif
