#pragma once

#include "variables.h"

extern void turnCrossCube(const int cubeIdx, const uint2 crossIdx, const Direction direction, const bool twice);
extern void turnCrossLayer(const int cubeIdx, const uint2 crossIdx, const CubeLayer cubeLayer, const Direction direction, const bool twice);
