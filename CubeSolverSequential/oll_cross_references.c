#include "oll_cross_references.h"

Reference OLLCrossReferences[4] =
{
	{
		Layer_Front,
		Cube_Top,
		Side_Top
	},
	{
		Layer_Back,
		Cube_Top,
		Side_Top
	},
	{
		Layer_Middle,
		Cube_Top_Left,
		Side_Top
	},
	{
		Layer_Middle,
		Cube_Top_Right,
		Side_Top
	}
};

Reference OLLCrossTargetReference =
{
	Layer_Middle,
	Cube_Top,
	Side_Top
};