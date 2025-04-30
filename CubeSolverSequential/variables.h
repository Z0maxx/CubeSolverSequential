#pragma once

#include <string.h>

#include "enums.h"
#include "structs.h"

extern const Move layerCornerMoves[9][2][4];
extern const Move layerEdgeMoves[9][2][4];

extern const Move faceCornerMoves[6][8];
extern const Move faceEdgeMoves[6][12];
extern const Move faceCenterMoves[6][6];

extern const Side layerAlwaysMoves[3][2];
extern const CubeAlwaysMove layerCubeAlwaysMoves[9];
extern const Side faceAlwaysMoves[3][2];

extern const MoveIdx cubeTurnMoveIdxs[7];

extern const SolvePiece solvePieces[4];
extern const int solveOrders[4][6][4];

extern Color cubeColors[6][3][9][6];
extern Color crossCubeColors[6][4][6][3][9][6];
extern Color F2LCornerCubeColors[6][4][6][4][6][3][9][6];
extern Color F2LEdgeCubeColors[6][4][6][4][6][4][6][3][9][6];

extern Notation cubeRotationMoves[6];
extern Notation crossRotationMoves[6][4][6][4];
extern Notation F2LCornerRotationMoves[6][4][6][4][6][4];
extern Notation F2LEdgeRotationMoves[6][4][6][4][6][4][6][4];

extern Notation crossLayerMoves[6][4][6][4][4];
extern Notation F2LCornerLayerMoves[6][4][6][4][6][4][8];
extern Notation F2LEdgeLayerMoves[6][4][6][4][6][4][6][4][16];
extern Notation OLLCrossLayerMoves[6][4][6][4][6][4][6][3][6];
extern Notation OLLEdgeLayerMoves[6][4][6][4][6][4][6][16];
extern Notation PLLCycleLayerMoves[6][4][6][4][6][4][6][3][8];
extern Notation PLLOrientLayerMoves[6][4][6][4][6][4][6][4][4][5];

extern Notation moves[82944][263];