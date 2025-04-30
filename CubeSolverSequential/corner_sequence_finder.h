#pragma once

#include "enums.h"
#include "structs.h"

extern const Notation* findCornerSequence(CornerSolveSequence sequences[24], const uint2 corner, const Color colors[6], const Color targetColor);