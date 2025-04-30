#include "variables.h"

const Move layerCornerMoves[9][2][4] =
{
	{
		{
			{
				Layer_Front,
				Cube_Top_Left,
				{Side_Left, Side_Top},
				Layer_Front,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Left},
			},
			{
				Layer_Front,
				Cube_Top_Right,
				{Side_Top, Side_Right},
				Layer_Front,
				Cube_Top_Left,
				{Side_Left, Side_Top}
			},
			{
				Layer_Front,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Left},
				Layer_Front,
				Cube_Bottom_Right,
				{Side_Right, Side_Bottom}
			},
			{
				Layer_Front,
				Cube_Bottom_Right,
				{Side_Right, Side_Bottom},
				Layer_Front,
				Cube_Top_Right,
				{Side_Top, Side_Right}
			}
		},
		{
			{
				Layer_Front,
				Cube_Top_Left,
				{Side_Left, Side_Top},
				Layer_Front,
				Cube_Top_Right,
				{Side_Top, Side_Right}
			},
			{
				Layer_Front,
				Cube_Top_Right,
				{Side_Top, Side_Right},
				Layer_Front,
				Cube_Bottom_Right,
				{Side_Right, Side_Bottom}
			},
			{
				Layer_Front,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Left},
				Layer_Front,
				Cube_Top_Left,
				{Side_Left, Side_Top}
			},
			{
				Layer_Front,
				Cube_Bottom_Right,
				{Side_Right, Side_Bottom},
				Layer_Front,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Left}
			}
		}
	},
	{
		{
			{
				Layer_Middle,
				Cube_Top_Left,
				{Side_Left, Side_Top},
				Layer_Middle,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Left},
			},
			{
				Layer_Middle,
				Cube_Top_Right,
				{Side_Top, Side_Right},
				Layer_Middle,
				Cube_Top_Left,
				{Side_Left, Side_Top}
			},
			{
				Layer_Middle,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Left},
				Layer_Middle,
				Cube_Bottom_Right,
				{Side_Right, Side_Bottom}
			},
			{
				Layer_Middle,
				Cube_Bottom_Right,
				{Side_Right, Side_Bottom},
				Layer_Middle,
				Cube_Top_Right,
				{Side_Top, Side_Right}
			}
		},
		{
			{
				Layer_Middle,
				Cube_Top_Left,
				{Side_Left, Side_Top},
				Layer_Middle,
				Cube_Top_Right,
				{Side_Top, Side_Right}
			},
			{
				Layer_Middle,
				Cube_Top_Right,
				{Side_Top, Side_Right},
				Layer_Middle,
				Cube_Bottom_Right,
				{Side_Right, Side_Bottom}
			},
			{
				Layer_Middle,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Left},
				Layer_Middle,
				Cube_Top_Left,
				{Side_Left, Side_Top}
			},
			{
				Layer_Middle,
				Cube_Bottom_Right,
				{Side_Right, Side_Bottom},
				Layer_Middle,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Left}
			}
		}
	},
	{
		{
			{
				Layer_Back,
				Cube_Top_Left,
				{Side_Left, Side_Top},
				Layer_Back,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Left},
			},
			{
				Layer_Back,
				Cube_Top_Right,
				{Side_Top, Side_Right},
				Layer_Back,
				Cube_Top_Left,
				{Side_Left, Side_Top}
			},
			{
				Layer_Back,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Left},
				Layer_Back,
				Cube_Bottom_Right,
				{Side_Right, Side_Bottom}
			},
			{
				Layer_Back,
				Cube_Bottom_Right,
				{Side_Right, Side_Bottom},
				Layer_Back,
				Cube_Top_Right,
				{Side_Top, Side_Right}
			}
		},
		{
			{
				Layer_Back,
				Cube_Top_Left,
				{Side_Left, Side_Top},
				Layer_Back,
				Cube_Top_Right,
				{Side_Top, Side_Right}
			},
			{
				Layer_Back,
				Cube_Top_Right,
				{Side_Top, Side_Right},
				Layer_Back,
				Cube_Bottom_Right,
				{Side_Right, Side_Bottom}
			},
			{
				Layer_Back,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Left},
				Layer_Back,
				Cube_Top_Left,
				{Side_Left, Side_Top}
			},
			{
				Layer_Back,
				Cube_Bottom_Right,
				{Side_Right, Side_Bottom},
				Layer_Back,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Left}
			}
		}
	},
	{
		{
			{
				Layer_Front,
				Cube_Top_Left,
				{Side_Top, Side_Front},
				Layer_Back,
				Cube_Top_Left,
				{Side_Back, Side_Top}
			},
			{
				Layer_Front,
				Cube_Bottom_Left,
				{Side_Front, Side_Bottom},
				Layer_Front,
				Cube_Top_Left,
				{Side_Top, Side_Front}
			},
			{
				Layer_Back,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Back},
				Layer_Front,
				Cube_Bottom_Left,
				{Side_Front, Side_Bottom}
			},
			{
				Layer_Back,
				Cube_Top_Left,
				{Side_Back, Side_Top},
				Layer_Back,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Back}
			}
		},
		{
			{
				Layer_Front,
				Cube_Top_Left,
				{Side_Top, Side_Front},
				Layer_Front,
				Cube_Bottom_Left,
				{Side_Front, Side_Bottom}
			},
			{
				Layer_Back,
				Cube_Top_Left,
				{Side_Back, Side_Top},
				Layer_Front,
				Cube_Top_Left,
				{Side_Top, Side_Front}
			},
			{
				Layer_Back,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Back},
				Layer_Back,
				Cube_Top_Left,
				{Side_Back, Side_Top},
			},
			{
				Layer_Front,
				Cube_Bottom_Left,
				{Side_Front, Side_Bottom},
				Layer_Back,
				Cube_Bottom_Left,
				{Side_Bottom, Side_Back}
			}
		}
	},
	{
		{
			{
				Layer_Front,
				Cube_Top,
				{Side_Top, Side_Front},
				Layer_Back,
				Cube_Top,
				{Side_Back, Side_Top}
			},
			{
				Layer_Front,
				Cube_Bottom,
				{Side_Front, Side_Bottom},
				Layer_Front,
				Cube_Top,
				{Side_Top, Side_Front}
			},
			{
				Layer_Back,
				Cube_Bottom,
				{Side_Bottom, Side_Back},
				Layer_Front,
				Cube_Bottom,
				{Side_Front, Side_Bottom}
			},
			{
				Layer_Back,
				Cube_Top,
				{Side_Back, Side_Top},
				Layer_Back,
				Cube_Bottom,
				{Side_Bottom, Side_Back}
			}
		},
		{
			{
				Layer_Front,
				Cube_Top,
				{Side_Top, Side_Front},
				Layer_Front,
				Cube_Bottom,
				{Side_Front, Side_Bottom}
			},
			{
				Layer_Back,
				Cube_Top,
				{Side_Back, Side_Top},
				Layer_Front,
				Cube_Top,
				{Side_Top, Side_Front}
			},
			{
				Layer_Back,
				Cube_Bottom,
				{Side_Bottom, Side_Back},
				Layer_Back,
				Cube_Top,
				{Side_Back, Side_Top},
			},
			{
				Layer_Front,
				Cube_Bottom,
				{Side_Front, Side_Bottom},
				Layer_Back,
				Cube_Bottom,
				{Side_Bottom, Side_Back}
			}
		}
	},
	{
		{
			{
				Layer_Front,
				Cube_Top_Right,
				{Side_Top, Side_Front},
				Layer_Back,
				Cube_Top_Right,
				{Side_Back, Side_Top}
			},
			{
				Layer_Front,
				Cube_Bottom_Right,
				{Side_Front, Side_Bottom},
				Layer_Front,
				Cube_Top_Right,
				{Side_Top, Side_Front}
			},
			{
				Layer_Back,
				Cube_Bottom_Right,
				{Side_Bottom, Side_Back},
				Layer_Front,
				Cube_Bottom_Right,
				{Side_Front, Side_Bottom}
			},
			{
				Layer_Back,
				Cube_Top_Right,
				{Side_Back, Side_Top},
				Layer_Back,
				Cube_Bottom_Right,
				{Side_Bottom, Side_Back}
			}
		},
		{
			{
				Layer_Front,
				Cube_Top_Right,
				{Side_Top, Side_Front},
				Layer_Front,
				Cube_Bottom_Right,
				{Side_Front, Side_Bottom}
			},
			{
				Layer_Back,
				Cube_Top_Right,
				{Side_Back, Side_Top},
				Layer_Front,
				Cube_Top_Right,
				{Side_Top, Side_Front}
			},
			{
				Layer_Back,
				Cube_Bottom_Right,
				{Side_Bottom, Side_Back},
				Layer_Back,
				Cube_Top_Right,
				{Side_Back, Side_Top},
			},
			{
				Layer_Front,
				Cube_Bottom_Right,
				{Side_Front, Side_Bottom},
				Layer_Back,
				Cube_Bottom_Right,
				{Side_Bottom, Side_Back}
			}
		}
	},
	{
		{
			{
				Layer_Front,
				Cube_Top_Left,
				{Side_Left, Side_Front},
				Layer_Back,
				Cube_Top_Left,
				{Side_Back, Side_Left}
			},
			{
				Layer_Front,
				Cube_Top_Right,
				{Side_Front, Side_Right},
				Layer_Front,
				Cube_Top_Left,
				{Side_Left, Side_Front}
			},
			{
				Layer_Back,
				Cube_Top_Right,
				{Side_Right, Side_Back},
				Layer_Front,
				Cube_Top_Right,
				{Side_Front, Side_Right}
			},
			{
				Layer_Back,
				Cube_Top_Left,
				{Side_Back, Side_Left},
				Layer_Back,
				Cube_Top_Right,
				{Side_Right, Side_Back}
			}
		},
		{
			{
				Layer_Front,
				Cube_Top_Left,
				{Side_Left, Side_Front},
				Layer_Front,
				Cube_Top_Right,
				{Side_Front, Side_Right}
			},
			{
				Layer_Back,
				Cube_Top_Left,
				{Side_Back, Side_Left},
				Layer_Front,
				Cube_Top_Left,
				{Side_Left, Side_Front}
			},
			{
				Layer_Back,
				Cube_Top_Right,
				{Side_Right, Side_Back},
				Layer_Back,
				Cube_Top_Left,
				{Side_Back, Side_Left}
			},
			{
				Layer_Front,
				Cube_Top_Right,
				{Side_Front, Side_Right},
				Layer_Back,
				Cube_Top_Right,
				{Side_Right, Side_Back}
			}
		}
	},
	{
		{
			{
				Layer_Front,
				Cube_Left,
				{Side_Left, Side_Front},
				Layer_Back,
				Cube_Left,
				{Side_Back, Side_Left}
			},
			{
				Layer_Front,
				Cube_Right,
				{Side_Front, Side_Right},
				Layer_Front,
				Cube_Left,
				{Side_Left, Side_Front}
			},
			{
				Layer_Back,
				Cube_Right,
				{Side_Right, Side_Back},
				Layer_Front,
				Cube_Right,
				{Side_Front, Side_Right}
			},
			{
				Layer_Back,
				Cube_Left,
				{Side_Back, Side_Left},
				Layer_Back,
				Cube_Right,
				{Side_Right, Side_Back}
			}
		},
		{
			{
				Layer_Front,
				Cube_Left,
				{Side_Left, Side_Front},
				Layer_Front,
				Cube_Right,
				{Side_Front, Side_Right}
			},
			{
				Layer_Back,
				Cube_Left,
				{Side_Back, Side_Left},
				Layer_Front,
				Cube_Left,
				{Side_Left, Side_Front}
			},
			{
				Layer_Back,
				Cube_Right,
				{Side_Right, Side_Back},
				Layer_Back,
				Cube_Left,
				{Side_Back, Side_Left}
			},
			{
				Layer_Front,
				Cube_Right,
				{Side_Front, Side_Right},
				Layer_Back,
				Cube_Right,
				{Side_Right, Side_Back}
			}
		}
	},
	{
		{
			{
				Layer_Front,
				Cube_Bottom_Left,
				{Side_Left, Side_Front},
				Layer_Back,
				Cube_Bottom_Left,
				{Side_Back, Side_Left}
			},
			{
				Layer_Front,
				Cube_Bottom_Right,
				{Side_Front, Side_Right},
				Layer_Front,
				Cube_Bottom_Left,
				{Side_Left, Side_Front}
			},
			{
				Layer_Back,
				Cube_Bottom_Right,
				{Side_Right, Side_Back},
				Layer_Front,
				Cube_Bottom_Right,
				{Side_Front, Side_Right}
			},
			{
				Layer_Back,
				Cube_Bottom_Left,
				{Side_Back, Side_Left},
				Layer_Back,
				Cube_Bottom_Right,
				{Side_Right, Side_Back}
			}
		},
		{
			{
				Layer_Front,
				Cube_Bottom_Left,
				{Side_Left, Side_Front},
				Layer_Front,
				Cube_Bottom_Right,
				{Side_Front, Side_Right}
			},
			{
				Layer_Back,
				Cube_Bottom_Left,
				{Side_Back, Side_Left},
				Layer_Front,
				Cube_Bottom_Left,
				{Side_Left, Side_Front}
			},
			{
				Layer_Back,
				Cube_Bottom_Right,
				{Side_Right, Side_Back},
				Layer_Back,
				Cube_Bottom_Left,
				{Side_Back, Side_Left}
			},
			{
				Layer_Front,
				Cube_Bottom_Right,
				{Side_Front, Side_Right},
				Layer_Back,
				Cube_Bottom_Right,
				{Side_Right, Side_Back}
			}
		}
	},
};

