#include "cross_rotations.h"

Color tempCrossColors[3][9][6];

void rotateCrossLayerColors(const int cubeIdx, const uint2 crossIdx, const CubeLayer cubeLayer, const Direction direction)
{
    memcpy(tempCrossColors, crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y], sizeof(tempCrossColors));

    const int alwaysMoveIdx = cubeLayer / 3;
    const int directionIdx = direction % 2;

    for (int x = 0; x < 4; x++)
    {
        const Move cornerMove = layerCornerMoves[cubeLayer][directionIdx][x];

        for (int y = 0; y < 2; y++)
        {
            tempCrossColors[cornerMove.targetLayer][cornerMove.targetCube][cornerMove.targetSides[y]] = crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerMove.originLayer][cornerMove.originCube][cornerMove.originSides[y]];
            tempCrossColors[cornerMove.targetLayer][cornerMove.targetCube][layerAlwaysMoves[alwaysMoveIdx][y]] = crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerMove.originLayer][cornerMove.originCube][layerAlwaysMoves[alwaysMoveIdx][y]];
        }
    }

    for (int x = 0; x < 4; x++)
    {
        const Move edgeMove = layerEdgeMoves[cubeLayer][directionIdx][x];
        tempCrossColors[edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[0]] = crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[0]];
        for (int y = 0; y < 2; y++)
        {
            tempCrossColors[edgeMove.targetLayer][edgeMove.targetCube][layerAlwaysMoves[alwaysMoveIdx][y]] = crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][edgeMove.originLayer][edgeMove.originCube][layerAlwaysMoves[alwaysMoveIdx][y]];
        }
    }

    memcpy(crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y], tempCrossColors, sizeof(tempCrossColors));
}

void rotateCrossFaceColors(const int cubeIdx, const uint2 crossIdx, const MoveIdx moveIdx)
{
    if (moveIdx == MoveIdx_None) return;

    const int alwaysMoveIdx = moveIdx / 2;

    for (int x = 0; x < 8; x++)
    {
        const Move cornerMove = faceCornerMoves[moveIdx][x];
        for (int y = 0; y < 2; y++)
        {
            tempCrossColors[cornerMove.targetLayer][cornerMove.targetCube][cornerMove.targetSides[y]] = crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerMove.originLayer][cornerMove.originCube][cornerMove.originSides[y]];
            tempCrossColors[cornerMove.targetLayer][cornerMove.targetCube][faceAlwaysMoves[alwaysMoveIdx][y]] = crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerMove.originLayer][cornerMove.originCube][faceAlwaysMoves[alwaysMoveIdx][y]];
        }
    }

    for (int x = 0; x < 12; x++)
    {
        const Move edgeMove = faceEdgeMoves[moveIdx][x];
        if (x < 8)
        {
            tempCrossColors[edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[0]] = crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[0]];
        }
        else
        {
            for (int y = 0; y < 2; y++)
            {
                tempCrossColors[edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[y]] = crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[y]];
            }
        }

        for (int i = 0; i < 2; i++)
        {
            tempCrossColors[edgeMove.targetLayer][edgeMove.targetCube][faceAlwaysMoves[alwaysMoveIdx][i]] = crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][edgeMove.originLayer][edgeMove.originCube][faceAlwaysMoves[alwaysMoveIdx][i]];
        }
    }

    for (int x = 0; x < 6; x++)
    {
        const Move centerMove = faceCenterMoves[moveIdx][x];
        tempCrossColors[centerMove.targetLayer][centerMove.targetCube][centerMove.targetSides[0]] = crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][centerMove.originLayer][centerMove.originCube][centerMove.originSides[0]];
    }

    memcpy(crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y], tempCrossColors, sizeof(tempCrossColors));
}

void turnCrossLayer(const int cubeIdx, const uint2 crossIdx, const CubeLayer cubeLayer, const Direction direction, const bool twice) {
    rotateCrossLayerColors(cubeIdx, crossIdx, cubeLayer, direction);
    if (twice)
    {
        rotateCrossLayerColors(cubeIdx, crossIdx, cubeLayer, direction);
    }
}

void turnCrossCube(const int cubeIdx, const uint2 crossIdx, const Direction direction, const bool twice) {
    MoveIdx moveIdx = cubeTurnMoveIdxs[direction];
    rotateCrossFaceColors(cubeIdx, crossIdx, moveIdx);
    if (twice)
    {
        rotateCrossFaceColors(cubeIdx, crossIdx, moveIdx);
    }
}