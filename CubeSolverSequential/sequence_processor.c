#include "sequence_processor.h"
#include <stdio.h>

int movesCountIdx[82944];
int movesCount[82944];

void setMoves1(int t, int u, int v, int w, int x, int y, int z)
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

	int idx = cubeIdx * 13824 + crossIdx.x * 3456 + crossIdx.y * 576 + cornerIdx.x * 144 + cornerIdx.y * 24 + edgeIdx.x * 6 + edgeIdx.y;
	movesCountIdx[idx] = idx;

	moves[idx][0] = cubeRotationMoves[cubeIdx];
	int pos = 1;
	for (int i = 0; i < 4; i++)
	{
		moves[idx][pos] = crossRotationMoves[cubeIdx][crossIdx.x][crossIdx.y][i];
		pos++;
		for (int j = 0; j < 4; j++)
		{
			moves[idx][pos] = crossLayerMoves[cubeIdx][crossIdx.x][crossIdx.y][i][j];
			pos++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		moves[idx][pos] = F2LCornerRotationMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][i];
		pos++;
		for (int j = 0; j < 8; j++)
		{
			moves[idx][pos] = F2LCornerLayerMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][i][j];
			pos++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		moves[idx][pos] = F2LEdgeRotationMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][i];
		pos++;
		for (int j = 0; j < 16; j++)
		{
			moves[idx][pos] = F2LEdgeLayerMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][i][j];
			pos++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			moves[idx][pos] = OLLCrossLayerMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][i][j];
			pos++;
		}
	}

	for (int i = 0; i < 16; i++)
	{
		moves[idx][pos] = OLLEdgeLayerMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][i];
		pos++;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			moves[idx][pos] = PLLCycleLayerMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][i][j];
			pos++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				moves[idx][pos] = PLLOrientLayerMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][i][j][k];
				pos++;
			}
		}
	}
}

void setMoves()
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
								setMoves1(i, j, k, l, m, n, o);
							}
						}
					}
				}
			}
		}
	}
}

void setMovesCount1(int t, int u, int v, int w, int x, int y, int z)
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

	const int idx = cubeIdx * 13824 + crossIdx.x * 3456 + crossIdx.y * 576 + cornerIdx.x * 144 + cornerIdx.y * 24 + edgeIdx.x * 6 + edgeIdx.y;

	int count = 0;
	Notation last = None;
	int lastIdx = -1;

	for (int i = 0; i < 263; i++)
	{
		Notation current = moves[idx][i];
		if (current != None)
		{
			if (lastIdx != -1)
			{
				//U + U' = None and U2 + U2 = None
				if (abs(current - last) == 1 && (current % 3 == 1 && last % 3 == 2 || current % 3 == 2 && last % 3 == 1) ||
					current == last && current % 3 == 0)
				{
					moves[idx][i] = None;
					moves[idx][lastIdx] = None;
					count--;
				}

				//U + U = U2 and U' + U' = U2
				else if (current == last && current % 3 != 0)
				{
					int newMove = current + 2;
					if (current % 3 == 2)
					{
						newMove = current + 1;
					}
					moves[idx][i] = (Notation)newMove;
					moves[idx][lastIdx] = None;
				}

				//U + U2 = U'
				else if (abs(current - last) == 2 && (current % 3 == 0 && last % 3 == 1 || current % 3 == 1 && last % 3 == 0))
				{
					moves[idx][i] = (Notation)((current < last ? current : last) + 1);
					moves[idx][lastIdx] = None;
				}

				//U' + U2 = U
				else if (abs(current - last) == 1 && (current % 3 == 0 && last % 3 == 2 || current % 3 == 2 && last % 3 == 0))
				{
					moves[idx][i] = (Notation)((current < last ? current : last) - 1);
					moves[idx][lastIdx] = None;
				}

				else {
					count++;
				}
			}
			else
			{
				count++;
			}

			if (moves[idx][i] != None)
			{
				last = moves[idx][i];
				lastIdx = i;
			}
			else if (lastIdx != -1 && moves[idx][lastIdx] == None)
			{
				int j = lastIdx;
				while (j > -1 && moves[idx][j] == None)
				{
					j--;
				}
				if (j != -1)
				{
					last = moves[idx][j];
				}
				lastIdx = j;
			}
		}
	}
	movesCount[idx] = count;
}

void setMovesCount()
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
								setMovesCount1(i, j, k, l, m, n, o);
							}
						}
					}
				}
			}
		}
	}
}

Notation* getSequence()
{
	int min = -1;
	int minIdx = -1;
	for (int i = 0; i < 82944; i++)
	{
		if (min > movesCount[i] || min == -1)
		{
			min = movesCount[i];
			minIdx = i;
		}
	}
	return moves[minIdx];
}
Notation* findSequence()
{
	setMoves();
	setMovesCount();
	return getSequence();
}