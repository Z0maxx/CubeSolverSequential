#include "cube_rotations.h"

Color tempCubeColors[6][3][9][6];

void rotateLayerColors(const int cubeIdx, const CubeLayer cubeLayer, const Direction direction)
{
    memcpy(tempCubeColors[cubeIdx], cubeColors[cubeIdx], sizeof(cubeColors[cubeIdx]));

    const int alwaysMoveIdx = cubeLayer / 3;
    const int directionIdx = direction % 2;

    for (int x = 0; x < 4; x++)
    {
        const Move cornerMove = layerCornerMoves[cubeLayer][directionIdx][x];
        
        for (int y = 0; y < 2; y++)
        {
            tempCubeColors[cubeIdx][cornerMove.targetLayer][cornerMove.targetCube][cornerMove.targetSides[y]] = cubeColors[cubeIdx][cornerMove.originLayer][cornerMove.originCube][cornerMove.originSides[y]];
            tempCubeColors[cubeIdx][cornerMove.targetLayer][cornerMove.targetCube][layerAlwaysMoves[alwaysMoveIdx][y]] = cubeColors[cubeIdx][cornerMove.originLayer][cornerMove.originCube][layerAlwaysMoves[alwaysMoveIdx][y]];
        }
    }

    for (int x = 0; x < 4; x++)
    {
        const Move edgeMove = layerEdgeMoves[cubeLayer][directionIdx][x];
        tempCubeColors[cubeIdx][edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[0]] = cubeColors[cubeIdx][edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[0]];
        for (int y = 0; y < 2; y++)
        {
            tempCubeColors[cubeIdx][edgeMove.targetLayer][edgeMove.targetCube][layerAlwaysMoves[alwaysMoveIdx][y]] = cubeColors[cubeIdx][edgeMove.originLayer][edgeMove.originCube][layerAlwaysMoves[alwaysMoveIdx][y]];
        }
    }

    memcpy(cubeColors[cubeIdx], tempCubeColors[cubeIdx], sizeof(tempCubeColors[cubeIdx]));
}

void rotateFaceColors(const int cubeIdx, const MoveIdx moveIdx)
{
    if (moveIdx == MoveIdx_None) return;

    const int alwaysMoveIdx = moveIdx / 2;

    for (int x = 0; x < 8; x++)
    {
        const Move cornerMove = faceCornerMoves[moveIdx][x];
        for (int y = 0; y < 2; y++)
        {
            tempCubeColors[cubeIdx][cornerMove.targetLayer][cornerMove.targetCube][cornerMove.targetSides[y]] = cubeColors[cubeIdx][cornerMove.originLayer][cornerMove.originCube][cornerMove.originSides[y]];
            tempCubeColors[cubeIdx][cornerMove.targetLayer][cornerMove.targetCube][faceAlwaysMoves[alwaysMoveIdx][y]] = cubeColors[cubeIdx][cornerMove.originLayer][cornerMove.originCube][faceAlwaysMoves[alwaysMoveIdx][y]];
        }
    }

    for (int x = 0; x < 12; x++)
    {
        const Move edgeMove = faceEdgeMoves[moveIdx][x];
        if (x < 8)
        {
            tempCubeColors[cubeIdx][edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[0]] = cubeColors[cubeIdx][edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[0]];
        }
        else
        {
            for (int y = 0; y < 2; y++)
            {
                tempCubeColors[cubeIdx][edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[y]] = cubeColors[cubeIdx][edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[y]];
            }
        }

        for (int i = 0; i < 2; i++)
        {
            tempCubeColors[cubeIdx][edgeMove.targetLayer][edgeMove.targetCube][faceAlwaysMoves[alwaysMoveIdx][i]] = cubeColors[cubeIdx][edgeMove.originLayer][edgeMove.originCube][faceAlwaysMoves[alwaysMoveIdx][i]];
        }
    }

    for (int x = 0; x < 6; x++)
    {
        const Move centerMove = faceCenterMoves[moveIdx][x];
        tempCubeColors[cubeIdx][centerMove.targetLayer][centerMove.targetCube][centerMove.targetSides[0]] = cubeColors[cubeIdx][centerMove.originLayer][centerMove.originCube][centerMove.originSides[0]];
    }

    memcpy(cubeColors[cubeIdx], tempCubeColors[cubeIdx], sizeof(tempCubeColors[cubeIdx]));
}

void turnLayer(const int cubeIdx, const CubeLayer cubeLayer, const Direction direction, const bool twice) {
    rotateLayerColors(cubeIdx, cubeLayer, direction);
    if (twice)
    {
        rotateLayerColors(cubeIdx, cubeLayer, direction);
    }
}

void turnCube(const int cubeIdx, const Direction direction, bool twice) {
    MoveIdx moveIdx = cubeTurnMoveIdxs[direction];
    rotateFaceColors(cubeIdx, moveIdx);
    if (twice)
    {
        rotateFaceColors(cubeIdx, moveIdx);
    }
}