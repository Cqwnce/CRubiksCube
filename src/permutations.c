#include <stdio.h>
#include <stdbool.h>

#include "header.h"

void permuteCycle(Cubie corners[8], Cubie edges[12], 
    int newCornerPositions[4], int newEdgePositions[4], int face,
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

void permuteF(Cubie corners[8], Cubie edges[12])
{
    int newCornerPositions[4] = {1, 2, 0, 3};
    int newCornerOrientations[4] = {1, 2, 2, 1};

    int newEdgePositions[4] = {1, 0, 2, 3};
    int newEdgeOrientations[4] = {1, 1, 1, 1};

    permuteCycle(corners, edges, newCornerPositions, newEdgePositions,
         2, newCornerOrientations, newEdgeOrientations);
}




