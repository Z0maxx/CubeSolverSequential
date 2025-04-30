#include "variables.h"
#include "cross_rotations.h"

int tempTestCubeColors[3][9][6];
int testCubeColors[3][9][6] =
{
	{
		{
			0,
			2,
			5,
			0,
			3,
			0
		},
		{
			0,
			0,
			3,
			0,
			1,
			0
		},
		{
			6,
			0,
			3,
			0,
			1,
			0
		},
		{
			0,
			1,
			0,
			0,
			6,
			0
		},
		{
			0,
			0,
			0,
			0,
			5,
			0
		},
		{
			5,
			0,
			0,
			0,
			6,
			0
		},
		{
			0,
			6,
			0,
			4,
			5,
			0
		},
		{
			0,
			0,
			0,
			4,
			6,
			0
		},
		{
			4,
			0,
			0,
			5,
			2,
			0
		}
	},
	{
		{
			0,
			3,
			6,
			0,
			0,
			0
		},
		{
			0,
			0,
			3,
			0,
			0,
			0
		},
		{
			3,
			0,
			5,
			0,
			0,
			0
		},
		{
			0,
			6,
			0,
			0,
			0,
			0
		},
		{
			0,
			0,
			0,
			0,
			0,
			0
		},
		{
			2,
			0,
			0,
			0,
			0,
			0
		},
		{
			0,
			1,
			0,
			4,
			0,
			0
		},
		{
			0,
			0,
			0,
			4,
			0,
			0
		},
		{
			2,
			0,
			0,
			1,
			0,
			0
		}
	},
	{
		{
			0,
			4,
			1,
			0,
			0,
			2
		},
		{
			0,
			0,
			2,
			0,
			0,
			5
		},
		{
			3,
			0,
			1,
			0,
			0,
			2
		},
		{
			0,
			4,
			0,
			0,
			0,
			2
		},
		{
			0,
			0,
			0,
			0,
			0,
			1
		},
		{
			3,
			0,
			0,
			0,
			0,
			2
		},
		{
			0,
			6,
			0,
			4,
			0,
			1
		},
		{
			0,
			0,
			0,
			5,
			0,
			4
		},
		{
			5,
			0,
			0,
			3,
			0,
			6
		}
	}
};

void rotateTestLayerColors(const CubeLayer cubeLayer, const Direction direction)
{
	memcpy(tempTestCubeColors, testCubeColors, sizeof(testCubeColors));

	const int alwaysMoveIdx = cubeLayer / 3;
	const int directionIdx = direction % 2;

	for (int x = 0; x < 4; x++)
	{
		const Move cornerMove = layerCornerMoves[cubeLayer][directionIdx][x];

		for (int y = 0; y < 2; y++)
		{
			tempTestCubeColors[cornerMove.targetLayer][cornerMove.targetCube][cornerMove.targetSides[y]] = testCubeColors[cornerMove.originLayer][cornerMove.originCube][cornerMove.originSides[y]];
			tempTestCubeColors[cornerMove.targetLayer][cornerMove.targetCube][layerAlwaysMoves[alwaysMoveIdx][y]] = testCubeColors[cornerMove.originLayer][cornerMove.originCube][layerAlwaysMoves[alwaysMoveIdx][y]];
		}
	}

	for (int x = 0; x < 4; x++)
	{
		const Move edgeMove = layerEdgeMoves[cubeLayer][directionIdx][x];
		tempTestCubeColors[edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[0]] = testCubeColors[edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[0]];
		for (int y = 0; y < 2; y++)
		{
			tempTestCubeColors[edgeMove.targetLayer][edgeMove.targetCube][layerAlwaysMoves[alwaysMoveIdx][y]] = testCubeColors[edgeMove.originLayer][edgeMove.originCube][layerAlwaysMoves[alwaysMoveIdx][y]];
		}
	}

	memcpy(testCubeColors, tempTestCubeColors, sizeof(tempTestCubeColors));
}

void rotateTestFaceColors(MoveIdx moveIdx)
{
	if (moveIdx == MoveIdx_None) return;

	const int alwaysMoveIdx = moveIdx / 2;

	for (int x = 0; x < 8; x++)
	{
		const Move cornerMove = faceCornerMoves[moveIdx][x];
		for (int y = 0; y < 2; y++)
		{
			tempTestCubeColors[cornerMove.targetLayer][cornerMove.targetCube][cornerMove.targetSides[y]] = testCubeColors[cornerMove.originLayer][cornerMove.originCube][cornerMove.originSides[y]];
			tempTestCubeColors[cornerMove.targetLayer][cornerMove.targetCube][faceAlwaysMoves[alwaysMoveIdx][y]] = testCubeColors[cornerMove.originLayer][cornerMove.originCube][faceAlwaysMoves[alwaysMoveIdx][y]];
		}
	}

	for (int x = 0; x < 12; x++)
	{
		const Move edgeMove = faceEdgeMoves[moveIdx][x];
		if (x < 8)
		{
			tempTestCubeColors[edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[0]] = testCubeColors[edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[0]];
		}
		else
		{
			for (int y = 0; y < 2; y++)
			{
				tempTestCubeColors[edgeMove.targetLayer][edgeMove.targetCube][edgeMove.targetSides[y]] = testCubeColors[edgeMove.originLayer][edgeMove.originCube][edgeMove.originSides[y]];
			}
		}

		for (int i = 0; i < 2; i++)
		{
			tempTestCubeColors[edgeMove.targetLayer][edgeMove.targetCube][faceAlwaysMoves[alwaysMoveIdx][i]] = testCubeColors[edgeMove.originLayer][edgeMove.originCube][faceAlwaysMoves[alwaysMoveIdx][i]];
		}
	}

	for (int x = 0; x < 6; x++)
	{
		const Move centerMove = faceCenterMoves[moveIdx][x];
		tempTestCubeColors[centerMove.targetLayer][centerMove.targetCube][centerMove.targetSides[0]] = testCubeColors[centerMove.originLayer][centerMove.originCube][centerMove.originSides[0]];
	}

    memcpy(testCubeColors, tempTestCubeColors, sizeof(tempTestCubeColors));
}

void turnTestLayer(CubeLayer cubeLayer, const Direction direction, const bool twice) {
	rotateTestLayerColors(cubeLayer, direction);
	if (twice)
	{
		rotateTestLayerColors(cubeLayer, direction);
	}
}

void turnTestCube(Direction direction, const bool twice) {
	MoveIdx moveIdx = cubeTurnMoveIdxs[direction];
	rotateTestFaceColors(moveIdx);
	if (twice)
	{
		rotateTestFaceColors(moveIdx);
	}
}