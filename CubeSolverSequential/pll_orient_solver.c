#include "pll_orient_solver.h"

bool isPLLOrientCorrect(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, const Color targetColor)
{
	int j = 0;
	while (j < 4 && F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][PLLOrientTargetReferences[j].layer][PLLOrientTargetReferences[j].cube][PLLOrientTargetReferences[j].side] == targetColor)
	{
		j++;
	}
	return j == 4;
}

bool isPLLOrientCurrentCorrect(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, const Color targetColor)
{
	return F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][PLLOrientCurrentTargetReference.layer][PLLOrientCurrentTargetReference.cube][PLLOrientCurrentTargetReference.side] == targetColor;
}

bool isPLLOrientTopLayerCorrect(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, const Color targetColor)
{
	return F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][PLLOrientFinalReferences[0].layer][PLLOrientFinalReferences[0].cube][PLLOrientFinalReferences[0].side] == targetColor;
}

int PLLOrientCorrectCount(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, const Color targetColor)
{
	int j = 0;
	while (j < 4 && F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][PLLOrientTargetReferences[j].layer][PLLOrientTargetReferences[j].cube][PLLOrientTargetReferences[j].side] == targetColor)
	{
		j++;
	}
	return j;
}

bool doesPLLOrientEdgeMatch(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx)
{
	Color colors[2];
	for (int i = 0; i < 2; i++)
	{
		colors[i] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][PLLOrientEdgeMatchReferences[i].layer][PLLOrientEdgeMatchReferences[i].cube][PLLOrientEdgeMatchReferences[i].side];
	}
	return colors[0] == colors[1];
}

bool doesPLLOrientCornerMatch(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx)
{
	Color colors[4];
	for (int i = 0; i < 4; i++)
	{
		colors[i] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][PLLOrientCornerMatchReferences[i].layer][PLLOrientCornerMatchReferences[i].cube][PLLOrientCornerMatchReferences[i].side];
	}
	return colors[0] == colors[1] && colors[2] == colors[3];
}

void PLLOrientSolve(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx)
{
	Color targetColor = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][PLLOrientReference.layer][PLLOrientReference.cube][PLLOrientReference.side];
	int idx = 0;
	int roundIdx = 0;
	bool cornerError = false;
	int correctCount = PLLOrientCorrectCount(cubeIdx, crossIdx, cornerIdx, edgeIdx, targetColor);
	bool edgeMatch = doesPLLOrientEdgeMatch(cubeIdx, crossIdx, cornerIdx, edgeIdx);
	bool cornerMatch = doesPLLOrientCornerMatch(cubeIdx, crossIdx, cornerIdx, edgeIdx);
	while (correctCount != 4 && !(edgeMatch && cornerMatch && correctCount == 3))
	{
		bool currentCorrect = isPLLOrientCurrentCorrect(cubeIdx, crossIdx, cornerIdx, edgeIdx, targetColor);
		roundIdx = 0;

		while (!currentCorrect && !(edgeMatch && cornerMatch && correctCount == 3))
		{
			executePLLOrientSequence(cubeIdx, crossIdx, cornerIdx, edgeIdx, idx, roundIdx);
			currentCorrect = isPLLOrientCurrentCorrect(cubeIdx, crossIdx, cornerIdx, edgeIdx, targetColor);
			if (!currentCorrect)
			{
				roundIdx++;
			}

			edgeMatch = doesPLLOrientEdgeMatch(cubeIdx, crossIdx, cornerIdx, edgeIdx);
			cornerMatch = doesPLLOrientCornerMatch(cubeIdx, crossIdx, cornerIdx, edgeIdx);
			if (edgeMatch && cornerMatch && !currentCorrect && correctCount == 3)
			{
				cornerError = true;
			}
		}
		correctCount = PLLOrientCorrectCount(cubeIdx, crossIdx, cornerIdx, edgeIdx, targetColor);
		if (correctCount != 4)
		{
			turnF2LEdgeLayer(cubeIdx, crossIdx, cornerIdx, edgeIdx, CubeLayer_Top, Direction_Left, false);
			PLLOrientLayerMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][idx][roundIdx][4] = U;
			idx++;
		}

		edgeMatch = doesPLLOrientEdgeMatch(cubeIdx, crossIdx, cornerIdx, edgeIdx);
		cornerMatch = doesPLLOrientCornerMatch(cubeIdx, crossIdx, cornerIdx, edgeIdx);
		if (edgeMatch && cornerMatch && correctCount == 3)
		{
			cornerError = true;
		}
	}
	int i = 0;
	targetColor = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][PLLOrientFinalReferences[1].layer][PLLOrientFinalReferences[1].cube][PLLOrientFinalReferences[1].side];
	while (!isPLLOrientTopLayerCorrect(cubeIdx, crossIdx, cornerIdx, edgeIdx, targetColor))
	{
		turnF2LEdgeLayer(cubeIdx, crossIdx, cornerIdx, edgeIdx, CubeLayer_Top, Direction_Left, false);
		i++;
	}

	Notation lastMove = None;
	switch (i)
	{
	case 1:
		lastMove = U;
		break;
	case 2:
		lastMove = U2;
		break;
	case 3:
		lastMove = Up;
		break;
	}

	PLLOrientLayerMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][idx][roundIdx][4] = lastMove;
}

void solvePLLOrient1(int t, int u, int v, int w, int x, int y, int z)
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

	PLLOrientSolve(cubeIdx, crossIdx, cornerIdx, edgeIdx);
}

void solvePLLOrient()
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
								solvePLLOrient1(i, j, k, l, m, n, o);
							}
						}
					}
				}
			}
		}
	}
}