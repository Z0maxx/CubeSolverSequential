#include "f2l_edge_rotations.h"

Color tempF2LEdgeColors[3][9][6];

void rotateF2LEdgeLayerColors(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, const CubeLayer cubeLayer, const Direction direction)
{
    memcpy(tempF2LEdgeColors, F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y], sizeof(tempF2LEdgeColors));

    const int alwaysMoveIdx = cubeLayer / 3;
    const int directionIdx = direction % 2;

    for (int x = 0; x < 4; x++)
    {
        const Move cornerMove = layerCornerMoves[cubeLayer][directionIdx][x];

        for (int y = 0; y < 2; y++)
        {
            tempF2LEdgeColors[cornerMove.targetLayer][cornerMove.targetCube][cornerMove.targetSides[y]] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][cornerMove.originLayer][cornerMove.originCube][cornerMove.originSides[y]];
            tempF2LEdgeColors[cornerMove.targetLayer][cornerMove.targetCube][layerAlwaysMoves[alwaysMoveIdx][y]] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][cornerMove.originLayer][cornerMove.originCube][layerAlwaysMoves[alwaysMoveIdx][y]];
        }
    }

    for (int x = 0; x < 4; x++)
    {
        const Move edgeMove = layerEdgeMoves[cubeLayer][directionIdx][x];
        tempF2LEdgeColors[edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[0]] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[0]];
        for (int y = 0; y < 2; y++)
        {
            tempF2LEdgeColors[edgeMove.targetLayer][edgeMove.targetCube][layerAlwaysMoves[alwaysMoveIdx][y]] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][edgeMove.originLayer][edgeMove.originCube][layerAlwaysMoves[alwaysMoveIdx][y]];
        }
    }

    memcpy(F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y], tempF2LEdgeColors, sizeof(tempF2LEdgeColors));
}

void rotateF2LEdgeFaceColors(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, const MoveIdx moveIdx)
{
    if (moveIdx == MoveIdx_None) return;

    const int alwaysMoveIdx = moveIdx / 2;

    for (int x = 0; x < 8; x++)
    {
        const Move cornerMove = faceCornerMoves[moveIdx][x];
        for (int y = 0; y < 2; y++)
        {
            tempF2LEdgeColors[cornerMove.targetLayer][cornerMove.targetCube][cornerMove.targetSides[y]] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][cornerMove.originLayer][cornerMove.originCube][cornerMove.originSides[y]];
            tempF2LEdgeColors[cornerMove.targetLayer][cornerMove.targetCube][faceAlwaysMoves[alwaysMoveIdx][y]] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][cornerMove.originLayer][cornerMove.originCube][faceAlwaysMoves[alwaysMoveIdx][y]];
        }
    }

    for (int x = 0; x < 12; x++)
    {
        const Move edgeMove = faceEdgeMoves[moveIdx][x];
        if (x < 8)
        {
            tempF2LEdgeColors[edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[0]] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[0]];
        }
        else
        {
            for (int y = 0; y < 2; y++)
            {
                tempF2LEdgeColors[edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[y]] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[y]];
            }
        }

        for (int i = 0; i < 2; i++)
        {
            tempF2LEdgeColors[edgeMove.targetLayer][edgeMove.targetCube][faceAlwaysMoves[alwaysMoveIdx][i]] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][edgeMove.originLayer][edgeMove.originCube][faceAlwaysMoves[alwaysMoveIdx][i]];
        }
    }

    for (int x = 0; x < 6; x++)
    {
        const Move centerMove = faceCenterMoves[moveIdx][x];
        tempF2LEdgeColors[centerMove.targetLayer][centerMove.targetCube][centerMove.targetSides[0]] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][centerMove.originLayer][centerMove.originCube][centerMove.originSides[0]];
    }

    memcpy(F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y], tempF2LEdgeColors, sizeof(tempF2LEdgeColors));
}

void turnF2LEdgeLayer(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, const CubeLayer cubeLayer, const Direction direction, const bool twice) {
    rotateF2LEdgeLayerColors(cubeIdx, crossIdx, cornerIdx, edgeIdx, cubeLayer, direction);
    if (twice)
    {
        rotateF2LEdgeLayerColors(cubeIdx, crossIdx, cornerIdx, edgeIdx, cubeLayer, direction);
    }
}

void turnF2LEdgeCube(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, const Direction direction, const bool twice) {
    MoveIdx moveWithLayerIdx = cubeTurnMoveIdxs[direction];
    rotateF2LEdgeFaceColors(cubeIdx, crossIdx, cornerIdx, edgeIdx, moveWithLayerIdx);
    if (twice)
    {
        rotateF2LEdgeFaceColors(cubeIdx, crossIdx, cornerIdx, edgeIdx, moveWithLayerIdx);
    }
}