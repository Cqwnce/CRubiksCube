#include <stdio.h>
#include <stdbool.h>

#include "header.h"

void permuteCycle(const permuteIndex *perm, int face)
{
    // Map state of modification to cubies
    bool modifiedCorner[8] = {false};
    bool modifiedEdge[12] = {false};

    // Update position index for corners and edges
    for (int i = 0; i < 4; i++)
    {
        int currentCornerCubie = corner_positions[face][i];
        int currentEdgeCubie = edge_positions[face][i];

        for (int j = 0; j < 8; j++)
        {
            // Check if cubie was already modified
            if (modifiedCorner[j]) continue;

            // If corner cubie is IN POSITION of face being permutated
            if (currentCornerCubie == corners[j].position)
            {
                // Mark cubie as modified
                modifiedCorner[j] = true;

                // Update new position and orientation of cubie
                corners[j].position = perm->newCornerPositions[i];
                corners[j].orientation = (corners[j].orientation + perm->newCornerOrientations[i]) % 3;
                break;
            }
        };

        for (int j = 0; j < 12; j++)
        {
            // Check if cubie was already modified
            if (modifiedEdge[j]) continue;

            // If edge cubie is IN POSITION of face being permutated
            if (currentEdgeCubie == edges[j].position)
            {
                // Mark cubie as modified
                modifiedEdge[j] = true;

                // Update new position and orientation of cubie
                edges[j].position = perm->newEdgePositions[i];
                edges[j].orientation = (edges[j].orientation + perm->newEdgeOrientations[i]) % 2;
                break;
            }
        };
    }
}

void permuteCycleSlice(int newPositions[4], int orientationOffset)
{
    int oldPositions[4] = {0, 2, 8, 10};
    bool modifiedEdge[12] = {false};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            // Check if cubie was already modified
            if (modifiedEdge[j]) continue;

            // If edge cubie is IN POSITION, update edges
            if (edges[j].position == oldPositions[i])
            {
                modifiedEdge[j] = true;

                edges[j].position = newPositions[i];
                edges[j].orientation = (edges[j].orientation + orientationOffset) % 2;
                break;
            }

        }
    }
}


// F
void permuteF(void)
{
    permuteIndex permF =
        {
            {1, 2, 0, 3}, {1, 2, 2, 1}, {1, 0, 2, 3}, {1, 1, 1, 1}
        };

    permuteCycle(&permF, 2);
}

void permuteFprime(void)
{
    permuteIndex permFprime =
        {
            {3, 0, 2, 1}, {1, 2, 2, 1}, {3, 2, 0, 1}, {1, 1, 1, 1}
        };

    permuteCycle(&permFprime, 2);
}

void permuteF2(void)
{
    permuteIndex permF2 =
        {
            {2, 3, 1, 0}, {0, 0, 0, 0}, {2, 1, 3, 0}, {0, 0, 0, 0}
        };

    permuteCycle(&permF2, 2);
}

// B
void permuteB(void)
{
    permuteIndex permB =
        {
            {4, 7, 5, 6}, {1, 2, 2, 1}, {11, 8, 10, 9}, {1, 1, 1, 1}
        };

    permuteCycle(&permB, 3);
}

void permuteBprime(void)
{
    permuteIndex permBprime =
        {
            {6, 5, 7, 4}, {1, 2, 2, 1}, {9, 10, 8, 11}, {1, 1, 1, 1}
        };

    permuteCycle(&permBprime, 3);
}

void permuteB2(void)
{
    permuteIndex permB2 =
        {
            {7, 6, 4, 5}, {0, 0, 0, 0}, {10, 11, 9, 8}, {0, 0, 0, 0}
        };

    permuteCycle(&permB2, 3);
}

// U
void permuteU(void)
{
    permuteIndex permU =
        {
            {5, 1, 4, 0}, {0, 0, 0, 0}, {5, 8, 0, 4}, {0, 0, 0, 0}
        };

    permuteCycle(&permU, 0);
}