const Move layerEdgeMoves[9][2][4] =
{
	{
		{
			{
				Layer_Front,
				Cube_Top,
				{Side_Top},
				Layer_Front,
				Cube_Left,
				{Side_Left}
			},
			{
				Layer_Front,
				Cube_Left,
				{Side_Left},
				Layer_Front,
				Cube_Bottom,
				{Side_Bottom}
			},
			{
				Layer_Front,
				Cube_Right,
				{Side_Right},
				Layer_Front,
				Cube_Top,
				{Side_Top}
			},
			{
				Layer_Front,
				Cube_Bottom,
				{Side_Bottom},
				Layer_Front,
				Cube_Right,
				{Side_Right}
			}
		},
		{
			{
				Layer_Front,
				Cube_Top,
				{Side_Top},
				Layer_Front,
				Cube_Right,
				{Side_Right}
			},
			{
				Layer_Front,
				Cube_Left,
				{Side_Left},
				Layer_Front,
				Cube_Top,
				{Side_Top}
			},
			{
				Layer_Front,
				Cube_Right,
				{Side_Right},
				Layer_Front,
				Cube_Bottom,
				{Side_Bottom}
			},
			{
				Layer_Front,
				Cube_Bottom,
				{Side_Bottom},
				Layer_Front,
				Cube_Left,
				{Side_Left}
			}
		}
	},
	{
		{
			{
				Layer_Middle,
				Cube_Top,
				{Side_Top},
				Layer_Middle,
				Cube_Left,
				{Side_Left}
			},
			{
				Layer_Middle,
				Cube_Left,
				{Side_Left},
				Layer_Middle,
				Cube_Bottom,
				{Side_Bottom}
			},
			{
				Layer_Middle,
				Cube_Right,
				{Side_Right},
				Layer_Middle,
				Cube_Top,
				{Side_Top}
			},
			{
				Layer_Middle,
				Cube_Bottom,
				{Side_Bottom},
				Layer_Middle,
				Cube_Right,
				{Side_Right}
			}
		},
		{
			{
				Layer_Middle,
				Cube_Top,
				{Side_Top},
				Layer_Middle,
				Cube_Right,
				{Side_Right}
			},
			{
				Layer_Middle,
				Cube_Left,
				{Side_Left},
				Layer_Middle,
				Cube_Top,
				{Side_Top}
			},
			{
				Layer_Middle,
				Cube_Right,
				{Side_Right},
				Layer_Middle,
				Cube_Bottom,
				{Side_Bottom}
			},
			{
				Layer_Middle,
				Cube_Bottom,
				{Side_Bottom},
				Layer_Middle,
				Cube_Left,
				{Side_Left}
			}
		}
	},
	{
		{
			{
				Layer_Back,
				Cube_Top,
				{Side_Top},
				Layer_Back,
				Cube_Left,
				{Side_Left}
			},
			{
				Layer_Back,
				Cube_Left,
				{Side_Left},
				Layer_Back,
				Cube_Bottom,
				{Side_Bottom}
			},
			{
				Layer_Back,
				Cube_Right,
				{Side_Right},
				Layer_Back,
				Cube_Top,
				{Side_Top}
			},
			{
				Layer_Back,
				Cube_Bottom,
				{Side_Bottom},
				Layer_Back,
				Cube_Right,
				{Side_Right}
			}
		},
		{
			{
				Layer_Back,
				Cube_Top,
				{Side_Top},
				Layer_Back,
				Cube_Right,
				{Side_Right}
			},
			{
				Layer_Back,
				Cube_Left,
				{Side_Left},
				Layer_Back,
				Cube_Top,
				{Side_Top}
			},
			{
				Layer_Back,
				Cube_Right,
				{Side_Right},
				Layer_Back,
				Cube_Bottom,
				{Side_Bottom}
			},
			{
				Layer_Back,
				Cube_Bottom,
				{Side_Bottom},
				Layer_Back,
				Cube_Left,
				{Side_Left}
			}
		}
	},
	{
		{
			{
				Layer_Front,
				Cube_Left,
				{Side_Front},
				Layer_Middle,
				Cube_Top_Left,
				{Side_Top}
			},
			{
				Layer_Middle,
				Cube_Bottom_Left,
				{Side_Bottom},
				Layer_Front,
				Cube_Left,
				{Side_Front},
			},
			{
				Layer_Back,
				Cube_Left,
				{Side_Back},
				Layer_Middle,
				Cube_Bottom_Left,
				{Side_Bottom}
			},
			{
				Layer_Middle,
				Cube_Top_Left,
				{Side_Top},
				Layer_Back,
				Cube_Left,
				{Side_Back}
			}
		},
		{
			{
				Layer_Front,
				Cube_Left,
				{Side_Front},
				Layer_Middle,
				Cube_Bottom_Left,
				{Side_Bottom}
			},
			{
				Layer_Middle,
				Cube_Top_Left,
				{Side_Top},
				Layer_Front,
				Cube_Left,
				{Side_Front}
			},
			{
				Layer_Back,
				Cube_Left,
				{Side_Back},
				Layer_Middle,
				Cube_Top_Left,
				{Side_Top}
			},
			{
				Layer_Middle,
				Cube_Bottom_Left,
				{Side_Bottom},
				Layer_Back,
				Cube_Left,
				{Side_Back}
			}
		}
	},
	{
		{
			{
				Layer_Front,
				Cube_Center,
				{Side_Front},
				Layer_Middle,
				Cube_Top,
				{Side_Top}
			},
			{
				Layer_Middle,
				Cube_Bottom,
				{Side_Bottom},
				Layer_Front,
				Cube_Center,
				{Side_Front},
			},
			{
				Layer_Back,
				Cube_Center,
				{Side_Back},
				Layer_Middle,
				Cube_Bottom,
				{Side_Bottom}
			},
			{
				Layer_Middle,
				Cube_Top,
				{Side_Top},
				Layer_Back,
				Cube_Center,
				{Side_Back}
			}
		},
		{
			{
				Layer_Front,
				Cube_Center,
				{Side_Front},
				Layer_Middle,
				Cube_Bottom,
				{Side_Bottom}
			},
			{
				Layer_Middle,
				Cube_Top,
				{Side_Top},
				Layer_Front,
				Cube_Center,
				{Side_Front}
			},
			{
				Layer_Back,
				Cube_Center,
				{Side_Back},
				Layer_Middle,
				Cube_Top,
				{Side_Top}
			},
			{
				Layer_Middle,
				Cube_Bottom,
				{Side_Bottom},
				Layer_Back,
				Cube_Center,
				{Side_Back}
			}
		}
	},
	{
		{
			{
				Layer_Front,
				Cube_Right,
				{Side_Front},
				Layer_Middle,
				Cube_Top_Right,
				{Side_Top}
			},
			{
				Layer_Middle,
				Cube_Bottom_Right,
				{Side_Bottom},
				Layer_Front,
				Cube_Right,
				{Side_Front},
			},
			{
				Layer_Back,
				Cube_Right,
				{Side_Back},
				Layer_Middle,
				Cube_Bottom_Right,
				{Side_Bottom}
			},
			{
				Layer_Middle,
				Cube_Top_Right,
				{Side_Top},
				Layer_Back,
				Cube_Right,
				{Side_Back}
			}
		},
		{
			{
				Layer_Front,
				Cube_Right,
				{Side_Front},
				Layer_Middle,
				Cube_Bottom_Right,
				{Side_Bottom}
			},
			{
				Layer_Middle,
				Cube_Top_Right,
				{Side_Top},
				Layer_Front,
				Cube_Right,
				{Side_Front}
			},
			{
				Layer_Back,
				Cube_Right,
				{Side_Back},
				Layer_Middle,
				Cube_Top_Right,
				{Side_Top}
			},
			{
				Layer_Middle,
				Cube_Bottom_Right,
				{Side_Bottom},
				Layer_Back,
				Cube_Right,
				{Side_Back}
			}
		}
	},
	{
		{
			{
				Layer_Front,
				Cube_Top,
				{Side_Front},
				Layer_Middle,
				Cube_Top_Left,
				{Side_Left}
			},
			{
				Layer_Middle,
				Cube_Top_Right,
				{Side_Right},
				Layer_Front,
				Cube_Top,
				{Side_Front}
			},
			{
				Layer_Back,
				Cube_Top,
				{Side_Back},
				Layer_Middle,
				Cube_Top_Right,
				{Side_Right}
			},
			{
				Layer_Middle,
				Cube_Top_Left,
				{Side_Left},
				Layer_Back,
				Cube_Top,
				{Side_Back}
			}
		},
		{
			{
				Layer_Front,
				Cube_Top,
				{Side_Front},
				Layer_Middle,
				Cube_Top_Right,
				{Side_Right}
			},
			{
				Layer_Middle,
				Cube_Top_Left,
				{Side_Left},
				Layer_Front,
				Cube_Top,
				{Side_Front}
			},
			{
				Layer_Back,
				Cube_Top,
				{Side_Back},
				Layer_Middle,
				Cube_Top_Left,
				{Side_Left}
			},
			{
				Layer_Middle,
				Cube_Top_Right,
				{Side_Right},
				Layer_Back,
				Cube_Top,
				{Side_Back}
			}
		}
	},
	{
		{
			{
				Layer_Front,
				Cube_Center,
				{Side_Front},
				Layer_Middle,
				Cube_Left,
				{Side_Left}
			},
			{
				Layer_Middle,
				Cube_Right,
				{Side_Right},
				Layer_Front,
				Cube_Center,
				{Side_Front}
			},
			{
				Layer_Back,
				Cube_Center,
				{Side_Back},
				Layer_Middle,
				Cube_Right,
				{Side_Right}
			},
			{
				Layer_Middle,
				Cube_Left,
				{Side_Left},
				Layer_Back,
				Cube_Center,
				{Side_Back}
			}
		},
		{
			{
				Layer_Front,
				Cube_Center,
				{Side_Front},
				Layer_Middle,
				Cube_Right,
				{Side_Right}
			},
			{
				Layer_Middle,
				Cube_Left,
				{Side_Left},
				Layer_Front,
				Cube_Center,
				{Side_Front}
			},
			{
				Layer_Back,
				Cube_Center,
				{Side_Back},
				Layer_Middle,
				Cube_Left,
				{Side_Left}
			},
			{
				Layer_Middle,
				Cube_Right,
				{Side_Right},
				Layer_Back,
				Cube_Center,
				{Side_Back}
			}
		}
	},
	{
		{
			{
				Layer_Front,
				Cube_Bottom,
				{Side_Front},
				Layer_Middle,
				Cube_Bottom_Left,
				{Side_Left}
			},
			{
				Layer_Middle,
				Cube_Bottom_Right,
				{Side_Right},
				Layer_Front,
				Cube_Bottom,
				{Side_Front}
			},
			{
				Layer_Back,
				Cube_Bottom,
				{Side_Back},
				Layer_Middle,
				Cube_Bottom_Right,
				{Side_Right}
			},
			{
				Layer_Middle,
				Cube_Bottom_Left,
				{Side_Left},
				Layer_Back,
				Cube_Bottom,
				{Side_Back}
			}
		},
		{
			{
				Layer_Front,
				Cube_Bottom,
				{Side_Front},
				Layer_Middle,
				Cube_Bottom_Right,
				{Side_Right}
			},
			{
				Layer_Middle,
				Cube_Bottom_Left,
				{Side_Left},
				Layer_Front,
				Cube_Bottom,
				{Side_Front}
			},
			{
				Layer_Back,
				Cube_Bottom,
				{Side_Back},
				Layer_Middle,
				Cube_Bottom_Left,
				{Side_Left}
			},
			{
				Layer_Middle,
				Cube_Bottom_Right,
				{Side_Right},
				Layer_Back,
				Cube_Bottom,
				{Side_Back}
			}
		}
	}
};

