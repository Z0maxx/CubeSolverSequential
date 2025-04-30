#include "cross_sequence_finder.h"

const Notation* findCrossSequence(const uint2 edge, const Color colors[6], const Color targetColor)
{
	for (int i = 0; i < 24; i++)
	{
		if (crossSequences[i].layer == edge.x && crossSequences[i].cube == edge.y && colors[crossSequences[i].side] == targetColor)
		{
			return crossSequences[i].sequence;
		}
	}
	Notation* n = None;
	return n;
}