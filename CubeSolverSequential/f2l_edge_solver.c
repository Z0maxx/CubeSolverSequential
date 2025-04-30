#include "f2l_edge_solver.h"

int F2LEdgeRotations[6][4][6][4][6][4][6];

void solveF2LEdgePiece(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, const int idx, const int solveOrderIdx)
{
	SolveRotation solveRotation = findSolveRotation(F2LEdgeRotations[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y], solveOrderIdx);
	if (solveRotation.rotation != 99)
	{
		turnF2LEdgeCube(cubeIdx, crossIdx, cornerIdx, edgeIdx, solveRotation.direction, solveRotation.twice);
		F2LEdgeRotationMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][idx] = solveRotation.notation;
		F2LEdgeRotations[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y] = solveRotation.newRotation;
	}
	
	Color colors[2];
	for (int i = 0; i < 2; i++)
	{
		colors[i] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][F2LEdgeReferences[i].layer][F2LEdgeReferences[i].cube][F2LEdgeReferences[i].side];
	}
	const uint2 edge = findEdge(F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y], colors, 8);
	const Color targetColor = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][F2LEdgeTargetReference.layer][F2LEdgeTargetReference.cube][F2LEdgeTargetReference.side];
	const Notation* sequence = findF2LEdgeSequence(edge, F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][edge.x][edge.y], targetColor);
	executeF2LEdgeSequence(cubeIdx, crossIdx, cornerIdx, edgeIdx, sequence, idx);
}

void solveF2LEdge1(int t, int u, int v, int w, int x, int y, int z)
{
	const int cubeIdx = t;

	const int crossIdxX = u;
	const int crossIdxY = v;
	const uint2 crossIdx = { crossIdxX, crossIdxY };

	const int cornerIdxX = w;
	const int cornerIdxY = x;
	const uint2 cornerIdx = { cornerIdxX, cornerIdxY };

	const int edgeIdxX = y;
	const int edgeIdxY = z;
	const uint2 edgeIdx = { edgeIdxX, edgeIdxY };

	for (int i = 0; i < 4; i++)
	{
		solveF2LEdgePiece(cubeIdx, crossIdx, cornerIdx, edgeIdx, i, solveOrders[edgeIdx.x][edgeIdx.y][i]);
	}
}

void copyF2LEdgeColor(int t, int u, int v, int w, int x, int y, int z)
{
	memcpy(F2LEdgeCubeColors[t][u][v][w][x][y][z], F2LCornerCubeColors[t][u][v][w][x], sizeof(F2LCornerCubeColors[t][u][v][w][x]));
}

void solveF2LEdge()
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
						for (int n = 0; n < 4; n++)
						{
							for (int o = 0; o < 6; o++)
							{
								copyF2LEdgeColor(i, j, k, l, m, n, o);
								solveF2LEdge1(i, j, k, l, m, n, o);
							}
						}
					}
				}
			}
		}
	}
}