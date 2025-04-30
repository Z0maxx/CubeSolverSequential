#include "cross_sequence_executor.h"

void executeCrossSequence(const int cubeIdx, const uint2 crossIdx, const Notation sequence[], const int idx)
{
	int i = 0;
	while (i < 4 && sequence[i] != None)
	{
		crossLayerMoves[cubeIdx][crossIdx.x][crossIdx.y][idx][i] = sequence[i];
		const TranslatedNotation move = translateNotation(sequence[i]);
		turnCrossLayer(cubeIdx, crossIdx, move.cubeLayer, move.direction, move.twice);
		i++;
	}
}