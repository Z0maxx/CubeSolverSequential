#include "cube_solver.h"
#include "sequence_processor.h"
#include "notation_translator.h"
#include "test_rotations.h"

int main(int argc, char* argv[])
{
    int idx = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                const char* a = argv[idx];
                testCubeColors[i][j][k] = atoi(a);
                
                idx++;
            }
        }
    }
    long long start = timeInMilliseconds();

    solve(testCubeColors);
    Notation const* sequence = findSequence();
    
    int count = 0;
    for (int i = 0; i < 263; i++)
    {
        if (sequence[i] != None)
        {
            count++;
            printf("%d ", sequence[i]);
        }
    }
    long long end = timeInMilliseconds();
    printf("%ld\n", end - start);
}