const Move faceCornerMoves[6][8] =
{
	{
		{
			Layer_Front,
			Cube_Top_Left,
			{Side_Front, Side_Left},
			Layer_Back,
			Cube_Top_Left,
			{Side_Left, Side_Back}
		},
		{
			Layer_Front,
			Cube_Top_Right,
			{Side_Front, Side_Right},
			Layer_Front,
			Cube_Top_Left,
			{Side_Left, Side_Front}
		},
		{
			Layer_Front,
			Cube_Bottom_Left,
			{Side_Front, Side_Left},
			Layer_Back,
			Cube_Bottom_Left,
			{Side_Left, Side_Back}
		},
		{
			Layer_Front,
			Cube_Bottom_Right,
			{Side_Front, Side_Right},
			Layer_Front,
			Cube_Bottom_Left,
			{Side_Left, Side_Front}
		},
		{
			Layer_Back,
			Cube_Top_Left,
			{Side_Left, Side_Back},
			Layer_Back,
			Cube_Top_Right,
			{Side_Back, Side_Right}
		},
		{
			Layer_Back,
			Cube_Top_Right,
			{Side_Right, Side_Back},
			Layer_Front,
			Cube_Top_Right,
			{Side_Front, Side_Right}
		},
		{
			Layer_Back,
			Cube_Bottom_Left,
			{Side_Left, Side_Back},
			Layer_Back,
			Cube_Bottom_Right,
			{Side_Back, Side_Right}
		},
		{
			Layer_Back,
			Cube_Bottom_Right,
			{Side_Right, Side_Back},
			Layer_Front,
			Cube_Bottom_Right,
			{Side_Front, Side_Right}
		}
	},
	{
		{
			Layer_Front,
			Cube_Top_Left,
			{Side_Front, Side_Left},
			Layer_Front,
			Cube_Top_Right,
			{Side_Right, Side_Front}
		},
		{
			Layer_Front,
			Cube_Top_Right,
			{Side_Front, Side_Right},
			Layer_Back,
			Cube_Top_Right,
			{Side_Right, Side_Back}
		},
		{
			Layer_Front,
			Cube_Bottom_Left,
			{Side_Front, Side_Left},
			Layer_Front,
			Cube_Bottom_Right,
			{Side_Right, Side_Front}
		},
		{
			Layer_Front,
			Cube_Bottom_Right,
			{Side_Front, Side_Right},
			Layer_Back,
			Cube_Bottom_Right,
			{Side_Right, Side_Back}
		},
		{
			Layer_Back,
			Cube_Top_Left,
			{Side_Left, Side_Back},
			Layer_Front,
			Cube_Top_Left,
			{Side_Front, Side_Left}
		},
		{
			Layer_Back,
			Cube_Top_Right,
			{Side_Right, Side_Back},
			Layer_Back,
			Cube_Top_Left,
			{Side_Back, Side_Left}
		},
		{
			Layer_Back,
			Cube_Bottom_Left,
			{Side_Left, Side_Back},
			Layer_Front,
			Cube_Bottom_Left,
			{Side_Front, Side_Left}
		},
		{
			Layer_Back,
			Cube_Bottom_Right,
			{Side_Right, Side_Back},
			Layer_Back,
			Cube_Bottom_Left,
			{Side_Back, Side_Left}
		}
	},
	{
		{
			Layer_Front,
			Cube_Top_Left,
			{Side_Front, Side_Top},
			Layer_Back,
			Cube_Top_Left,
			{Side_Top, Side_Back}
		},
		{
			Layer_Front,
			Cube_Top_Right,
			{Side_Front, Side_Top},
			Layer_Back,
			Cube_Top_Right,
			{Side_Top, Side_Back}
		},
		{
			Layer_Front,
			Cube_Bottom_Left,
			{Side_Front, Side_Bottom},
			Layer_Front,
			Cube_Top_Left,
			{Side_Top, Side_Front}
		},
		{
			Layer_Front,
			Cube_Bottom_Right,
			{Side_Front, Side_Bottom},
			Layer_Front,
			Cube_Top_Right,
			{Side_Top, Side_Front}
		},
		{
			Layer_Back,
			Cube_Top_Left,
			{Side_Top, Side_Back},
			Layer_Back,
			Cube_Bottom_Left,
			{Side_Back, Side_Bottom}
		},
		{
			Layer_Back,
			Cube_Top_Right,
			{Side_Top, Side_Back},
			Layer_Back,
			Cube_Bottom_Right,
			{Side_Back, Side_Bottom}
		},
		{
			Layer_Back,
			Cube_Bottom_Left,
			{Side_Back, Side_Bottom},
			Layer_Front,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Front}
		},
		{
			Layer_Back,
			Cube_Bottom_Right,
			{Side_Back, Side_Bottom},
			Layer_Front,
			Cube_Bottom_Right,
			{Side_Bottom, Side_Front}
		}
	},
	{
		{
			Layer_Front,
			Cube_Top_Left,
			{Side_Front, Side_Top},
			Layer_Front,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Front}
		},
		{
			Layer_Front,
			Cube_Top_Right,
			{Side_Front, Side_Top},
			Layer_Front,
			Cube_Bottom_Right,
			{Side_Bottom, Side_Front}
		},
		{
			Layer_Front,
			Cube_Bottom_Left,
			{Side_Front, Side_Bottom},
			Layer_Back,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Back}
		},
		{
			Layer_Front,
			Cube_Bottom_Right,
			{Side_Front, Side_Bottom},
			Layer_Back,
			Cube_Bottom_Right,
			{Side_Bottom, Side_Back}
		},
		{
			Layer_Back,
			Cube_Top_Left,
			{Side_Top, Side_Back},
			Layer_Front,
			Cube_Top_Left,
			{Side_Front, Side_Top}
		},
		{
			Layer_Back,
			Cube_Top_Right,
			{Side_Top, Side_Back},
			Layer_Front,
			Cube_Top_Right,
			{Side_Front, Side_Top}
		},
		{
			Layer_Back,
			Cube_Bottom_Left,
			{Side_Back, Side_Bottom},
			Layer_Back,
			Cube_Top_Left,
			{Side_Top, Side_Back}
		},
		{
			Layer_Back,
			Cube_Bottom_Right,
			{Side_Back, Side_Bottom},
			Layer_Back,
			Cube_Top_Right,
			{Side_Top, Side_Back}
		}
			},
	{
		{
			Layer_Front,
			Cube_Top_Left,
			{Side_Left, Side_Top},
			Layer_Front,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Left},
		},
		{
			Layer_Front,
			Cube_Top_Right,
			{Side_Top, Side_Right},
			Layer_Front,
			Cube_Top_Left,
			{Side_Left, Side_Top}
		},
		{
			Layer_Front,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Left},
			Layer_Front,
			Cube_Bottom_Right,
			{Side_Right, Side_Bottom}
		},
		{
			Layer_Front,
			Cube_Bottom_Right,
			{Side_Right, Side_Bottom},
			Layer_Front,
			Cube_Top_Right,
			{Side_Top, Side_Right}
		},
		{
			Layer_Back,
			Cube_Top_Left,
			{Side_Left, Side_Top},
			Layer_Back,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Left},
		},
		{
			Layer_Back,
			Cube_Top_Right,
			{Side_Top, Side_Right},
			Layer_Back,
			Cube_Top_Left,
			{Side_Left, Side_Top}
		},
		{
			Layer_Back,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Left},
			Layer_Back,
			Cube_Bottom_Right,
			{Side_Right, Side_Bottom}
		},
		{
			Layer_Back,
			Cube_Bottom_Right,
			{Side_Right, Side_Bottom},
			Layer_Back,
			Cube_Top_Right,
			{Side_Top, Side_Right}
		}
	},
	{
		{
			Layer_Front,
			Cube_Top_Left,
			{Side_Left, Side_Top},
			Layer_Front,
			Cube_Top_Right,
			{Side_Top, Side_Right}
		},
		{
			Layer_Front,
			Cube_Top_Right,
			{Side_Top, Side_Right},
			Layer_Front,
			Cube_Bottom_Right,
			{Side_Right, Side_Bottom}
		},
		{
			Layer_Front,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Left},
			Layer_Front,
			Cube_Top_Left,
			{Side_Left, Side_Top}
		},
		{
			Layer_Front,
			Cube_Bottom_Right,
			{Side_Right, Side_Bottom},
			Layer_Front,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Left}
		},
		{
			Layer_Back,
			Cube_Top_Left,
			{Side_Left, Side_Top},
			Layer_Back,
			Cube_Top_Right,
			{Side_Top, Side_Right}
		},
		{
			Layer_Back,
			Cube_Top_Right,
			{Side_Top, Side_Right},
			Layer_Back,
			Cube_Bottom_Right,
			{Side_Right, Side_Bottom}
		},
		{
			Layer_Back,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Left},
			Layer_Back,
			Cube_Top_Left,
			{Side_Left, Side_Top}
		},
		{
			Layer_Back,
			Cube_Bottom_Right,
			{Side_Right, Side_Bottom},
			Layer_Back,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Left}
		}
	}
};

