#include "f2l_edge_sequence_finder.h"

const Notation* findF2LEdgeSequence(const uint2 edge, const Color colors[6], const Color targetColor)
{
	for (int i = 0; i < 16; i++)
	{
		if (F2LEdgeSequences[i].layer == edge.x && F2LEdgeSequences[i].cube == edge.y && colors[F2LEdgeSequences[i].side] == targetColor)
		{
			return F2LEdgeSequences[i].sequence;
		}
	}
	Notation* n = None;
	return n;
}