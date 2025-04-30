#include "oll_edge_sequence_finder.h"

Notation* findOLLEdgeSequence(const bool match[4], const bool near[4])
{
	for (int i = 0; i < 15; i++)
	{
		int j = 0;
		while (j < 4 && OLLEdgeSequences[i].match[j] == match[j] && (i < 8 && OLLEdgeSequences[i].near[j] == near[j] || i >= 8))
		{
			j++;
		}
		if (j == 4)
		{
			return OLLEdgeSequences[i].sequence;
		}
	}
	Notation* n = None;
	return n;
}