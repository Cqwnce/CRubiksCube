#include <stdio.h>
#include <stdbool.h>

#include "header.h"

void permuteCycle(int newCornerPositions[4], int newEdgePositions[4], int face,
        int newCornerOrientations[4], int newEdgeOrientations[4])
{
    // Temporary array to store indexes of modified Cubies
    int modifiedCorner[4] = {13, 13, 13, 13};
    int modifiedEdge[4] = {13, 13, 13, 13};

    // Update position index for corners and edges
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // Check if cubie was already modified
            if(checkModified(modifiedCorner, j))
            {
                continue;
            }

            // If corner cubie is IN POSITION of face being permutated
            if (corner_positions[face][i] == corners[j].position)
            {
                // Mark cubie as modified
                modifiedCorner[i] = j;

                // Update new position and orientation of cubie
                corners[j].position = newCornerPositions[i];
                corners[j].orientation = (corners[j].orientation + newCornerOrientations[i]) % 3;
                break;
            }
        };

        for (int j = 0; j < 12; j++)
        {
            // Check if cubie was already modified
            if(checkModified(modifiedEdge, j))
            {
                continue;
            }

            // If edge cubie is IN POSITION of face being permutated
            if (edge_positions[face][i] == edges[j].position)
            {
                // Mark cubie as modified
                modifiedEdge[i] = j;

                // Update new position and orientation of cubie
                edges[j].position = newEdgePositions[i];
                edges[j].orientation = (edges[j].orientation + newEdgeOrientations[i]) % 2;
                break;
            }
        };
    }
}

bool checkModified(int modifiedCubies[4], int j)
{
    for (int i = 0; i < 4; i++)
    {
        if (j == modifiedCubies[i])
        {
            return true;
        }
    }

    return false;
}

// F
void permuteF(void)
{
    int newCornerPositions[4] = {1, 2, 0, 3};
    int newCornerOrientations[4] = {1, 2, 2, 1};

    int newEdgePositions[4] = {1, 0, 2, 3};
    int newEdgeOrientations[4] = {1, 1, 1, 1};

    permuteCycle(newCornerPositions, newEdgePositions,
         2, newCornerOrientations, newEdgeOrientations);
}

void permuteFprime(void)
{
    int newCornerPositions[4] = {3, 0, 2, 1};
    int newCornerOrientations[4] = {1, 2, 2, 1};

    int newEdgePositions[4] = {3, 2, 0, 1};
    int newEdgeOrientations[4] = {1, 1, 1, 1};

    permuteCycle(newCornerPositions, newEdgePositions,
         2, newCornerOrientations, newEdgeOrientations);
}

// B
void permuteB(void)
{
    int newCornerPositions[4] = {4, 7, 5, 6};
    int newCornerOrientations[4] = {1, 2, 2, 1};

    int newEdgePositions[4] = {11, 8, 10, 9};
    int newEdgeOrientations[4] = {1, 1, 1, 1};

    permuteCycle(newCornerPositions, newEdgePositions,
         3, newCornerOrientations, newEdgeOrientations);
}

void permuteBprime(void)
{
    int newCornerPositions[4] = {6, 5, 7, 4};
    int newCornerOrientations[4] = {1, 2, 2, 1};

    int newEdgePositions[4] = {9, 10, 8, 11};
    int newEdgeOrientations[4] = {1, 1, 1, 1};

    permuteCycle(newCornerPositions, newEdgePositions,
         3, newCornerOrientations, newEdgeOrientations);
}

// U
void permuteU(void)
{
    int newCornerPositions[4] = {5, 1, 4, 0};
    int newCornerOrientations[4] = {0, 0, 0, 0};

    int newEdgePositions[4] = {5, 8, 0, 4};
    int newEdgeOrientations[4] = {0, 0, 0, 0};

    permuteCycle(newCornerPositions, newEdgePositions,
         0, newCornerOrientations, newEdgeOrientations);
}

void permuteUprime(void)
{
    int newCornerPositions[4] = {0, 4, 1, 5};
    int newCornerOrientations[4] = {0, 0, 0, 0};

    int newEdgePositions[4] = {4, 0, 8, 5};
    int newEdgeOrientations[4] = {0, 0, 0, 0};

    permuteCycle(newCornerPositions, newEdgePositions,
         0, newCornerOrientations, newEdgeOrientations);
}

// D
void permuteD(void)
{
    int newCornerPositions[4] = {2, 6, 3, 7};
    int newCornerOrientations[4] = {0, 0, 0, 0};

    int newEdgePositions[4] = {6, 2, 10, 7};
    int newEdgeOrientations[4] = {0, 0, 0, 0};

    permuteCycle(newCornerPositions, newEdgePositions,
         1, newCornerOrientations, newEdgeOrientations);
}

void permuteDprime(void)
{
    int newCornerPositions[4] = {7, 3, 6, 2};
    int newCornerOrientations[4] = {0, 0, 0, 0};

    int newEdgePositions[4] = {7, 10, 2, 6};
    int newEdgeOrientations[4] = {0, 0, 0, 0};

    permuteCycle(newCornerPositions, newEdgePositions,
         1, newCornerOrientations, newEdgeOrientations);
}

// L
void permuteL(void)
{
    int newCornerPositions[4] = {0, 3, 4, 7};
    int newCornerOrientations[4] = {1, 2, 2, 1};

    int newEdgePositions[4] = {3, 4, 7, 11};
    int newEdgeOrientations[4] = {0, 0, 0, 0};

    permuteCycle(newCornerPositions, newEdgePositions,
         4, newCornerOrientations, newEdgeOrientations);
}

void permuteLprime(void)
{
    int newCornerPositions[4] = {7, 4, 3, 0};
    int newCornerOrientations[4] = {1, 2, 2, 1};

    int newEdgePositions[4] = {11, 7, 4, 3};
    int newEdgeOrientations[4] = {0, 0, 0, 0};

    permuteCycle(newCornerPositions, newEdgePositions,
         4, newCornerOrientations, newEdgeOrientations);
}

// R
void permuteR(void)
{
    int newCornerPositions[4] = {5, 6, 1, 2};
    int newCornerOrientations[4] = {1, 2, 2, 1};

    int newEdgePositions[4] = {9, 5, 6, 1};
    int newEdgeOrientations[4] = {0, 0, 0, 0};

    permuteCycle(newCornerPositions, newEdgePositions,
         5, newCornerOrientations, newEdgeOrientations);
}

void permuteRprime(void)
{
    int newCornerPositions[4] = {2, 1, 6, 5};
    int newCornerOrientations[4] = {1, 2, 2, 1};

    int newEdgePositions[4] = {1, 6, 5, 9};
    int newEdgeOrientations[4] = {0, 0, 0, 0};

    permuteCycle(newCornerPositions, newEdgePositions,
         5, newCornerOrientations, newEdgeOrientations);
}



