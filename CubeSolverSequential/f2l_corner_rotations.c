#include "f2l_corner_rotations.h"

Color tempF2LCornerColors[3][9][6];

void rotateF2LCornerLayerColors(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const CubeLayer cubeLayer, const Direction direction)
{
    memcpy(tempF2LCornerColors, F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y], sizeof(tempF2LCornerColors));

    const int alwaysMoveIdx = cubeLayer / 3;
    const int directionIdx = direction % 2;

    for (int x = 0; x < 4; x++)
    {
        const Move cornerMove = layerCornerMoves[cubeLayer][directionIdx][x];

        for (int y = 0; y < 2; y++)
        {
            tempF2LCornerColors[cornerMove.targetLayer][cornerMove.targetCube][cornerMove.targetSides[y]] = F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][cornerMove.originLayer][cornerMove.originCube][cornerMove.originSides[y]];
            tempF2LCornerColors[cornerMove.targetLayer][cornerMove.targetCube][layerAlwaysMoves[alwaysMoveIdx][y]] = F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][cornerMove.originLayer][cornerMove.originCube][layerAlwaysMoves[alwaysMoveIdx][y]];
        }
    }

    for (int x = 0; x < 4; x++)
    {
        const Move edgeMove = layerEdgeMoves[cubeLayer][directionIdx][x];
        tempF2LCornerColors[edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[0]] = F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[0]];
        for (int y = 0; y < 2; y++)
        {
            tempF2LCornerColors[edgeMove.targetLayer][edgeMove.targetCube][layerAlwaysMoves[alwaysMoveIdx][y]] = F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeMove.originLayer][edgeMove.originCube][layerAlwaysMoves[alwaysMoveIdx][y]];
        }
    }

    memcpy(F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y], tempF2LCornerColors, sizeof(tempF2LCornerColors));
}

void rotateF2LCornerFaceColors(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const MoveIdx moveIdx)
{
    if (moveIdx == MoveIdx_None) return;

    const int alwaysMoveIdx = moveIdx / 2;

    for (int x = 0; x < 8; x++)
    {
        const Move cornerMove = faceCornerMoves[moveIdx][x];
        for (int y = 0; y < 2; y++)
        {
            tempF2LCornerColors[cornerMove.targetLayer][cornerMove.targetCube][cornerMove.targetSides[y]] = F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][cornerMove.originLayer][cornerMove.originCube][cornerMove.originSides[y]];
            tempF2LCornerColors[cornerMove.targetLayer][cornerMove.targetCube][faceAlwaysMoves[alwaysMoveIdx][y]] = F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][cornerMove.originLayer][cornerMove.originCube][faceAlwaysMoves[alwaysMoveIdx][y]];
        }
    }

    for (int x = 0; x < 12; x++)
    {
        const Move edgeMove = faceEdgeMoves[moveIdx][x];
        if (x < 8)
        {
            tempF2LCornerColors[edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[0]] = F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[0]];
        }
        else
        {
            for (int y = 0; y < 2; y++)
            {
                tempF2LCornerColors[edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[y]] = F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[y]];
            }
        }

        for (int i = 0; i < 2; i++)
        {
            tempF2LCornerColors[edgeMove.targetLayer][edgeMove.targetCube][faceAlwaysMoves[alwaysMoveIdx][i]] = F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeMove.originLayer][edgeMove.originCube][faceAlwaysMoves[alwaysMoveIdx][i]];
        }
    }

    for (int x = 0; x < 6; x++)
    {
        const Move centerMove = faceCenterMoves[moveIdx][x];
        tempF2LCornerColors[centerMove.targetLayer][centerMove.targetCube][centerMove.targetSides[0]] = F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][centerMove.originLayer][centerMove.originCube][centerMove.originSides[0]];
    }

    memcpy(F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y], tempF2LCornerColors, sizeof(tempF2LCornerColors));
}

void turnF2LCornerLayer(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const CubeLayer cubeLayer, const Direction direction, const bool twice) {
    rotateF2LCornerLayerColors(cubeIdx, crossIdx, cornerIdx, cubeLayer, direction);
    if (twice)
    {
        rotateF2LCornerLayerColors(cubeIdx, crossIdx, cornerIdx, cubeLayer, direction);
    }
}

void turnF2LCornerCube(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const Direction direction, const bool twice) {
    MoveIdx moveIdx = cubeTurnMoveIdxs[direction];
    rotateF2LCornerFaceColors(cubeIdx, crossIdx, cornerIdx, moveIdx);
    if (twice)
    {
        rotateF2LCornerFaceColors(cubeIdx, crossIdx, cornerIdx, moveIdx);
    }
}