const Move faceEdgeMoves[6][12] =
{
	{
		{
			Layer_Front,
			Cube_Top,
			{Side_Front},
			Layer_Middle,
			Cube_Top_Left,
			{Side_Left}
		},
		{
			Layer_Front,
			Cube_Bottom,
			{Side_Front},
			Layer_Middle,
			Cube_Bottom_Left,
			{Side_Left}
		},
		{
			Layer_Middle,
			Cube_Top_Left,
			{Side_Left},
			Layer_Back,
			Cube_Top,
			{Side_Back}
		},
		{
			Layer_Middle,
			Cube_Top_Right,
			{Side_Right},
			Layer_Front,
			Cube_Top,
			{Side_Front}
		},
		{
			Layer_Middle,
			Cube_Bottom_Left,
			{Side_Left},
			Layer_Back,
			Cube_Bottom,
			{Side_Back}
		},
		{
			Layer_Middle,
			Cube_Bottom_Right,
			{Side_Right},
			Layer_Front,
			Cube_Bottom,
			{Side_Front}
		},
		{
			Layer_Back,
			Cube_Top,
			{Side_Back},
			Layer_Middle,
			Cube_Top_Right,
			{Side_Right}
		},
		{
			Layer_Back,
			Cube_Bottom,
			{Side_Back},
			Layer_Middle,
			Cube_Bottom_Right,
			{Side_Right}
		},
		{
			Layer_Front,
			Cube_Left,
			{Side_Left, Side_Front},
			Layer_Back,
			Cube_Left,
			{Side_Back, Side_Left}
		},
		{
			Layer_Front,
			Cube_Right,
			{Side_Front, Side_Right},
			Layer_Front,
			Cube_Left,
			{Side_Left, Side_Front}
		},

		{
			Layer_Back,
			Cube_Left,
			{Side_Left, Side_Back},
			Layer_Back,
			Cube_Right,
			{Side_Back, Side_Right}
		},
		{
			Layer_Back,
			Cube_Right,
			{Side_Right, Side_Back},
			Layer_Front,
			Cube_Right,
			{Side_Front, Side_Right}
		}
	},
	{
		{
			Layer_Front,
			Cube_Top,
			{Side_Front},
			Layer_Middle,
			Cube_Top_Right,
			{Side_Right}
		},
		{
			Layer_Front,
			Cube_Bottom,
			{Side_Front},
			Layer_Middle,
			Cube_Bottom_Right,
			{Side_Right}
		},
		{
			Layer_Middle,
			Cube_Top_Left,
			{Side_Left},
			Layer_Front,
			Cube_Top,
			{Side_Front}
		},
		{
			Layer_Middle,
			Cube_Top_Right,
			{Side_Right},
			Layer_Back,
			Cube_Top,
			{Side_Back}
		},
		{
			Layer_Middle,
			Cube_Bottom_Left,
			{Side_Left},
			Layer_Front,
			Cube_Bottom,
			{Side_Front}
		},
		{
			Layer_Middle,
			Cube_Bottom_Right,
			{Side_Right},
			Layer_Back,
			Cube_Bottom,
			{Side_Back}
		},
		{
			Layer_Back,
			Cube_Top,
			{Side_Back},
			Layer_Middle,
			Cube_Top_Left,
			{Side_Left}
		},
		{
			Layer_Back,
			Cube_Bottom,
			{Side_Back},
			Layer_Middle,
			Cube_Bottom_Left,
			{Side_Left}
		},
		{
			Layer_Front,
			Cube_Left,
			{Side_Left, Side_Front},
			Layer_Front,
			Cube_Right,
			{Side_Front, Side_Right}
		},
		{
			Layer_Front,
			Cube_Right,
			{Side_Front, Side_Right},
			Layer_Back,
			Cube_Right,
			{Side_Right, Side_Back}
		},
		{
			Layer_Back,
			Cube_Left,
			{Side_Left, Side_Back},
			Layer_Front,
			Cube_Left,
			{Side_Front, Side_Left}
		},
		{
			Layer_Back,
			Cube_Right,
			{Side_Right, Side_Back},
			Layer_Back,
			Cube_Left,
			{Side_Back, Side_Left}
		}
	},
	{
		{
			Layer_Front,
			Cube_Left,
			{Side_Front},
			Layer_Middle,
			Cube_Top_Left,
			{Side_Top}
		},
		{
			Layer_Front,
			Cube_Right,
			{Side_Front},
			Layer_Middle,
			Cube_Top_Right,
			{Side_Top}
		},
		{
			Layer_Middle,
			Cube_Top_Left,
			{Side_Top},
			Layer_Back,
			Cube_Left,
			{Side_Back}
		},
		{
			Layer_Middle,
			Cube_Top_Right,
			{Side_Top},
			Layer_Back,
			Cube_Right,
			{Side_Back}
		},
		{
			Layer_Middle,
			Cube_Bottom_Left,
			{Side_Bottom},
			Layer_Front,
			Cube_Left,
			{Side_Front}
		},
		{
			Layer_Middle,
			Cube_Bottom_Right,
			{Side_Bottom},
			Layer_Front,
			Cube_Right,
			{Side_Front}
		},
		{
			Layer_Back,
			Cube_Left,
			{Side_Back},
			Layer_Middle,
			Cube_Bottom_Left,
			{Side_Bottom}
		},
		{
			Layer_Back,
			Cube_Right,
			{Side_Back},
			Layer_Middle,
			Cube_Bottom_Right,
			{Side_Bottom}
		},
		{
			Layer_Front,
			Cube_Top,
			{Side_Front, Side_Top},
			Layer_Back,
			Cube_Top,
			{Side_Top, Side_Back}
		},
		{
			Layer_Front,
			Cube_Bottom,
			{Side_Front, Side_Bottom},
			Layer_Front,
			Cube_Top,
			{Side_Top, Side_Front}
		},
		{
			Layer_Back,
			Cube_Top,
			{Side_Top, Side_Back},
			Layer_Back,
			Cube_Bottom,
			{Side_Back, Side_Bottom}
		},
		{
			Layer_Back,
			Cube_Bottom,
			{Side_Back, Side_Bottom},
			Layer_Front,
			Cube_Bottom,
			{Side_Bottom, Side_Front}
		}
	},
	{
		{
			Layer_Front,
			Cube_Left,
			{Side_Front},
			Layer_Middle,
			Cube_Bottom_Left,
			{Side_Bottom}
		},
		{
			Layer_Front,
			Cube_Right,
			{Side_Front},
			Layer_Middle,
			Cube_Bottom_Right,
			{Side_Bottom}
		},
		{
			Layer_Middle,
			Cube_Top_Left,
			{Side_Top},
			Layer_Front,
			Cube_Left,
			{Side_Front}
		},
		{
			Layer_Middle,
			Cube_Top_Right,
			{Side_Top},
			Layer_Front,
			Cube_Right,
			{Side_Front}
		},
		{
			Layer_Middle,
			Cube_Bottom_Left,
			{Side_Bottom},
			Layer_Back,
			Cube_Left,
			{Side_Back}
		},
		{
			Layer_Middle,
			Cube_Bottom_Right,
			{Side_Bottom},
			Layer_Back,
			Cube_Right,
			{Side_Back}
		},
		{
			Layer_Back,
			Cube_Left,
			{Side_Back},
			Layer_Middle,
			Cube_Top_Left,
			{Side_Top}
		},
		{
			Layer_Back,
			Cube_Right,
			{Side_Back},
			Layer_Middle,
			Cube_Top_Right,
			{Side_Top}
		},
		{
			Layer_Front,
			Cube_Top,
			{Side_Front, Side_Top},
			Layer_Front,
			Cube_Bottom,
			{Side_Bottom, Side_Front}
		},
		{
			Layer_Front,
			Cube_Bottom,
			{Side_Front, Side_Bottom},
			Layer_Back,
			Cube_Bottom,
			{Side_Bottom, Side_Back}
		},
		{
			Layer_Back,
			Cube_Top,
			{Side_Top, Side_Back},
			Layer_Front,
			Cube_Top,
			{Side_Front, Side_Top}
		},
		{
			Layer_Back,
			Cube_Bottom,
			{Side_Back, Side_Bottom},
			Layer_Back,
			Cube_Top,
			{Side_Top, Side_Back}
		}
	},
	{
		{
			Layer_Front,
			Cube_Top,
			{Side_Top},
			Layer_Front,
			Cube_Left,
			{Side_Left}
		},
		{
			Layer_Front,
			Cube_Left,
			{Side_Left},
			Layer_Front,
			Cube_Bottom,
			{Side_Bottom}
		},
		{
			Layer_Front,
			Cube_Right,
			{Side_Right},
			Layer_Front,
			Cube_Top,
			{Side_Top}
		},
		{
			Layer_Front,
			Cube_Bottom,
			{Side_Bottom},
			Layer_Front,
			Cube_Right,
			{Side_Right}
		},
		{
			Layer_Back,
			Cube_Top,
			{Side_Top},
			Layer_Back,
			Cube_Left,
			{Side_Left}
		},
		{
			Layer_Back,
			Cube_Left,
			{Side_Left},
			Layer_Back,
			Cube_Bottom,
			{Side_Bottom}
		},
		{
			Layer_Back,
			Cube_Right,
			{Side_Right},
			Layer_Back,
			Cube_Top,
			{Side_Top}
		},
		{
			Layer_Back,
			Cube_Bottom,
			{Side_Bottom},
			Layer_Back,
			Cube_Right,
			{Side_Right}
		},
		{
			Layer_Middle,
			Cube_Top_Left,
			{Side_Left, Side_Top},
			Layer_Middle,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Left},
		},
		{
			Layer_Middle,
			Cube_Top_Right,
			{Side_Top, Side_Right},
			Layer_Middle,
			Cube_Top_Left,
			{Side_Left, Side_Top}
		},
		{
			Layer_Middle,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Left},
			Layer_Middle,
			Cube_Bottom_Right,
			{Side_Right, Side_Bottom}
		},
		{
			Layer_Middle,
			Cube_Bottom_Right,
			{Side_Right, Side_Bottom},
			Layer_Middle,
			Cube_Top_Right,
			{Side_Top, Side_Right}
		}
	},
	{
		{
			Layer_Front,
			Cube_Top,
			{Side_Top},
			Layer_Front,
			Cube_Right,
			{Side_Right}
		},
		{
			Layer_Front,
			Cube_Left,
			{Side_Left},
			Layer_Front,
			Cube_Top,
			{Side_Top}
		},
		{
			Layer_Front,
			Cube_Right,
			{Side_Right},
			Layer_Front,
			Cube_Bottom,
			{Side_Bottom}
		},
		{
			Layer_Front,
			Cube_Bottom,
			{Side_Bottom},
			Layer_Front,
			Cube_Left,
			{Side_Left}
		},
		{
			Layer_Back,
			Cube_Top,
			{Side_Top},
			Layer_Back,
			Cube_Right,
			{Side_Right}
		},
		{
			Layer_Back,
			Cube_Left,
			{Side_Left},
			Layer_Back,
			Cube_Top,
			{Side_Top}
		},
		{
			Layer_Back,
			Cube_Right,
			{Side_Right},
			Layer_Back,
			Cube_Bottom,
			{Side_Bottom}
		},
		{
			Layer_Back,
			Cube_Bottom,
			{Side_Bottom},
			Layer_Back,
			Cube_Left,
			{Side_Left}
		},
		{
			Layer_Middle,
			Cube_Top_Left,
			{Side_Left, Side_Top},
			Layer_Middle,
			Cube_Top_Right,
			{Side_Top, Side_Right}
		},
		{
			Layer_Middle,
			Cube_Top_Right,
			{Side_Top, Side_Right},
			Layer_Middle,
			Cube_Bottom_Right,
			{Side_Right, Side_Bottom}
		},
		{
			Layer_Middle,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Left},
			Layer_Middle,
			Cube_Top_Left,
			{Side_Left, Side_Top}
		},
		{
			Layer_Middle,
			Cube_Bottom_Right,
			{Side_Right, Side_Bottom},
			Layer_Middle,
			Cube_Bottom_Left,
			{Side_Bottom, Side_Left}
		}
	}
};

