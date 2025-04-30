#include "pll_cycle_sequence_finder.h"

const Notation* findPLLCycleSequence(const bool match[4])
{
	for (int i = 0; i < 5; i++)
	{
		int j = 0;
		while (j < 4 && PLLCycleSequences[i].match[j] == match[j])
		{
			j++;
		}
		if (j == 4)
		{
			return PLLCycleSequences[i].sequence;
		}
	}
	Notation* n = None;
	return n;
}