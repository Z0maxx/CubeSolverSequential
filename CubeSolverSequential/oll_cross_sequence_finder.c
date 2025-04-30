#include "oll_cross_sequence_finder.h"

const Notation* findOLLCrossSequence(const bool match[4])
{
	for (int i = 0; i < 7; i++)
	{
		int j = 0;
		while (j < 4 && OLLCrossSequences[i].match[j] == match[j])
		{
			j++;
		}
		if (j == 4)
		{
			return OLLCrossSequences[i].sequence;
		}
	}
	Notation* n = None;
	return n;
}