const Move faceCenterMoves[6][6] =
{
	{
		{
			Layer_Front,
			Cube_Center,
			{Side_Front},
			Layer_Middle,
			Cube_Left,
			{Side_Left}
		},
		{
			Layer_Middle,
			Cube_Left,
			{Side_Left},
			Layer_Back,
			Cube_Center,
			{Side_Back}
		},
		{
			Layer_Middle,
			Cube_Right,
			{Side_Right},
			Layer_Front,
			Cube_Center,
			{Side_Front}
		},
		{
			Layer_Back,
			Cube_Center,
			{Side_Back},
			Layer_Middle,
			Cube_Right,
			{Side_Right}
		},
		{
			Layer_Middle,
			Cube_Top,
			{Side_Top},
			Layer_Middle,
			Cube_Top,
			{Side_Top}
		},
		{
			Layer_Middle,
			Cube_Bottom,
			{Side_Bottom},
			Layer_Middle,
			Cube_Bottom,
			{Side_Bottom}
		}
	},
	{
		{
			Layer_Front,
			Cube_Center,
			{Side_Front},
			Layer_Middle,
			Cube_Right,
			{Side_Right}
		},
		{
			Layer_Middle,
			Cube_Left,
			{Side_Left},
			Layer_Front,
			Cube_Center,
			{Side_Front}
		},
		{
			Layer_Middle,
			Cube_Right,
			{Side_Right},
			Layer_Back,
			Cube_Center,
			{Side_Back}
		},
		{
			Layer_Back,
			Cube_Center,
			{Side_Back},
			Layer_Middle,
			Cube_Left,
			{Side_Left}
		},
		{
			Layer_Middle,
			Cube_Top,
			{Side_Top},
			Layer_Middle,
			Cube_Top,
			{Side_Top}
		}
		,
		{
			Layer_Middle,
			Cube_Bottom,
			{Side_Bottom},
			Layer_Middle,
			Cube_Bottom,
			{Side_Bottom}
		}
	},
	{
		{
			Layer_Front,
			Cube_Center,
			{Side_Front},
			Layer_Middle,
			Cube_Top,
			{Side_Top}
		},
		{
			Layer_Middle,
			Cube_Top,
			{Side_Top},
			Layer_Back,
			Cube_Center,
			{Side_Back}
		},
		{
			Layer_Middle,
			Cube_Bottom,
			{Side_Bottom},
			Layer_Front,
			Cube_Center,
			{Side_Front}
		},
		{
			Layer_Back,
			Cube_Center,
			{Side_Back},
			Layer_Middle,
			Cube_Bottom,
			{Side_Bottom}
		},
		{
			Layer_Middle,
			Cube_Left,
			{Side_Left},
			Layer_Middle,
			Cube_Left,
			{Side_Left}
		},
		{
			Layer_Middle,
			Cube_Right,
			{Side_Right},
			Layer_Middle,
			Cube_Right,
			{Side_Right}
		}
	},
	{
		{
			Layer_Front,
			Cube_Center,
			{Side_Front},
			Layer_Middle,
			Cube_Bottom,
			{Side_Bottom}
		},
		{
			Layer_Middle,
			Cube_Top,
			{Side_Top},
			Layer_Front,
			Cube_Center,
			{Side_Front}
		},
		{
			Layer_Middle,
			Cube_Bottom,
			{Side_Bottom},
			Layer_Back,
			Cube_Center,
			{Side_Back}
		},
		{
			Layer_Back,
			Cube_Center,
			{Side_Back},
			Layer_Middle,
			Cube_Top,
			{Side_Top}
		},
		{
			Layer_Middle,
			Cube_Left,
			{Side_Left},
			Layer_Middle,
			Cube_Left,
			{Side_Left}
		},
		{
			Layer_Middle,
			Cube_Right,
			{Side_Right},
			Layer_Middle,
			Cube_Right,
			{Side_Right}
		}
				},
	{
		{
			Layer_Middle,
			Cube_Top,
			{Side_Top},
			Layer_Middle,
			Cube_Left,
			{Side_Left}
		},
		{
			Layer_Middle,
			Cube_Left,
			{Side_Left},
			Layer_Middle,
			Cube_Bottom,
			{Side_Bottom}
		},
		{
			Layer_Middle,
			Cube_Right,
			{Side_Right},
			Layer_Middle,
			Cube_Top,
			{Side_Top}
		},
		{
			Layer_Middle,
			Cube_Bottom,
			{Side_Bottom},
			Layer_Middle,
			Cube_Right,
			{Side_Right}
		},
		{
			Layer_Front,
			Cube_Center,
			{Side_Front},
			Layer_Front,
			Cube_Center,
			{Side_Front}
		},
		{
			Layer_Back,
			Cube_Center,
			{Side_Back},
			Layer_Back,
			Cube_Center,
			{Side_Back}
		}
	},
	{
		{
			Layer_Middle,
			Cube_Top,
			{Side_Top},
			Layer_Middle,
			Cube_Right,
			{Side_Right}
		},
		{
			Layer_Middle,
			Cube_Left,
			{Side_Left},
			Layer_Middle,
			Cube_Top,
			{Side_Top}
		},
		{
			Layer_Middle,
			Cube_Right,
			{Side_Right},
			Layer_Middle,
			Cube_Bottom,
			{Side_Bottom}
		},
		{
			Layer_Middle,
			Cube_Bottom,
			{Side_Bottom},
			Layer_Middle,
			Cube_Left,
			{Side_Left}
		},
		{
			Layer_Front,
			Cube_Center,
			{Side_Front},
			Layer_Front,
			Cube_Center,
			{Side_Front}
		},
		{
			Layer_Back,
			Cube_Center,
			{Side_Back},
			Layer_Back,
			Cube_Center,
			{Side_Back}
		}
	}
};

