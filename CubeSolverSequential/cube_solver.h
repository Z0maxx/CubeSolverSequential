#pragma once

#include <string.h>

#include "cube_rotations.h"
#include "cube_printer.h"
#include "ms_clock.h"
#include "cross_solver.h"
#include "f2l_corner_solver.h"
#include "f2l_edge_solver.h"
#include "oll_cross_solver.h"
#include "oll_edge_solver.h"
#include "pll_cycle_solver.h"
#include "pll_orient_solver.h"

extern void solve(const int cube[3][9][6]);