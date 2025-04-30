#include "f2l_corner_references.h"

 Reference F2LCornerReferences[3] =
{
	{
		Layer_Middle,
		Cube_Left,
		Side_Left
	},
	{
		Layer_Front,
		Cube_Center,
		Side_Front
	},
	{
		Layer_Middle,
		Cube_Bottom,
		Side_Bottom
	}
};

Reference F2LCornerTargetReference =
{
	Layer_Front,
	Cube_Center,
	Side_Front,
};