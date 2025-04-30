#include "corner_sequence_finder.h"

const Notation* findCornerSequence(CornerSolveSequence sequences[24], const uint2 corner, const Color colors[6], const Color targetColor)
{
	for (int i = 0; i < 24; i++)
	{
		if (sequences[i].layer == corner.x && sequences[i].cube == corner.y && colors[sequences[i].side] == targetColor)
		{
			return sequences[i].sequence;
		}
	}
	Notation* n = None;
	return n;
}