void permuteUprime(void)
{
    permuteIndex permUprime =
        {
            {0, 4, 1, 5}, {0, 0, 0, 0}, {4, 0, 8, 5}, {0, 0, 0, 0}
        };

    permuteCycle(&permUprime, 0);
}

void permuteU2(void)
{
    permuteIndex permU2 =
        {
            {1, 0, 5, 4}, {0, 0, 0, 0}, {0, 5, 4, 8}, {0, 0, 0, 0}
        };

    permuteCycle(&permU2, 0);
}

// D
void permuteD(void)
{
    permuteIndex permD =
        {
            {2, 6, 3, 7}, {0, 0, 0, 0}, {6, 2, 10, 7}, {0, 0, 0, 0}
        };

    permuteCycle(&permD, 1);
}

void permuteDprime(void)
{
    permuteIndex permDprime =
        {
            {7, 3, 6, 2}, {0, 0, 0, 0}, {7, 10, 2, 6}, {0, 0, 0, 0}
        };

    permuteCycle(&permDprime, 1);
}

void permuteD2(void)
{
    permuteIndex permD2 =
        {
            {6, 7, 2, 3}, {0, 0, 0, 0}, {10, 6, 7, 2}, {0, 0, 0, 0}
        };

    permuteCycle(&permD2, 1);
}

// L
void permuteL(void)
{
    permuteIndex permL =
        {
            {0, 3, 4, 7}, {1, 2, 2, 1}, {3, 4, 7, 11}, {0, 0, 0, 0}
        };

    permuteCycle(&permL, 4);
}

void permuteLprime(void)
{
    permuteIndex permL2 =
        {
            {7, 4, 3, 0}, {1, 2, 2, 1}, {11, 7, 4, 3}, {0, 0, 0, 0}
        };

    permuteCycle(&permL2, 4);
}

void permuteL2(void)
{
    permuteIndex permLprime =
        {
            {3, 7, 0, 4}, {0, 0, 0, 0}, {7, 3, 11, 4}, {0, 0, 0, 0}
        };

    permuteCycle(&permLprime, 4);
}

// R
void permuteR(void)
{
    permuteIndex permLprime =
        {
            {5, 6, 1, 2}, {1, 2, 2, 1}, {9, 5, 6, 1}, {0, 0, 0, 0}
        };

    permuteCycle(&permLprime, 5);
}

void permuteRprime(void)
{
    permuteIndex permLprime =
        {
            {2, 1, 6, 5}, {1, 2, 2, 1}, {1, 6, 5, 9}, {0, 0, 0, 0}
        };

    permuteCycle(&permLprime, 5);
}

void permuteR2(void)
{
    permuteIndex permLprime =
        {
            {6, 2, 5, 1}, {0, 0, 0, 0}, {6, 9, 1, 5}, {0, 0, 0, 0}
        };

    permuteCycle(&permLprime, 5);
}

// M (special slice move)
void permuteM(void)
{
    // swap centers in following order:
    // 2->0 | 0->3 | 1->2 | 3->1
    char temp;
    temp = centers[2];

    centers[2] = centers[0];
    centers[0] = centers[3];
    centers[3] = centers[1];
    centers[1] = temp;

    // swap edges
    int newPositions[4] = {2, 10, 0, 8};

    permuteCycleSlice(newPositions, 1);
}

void permuteMprime(void)
{
    // swap centers in following order:
    // 2->1 | 1->3 | 3->0 | 0->2 |
    char temp;
    temp = centers[2];

    centers[2] = centers[1];
    centers[1] = centers[3];
    centers[3] = centers[0];
    centers[0] = temp;

    // swap edges
    int newPositions[4] = {8, 0, 10, 2};

    permuteCycleSlice(newPositions, 1);
}

void permuteM2(void)
{
    // swap centers in following order:
    // 2->3 | 3->2 | 1->0 | 0->1 |
    char temp;

    temp = centers[2];
    centers[2] = centers[3];
    centers[3] = temp;

    temp = centers[1];
    centers[1] = centers[0];
    centers[0] = temp;

    // swap edges
    int newPositions[4] = {10, 8, 2, 0};

    permuteCycleSlice(newPositions, 0);
}
    



