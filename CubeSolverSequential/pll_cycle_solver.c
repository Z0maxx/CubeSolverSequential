#include "pll_cycle_solver.h"

bool setPLLCycleMatch(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, bool match[4])
{
	for (int i = 0; i < 4; i++)
	{
		Color colors[3];
		for (int j = 0; j < 3; j++)
		{
			colors[j] = F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][PLLCycleReferences[i][j].layer][PLLCycleReferences[i][j].cube][PLLCycleReferences[i][j].side];
		}
		const uint2 corner = findCorner(F2LEdgeCubeColors[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y], colors, 4);
		match[i] = corner.x == PLLCycleCubeReferences[i].layer && corner.y == PLLCycleCubeReferences[i].cube;
	}
	int j = 0;
	while (j < 4 && match[j])
	{
		j++;
	}
	return j == 4;
}

void PLLCycleSolve(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx)
{
	bool match[4];
	int idx = 0;
	while (!setPLLCycleMatch(cubeIdx, crossIdx, cornerIdx, edgeIdx, match))
	{
		const Notation* sequence = findPLLCycleSequence(match);
		executePLLCycleSequence(cubeIdx, crossIdx, cornerIdx, edgeIdx, sequence, idx);
		idx++;
	}
}

void solvePLLCycle1(int t, int u, int v, int w, int x, int y, int z)
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

	PLLCycleSolve(cubeIdx, crossIdx, cornerIdx, edgeIdx);
}

void solvePLLCycle()
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
								solvePLLCycle1(i, j, k, l, m, n, o);
							}
						}
					}
				}
			}
		}
	}
}