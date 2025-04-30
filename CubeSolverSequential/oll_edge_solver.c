#include "oll_edge_solver.h"

bool setOLLEdgeMatch(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, bool match[4])
{
	for (int i = 0; i < 4; i++)
	{
		const Color color = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][OLLEdgeReferences[i].layer][OLLEdgeReferences[i].cube][OLLEdgeReferences[i].side];
		const Color targetColor = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][OLLEdgeTargetReferences[i].layer][OLLEdgeTargetReferences[i].cube][OLLEdgeTargetReferences[i].side];
		match[i] = color == targetColor;
	}
	int j = 0;
	while (j < 4 && !match[j])
	{
		j++;
	}
	return j < 4;
}

void setOLLEdgeNear(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, bool near[4])
{
	for (int i = 0; i < 4; i++)
	{
		const Color origin = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][OLLEdgeNearReferences[i].origin.layer][OLLEdgeNearReferences[i].origin.cube][OLLEdgeNearReferences[i].origin.side];
		const Color leftTarget = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][OLLEdgeNearReferences[i].leftTarget.layer][OLLEdgeNearReferences[i].leftTarget.cube][OLLEdgeNearReferences[i].leftTarget.side];
		const Color rightTarget = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][OLLEdgeNearReferences[i].rightTarget.layer][OLLEdgeNearReferences[i].rightTarget.cube][OLLEdgeNearReferences[i].rightTarget.side];
		near[i] = origin == leftTarget || origin == rightTarget;
	}
}

void OLLEdgeSolve(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx)
{
	Notation firstMove = None;
	bool match[4];
	int i = 0;
	while (!setOLLEdgeMatch(cubeIdx, crossIdx, cornerIdx, edgeIdx, match))
	{
		turnF2LEdgeLayer(cubeIdx, crossIdx, cornerIdx, edgeIdx, CubeLayer_Top, Direction_Left, false);
		i++;
	}
	switch (i)
	{
	case 1:
		firstMove = U;
		break;
	case 2:
		firstMove = U2;
		break;
	case 3:
		firstMove = Up;
		break;
	}
	
	OLLEdgeLayerMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][0] = firstMove;
	bool near[4];
	setOLLEdgeNear(cubeIdx, crossIdx, cornerIdx, edgeIdx, near);
	const Notation* sequence = findOLLEdgeSequence(match, near);
	executeOLLEdgeSequence(cubeIdx, crossIdx, cornerIdx, edgeIdx, sequence);
}

void solveOLLEdge1(int t, int u, int v, int w, int x, int y, int z)
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

	OLLEdgeSolve(cubeIdx, crossIdx, cornerIdx, edgeIdx);
}

void solveOLLEdge()
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
								solveOLLEdge1(i, j, k, l, m, n, o);
							}
						}
					}
				}
			}
		}
	}
}