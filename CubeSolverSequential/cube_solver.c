#include "cube_solver.h"
#include "cube_printer.h"

void startSolve()
{
	turnCube(1, Direction_Up, false);
	cubeRotationMoves[1] = x;
	turnCube(2, Direction_Down, false);
	cubeRotationMoves[2] = xp;
	turnCube(3, Direction_Down, true);
	cubeRotationMoves[3] = x2;
	turnCube(4, Direction_Tilt_Left, false);
	cubeRotationMoves[4] = zp;
	turnCube(5, Direction_Tilt_Right, false);
	cubeRotationMoves[5] = z;
	solveCross();
	solveF2LCorner();
	solveF2LEdge();
	solveOLLCross();
	solveOLLEdge();
	solvePLLCycle();
	solvePLLOrient();
}

Color crossCubeColors[6][4][6][3][9][6];
Color edgeCubeColors[6][4][6][4][6][4][6][3][9][6];
Color cornerCubeColors[6][4][6][4][6][3][9][6];

void solve(const int cube[3][9][6])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				for (int l = 0; l < 6; l++)
				{
					cubeColors[i][j][k][l] = (Color)cube[j][k][l];
				}
			}
		}
	}
	startSolve();
	/*cudaMemcpyFromSymbol(edgeCubeColors, F2LEdgeCubeColors, sizeof(edgeCubeColors));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int l = 0; l < 6; l++)
				{
					printCube(edgeCubeColors[3][1][1][i][j][k][l]);
				}
			}
		}
	}*/
}