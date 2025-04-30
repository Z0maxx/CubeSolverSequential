#include "oll_cross_solver.h"

bool setOLLCrossMatch(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, const Color targetColor, bool match[4])
{
	for (int i = 0; i < 4; i++)
	{
		match[i] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][OLLCrossReferences[i].layer][OLLCrossReferences[i].cube][OLLCrossReferences[i].side] == targetColor;
	}
	int j = 0;
	while (j < 4 && match[j])
	{
		j++;
	}
	return j == 4;
}
void OLLCrossSolve(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx)
{
	const Color targetColor = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][OLLCrossTargetReference.layer][OLLCrossTargetReference.cube][OLLCrossTargetReference.side];
	bool match[4];
	int idx = 0;

	while (!setOLLCrossMatch(cubeIdx, crossIdx, cornerIdx, edgeIdx, targetColor, match))
	{
		const Notation* sequence = findOLLCrossSequence(match);
		executeOLLCrossSequence(cubeIdx, crossIdx, cornerIdx, edgeIdx, sequence, idx);
		idx++;
	}
}

void solveOLLCross1(int t, int u, int v, int w, int x, int y, int z)
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

	OLLCrossSolve(cubeIdx, crossIdx, cornerIdx, edgeIdx);
}

void solveOLLCross()
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
								solveOLLCross1(i, j, k, l, m, n, o);
							}
						}
					}
				}
			}
		}
	}
}