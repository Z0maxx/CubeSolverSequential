#include "cross_solver.h"

int crossRotations[6][4][6];

void solveCrossPiece(const int cubeIdx, const uint2 crossIdx, const int idx, const int solveOrderIdx)
{
	SolveRotation solveRotation = findSolveRotation(crossRotations[cubeIdx][crossIdx.x][crossIdx.y], solveOrderIdx);
	if (solveRotation.rotation != 99)
	{
		turnCrossCube(cubeIdx, crossIdx, solveRotation.direction, solveRotation.twice);
		crossRotationMoves[cubeIdx][crossIdx.x][crossIdx.y][idx] = solveRotation.notation;
		crossRotations[cubeIdx][crossIdx.x][crossIdx.y] = solveRotation.newRotation;
	}
	Color colors[2];
	for (int i = 0; i < 2; i++)
	{
		colors[i] = crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][crossReferences[i].layer][crossReferences[i].cube][crossReferences[i].side];
	}
	const uint2 edge = findEdge(crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y], colors, 12);
	const Color targetColor = crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][crossTargetReference.layer][crossTargetReference.cube][crossTargetReference.side];
	const Notation* sequence = findCrossSequence(edge, crossCubeColors[cubeIdx][crossIdx.x][crossIdx.y][edge.x][edge.y], targetColor);
	executeCrossSequence(cubeIdx, crossIdx, sequence, idx);
}

void solveCross1(int x, int y, int z)
{
	const int cubeIdx = x;
	const int crossIdxX = y;
	const int crossIdxY = z;
	const uint2 crossIdx = { crossIdxX, crossIdxY };

	for (int i = 0; i < 4; i++)
	{
		solveCrossPiece(cubeIdx, crossIdx, i, solveOrders[crossIdx.x][crossIdx.y][i]);
	}
}

void copyCrossColor(int x, int y, int z)
{
	memcpy(crossCubeColors[x][y][z], cubeColors[x], sizeof(cubeColors[x]));
}

void solveCross()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				copyCrossColor(i, j, k);
				solveCross1(i, j, k);
			}
		}
	}
}