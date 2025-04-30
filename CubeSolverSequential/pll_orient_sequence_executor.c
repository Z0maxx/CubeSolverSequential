#include "pll_orient_sequence_executor.h"

void executePLLOrientSequence(const int cubeIdx, const uint2 crossIdx, const uint2 cornerIdx, const uint2 edgeIdx, const int idx, const int roundIdx)
{
	for (int i = 0; i < 4; i++)
	{
		PLLOrientLayerMoves[cubeIdx][crossIdx.x][crossIdx.y][cornerIdx.x][cornerIdx.y][edgeIdx.x][edgeIdx.y][idx][roundIdx][i] = PLLOrientSequence[i];
		const TranslatedNotation move = translateNotation(PLLOrientSequence[i]);
		turnF2LEdgeLayer(cubeIdx, crossIdx, cornerIdx, edgeIdx, move.cubeLayer, move.direction, move.twice);
	}
}