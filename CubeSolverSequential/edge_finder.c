#include "edge_finder.h"

const Edge edges[12] =
{
	{
		Layer_Front,
		Cube_Top,
		{ Side_Top, Side_Front }
	},
	{
		Layer_Front,
		Cube_Left,
		{ Side_Left, Side_Front }
	},
	{
		Layer_Front,
		Cube_Right,
		{ Side_Right, Side_Front }
	},
	{
		Layer_Middle,
		Cube_Top_Left,
		{ Side_Left, Side_Top }
	},
	{
		Layer_Middle,
		Cube_Top_Right,
		{ Side_Right, Side_Top }
	},
	{
		Layer_Back,
		Cube_Top,
		{ Side_Top, Side_Back }
	},
	{
		Layer_Back,
		Cube_Left,
		{ Side_Left, Side_Back }
	},
	{
		Layer_Back,
		Cube_Right,
		{ Side_Right, Side_Back}
	},
	{
		Layer_Front,
		Cube_Bottom,
		{ Side_Bottom, Side_Front}
	},
	{
		Layer_Middle,
		Cube_Bottom_Left,
		{ Side_Left, Side_Bottom}
	},
	{
		Layer_Middle,
		Cube_Bottom_Right,
		{ Side_Right, Side_Bottom}
	},
	{
		Layer_Back,
		Cube_Bottom,
		{ Side_Bottom, Side_Back}
	},
};

const uint2 findEdge(const Color cubeColors[3][9][6], const Color colors[2], const int count)
{
	uint2 rv;
	for (int i = 0; i < count; i++)
	{
		const Layer layer = edges[i].layer;
		const Cube cube = edges[i].cube;
		Color targetColors[2];
		for (int j = 0; j < 2; j++)
		{
			targetColors[j] = cubeColors[layer][cube][edges[i].sides[j]];
		}
		if (targetColors[0] == colors[0] && targetColors[1] == colors[1] || targetColors[0] == colors[1] && targetColors[1] == colors[0])
		{
			rv.x = layer;
			rv.y = cube;
			return rv;
		}
	}
	rv.x = 100;
	rv.y = 100;
	return rv;
}