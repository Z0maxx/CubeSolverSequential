#include "pll_orient_references.h"

Reference PLLOrientReference =
{
	Layer_Middle,
	Cube_Top,
	Side_Top
};

Reference PLLOrientTargetReferences[4] =
{
	{
		Layer_Front,
		Cube_Top_Left,
		Side_Top
	},
	{
		Layer_Back,
		Cube_Top_Left,
		Side_Top
	},
	{
		Layer_Back,
		Cube_Top_Right,
		Side_Top
	},
	{
		Layer_Front,
		Cube_Top_Right,
		Side_Top
	}
};

Reference PLLOrientCurrentTargetReference =
{
	Layer_Front,
	Cube_Top_Left,
	Side_Top
};

Reference PLLOrientEdgeMatchReferences[2] =
{
	{
		Layer_Front,
		Cube_Center,
		Side_Front
	},
	{
		Layer_Front,
		Cube_Left,
		Side_Front
	}
};

Reference PLLOrientCornerMatchReferences[4] =
{
	{
		Layer_Front,
		Cube_Center,
		Side_Front
	},
	{
		Layer_Front,
		Cube_Bottom_Left,
		Side_Front
	},
	{
		Layer_Middle,
		Cube_Left,
		Side_Left
	},
	{
		Layer_Front,
		Cube_Bottom_Left,
		Side_Left
	}
};


Reference PLLOrientFinalReferences[2] =
{
	{
		Layer_Front,
		Cube_Top,
		Side_Front
	},
	{
		Layer_Front,
		Cube_Center,
		Side_Front
	}
};