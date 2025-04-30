#include "f2l_corner_solver.h"
#include <windows.h>

int F2LCornerRotations[6][4][6][4][6];

void solveF2LCornerPiece(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const int idx, const int solveOrderIdx)
{
	SolveRotation solveRotation = findSolveRotation(F2LCornerRotations[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y], solveOrderIdx);
	if (solveRotation.rotation != 99)
	{
		turnF2LCornerCube(cubeIdx, crossIdx, cornerIdx, solveRotation.direction, solveRotation.twice);
		F2LCornerRotationMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][idx] = solveRotation.notation;
		F2LCornerRotations[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y] = solveRotation.newRotation;
	}
	Color colors[3];
	for (int i = 0; i < 3; i++)
	{
		colors[i] = F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][F2LCornerReferences[i].layer][F2LCornerReferences[i].cube][F2LCornerReferences[i].side];
	}
	const uint2 corner = findCorner(F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y], colors, 8);
	const Color targetColor = F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][F2LCornerTargetReference.layer][F2LCornerTargetReference.cube][F2LCornerTargetReference.side];
	const Notation* sequence = findCornerSequence(F2LCornerSequences, corner, F2LCornerCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][corner.x][corner.y], targetColor);
	executeF2LCornerSequence(cubeIdx, crossIdx, cornerIdx, sequence, idx);
}

void solveF2LCorner1(int v, int w, int x, int y, int z)
{
	const int cubeIdx = v;

	const int crossIdxX = w;
	const int crossIdxY = x;
	const uint2 crossIdx = { crossIdxX, crossIdxY };

	const int cornerIdxX = y;
	const int cornerIdxY = z;
	const uint2 cornerIdx = { cornerIdxX, cornerIdxY };

	for (int i = 0; i < 4; i++)
	{
		solveF2LCornerPiece(cubeIdx, crossIdx, cornerIdx, i, solveOrders[cornerIdx.x][cornerIdx.y][i]);
	}
}

void copyF2LCornerColor(int v, int w, int x, int y, int z)
{
	memcpy(F2LCornerCubeColors[v][w][x][y][z], crossCubeColors[v][w][x], sizeof(crossCubeColors[v][w][x]));
}

void solveF2LCorner()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				for (int l = 0; l < 4; l++)
				{
					for (int m = 0; m < 6; m++)
					{
						copyF2LCornerColor(i, j, k, l, m);
						solveF2LCorner1(i, j, k, l, m);
					}
				}
			}
		}
	}
}