const Side layerAlwaysMoves[3][2] =
{
	{ Side_Front, Side_Back },
	{ Side_Left, Side_Right },
	{ Side_Top, Side_Bottom }
};

const CubeAlwaysMove layerCubeAlwaysMoves[9] =
{
	{ Layer_Front, Cube_Center },
	{ Layer_Middle, Cube_Center },
	{ Layer_Back, Cube_Center },
	{ Layer_Middle, Cube_Left },
	{ Layer_Middle, Cube_Center },
	{ Layer_Middle, Cube_Right },
	{ Layer_Middle, Cube_Top },
	{ Layer_Middle, Cube_Center },
	{ Layer_Middle, Cube_Bottom }
};

const Side faceAlwaysMoves[3][2] =
{
	{ Side_Top, Side_Bottom },
	{ Side_Left, Side_Right },
	{ Side_Front, Side_Back }
};

const MoveIdx cubeTurnMoveIdxs[7] =
{
	MoveIdx_Y_Right,
	MoveIdx_Y_Left,
	MoveIdx_X_Down,
	MoveIdx_X_Up,
	MoveIdx_Z_Right,
	MoveIdx_Z_Left,
	MoveIdx_None
};

const int solveOrders[4][6][4] =
{
	{
		{
			0,
			1,
			2,
			3
		},
		{
			0,
			1,
			3,
			2
		},
		{
			0,
			3,
			2,
			1
		},
		{
			0,
			3,
			1,
			2
		},
		{
			0,
			2,
			1,
			3
		},
		{
			0,
			2,
			3,
			1
		},
	},
	{
		{
			1,
			2,
			3,
			0
		},
		{
			1,
			2,
			0,
			3
		},
		{
			1,
			0,
			3,
			2
		},
		{
			1,
			0,
			2,
			3
		},
		{
			1,
			3,
			0,
			2
		},
		{
			1,
			3,
			2,
			0
		}
	},
	{
		{
			2,
			3,
			0,
			1
		},
		{
			2,
			3,
			1,
			0
		},
		{
			2,
			1,
			0,
			3
		},
		{
			2,
			1,
			3,
			0
		},
		{
			2,
			0,
			1,
			3
		},
		{
			2,
			0,
			3,
			1
		}
	},
	{
		{
			3,
			0,
			1,
			2
		},
		{
			3,
			0,
			2,
			1
		},
		{
			3,
			2,
			1,
			0
		},
		{
			3,
			2,
			0,
			1
		},
		{
			3,
			1,
			0,
			2
		},
		{
			3,
			1,
			2,
			0
		}
	}
};

Color cubeColors[6][3][9][6];
Color crossCubeColors[6][4][6][3][9][6];
Color F2LCornerCubeColors[6][4][6][4][6][3][9][6];
Color F2LEdgeCubeColors[6][4][6][4][6][4][6][3][9][6];

Notation cubeRotationMoves[6];
Notation crossRotationMoves[6][4][6][4];
Notation F2LCornerRotationMoves[6][4][6][4][6][4];
Notation F2LEdgeRotationMoves[6][4][6][4][6][4][6][4];

Notation crossLayerMoves[6][4][6][4][4];
Notation F2LCornerLayerMoves[6][4][6][4][6][4][8];
Notation F2LEdgeLayerMoves[6][4][6][4][6][4][6][4][16];
Notation OLLCrossLayerMoves[6][4][6][4][6][4][6][3][6];
Notation OLLEdgeLayerMoves[6][4][6][4][6][4][6][16];
Notation PLLCycleLayerMoves[6][4][6][4][6][4][6][3][8];
Notation PLLOrientLayerMoves[6][4][6][4][6][4][6][4][4][5];

Notation moves[82944][263];