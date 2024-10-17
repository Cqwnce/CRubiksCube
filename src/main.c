#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "header.h"

int main(int argc, char *argv[])
{

    // check for two command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./program print");
        return 0;
    }

    if (strcmp(argv[1], "print") == 0)
    {
        return 0;
    }

    // define cubies object, initialise all cubies to solved state
    CornerCubie corners[8] =
        {
            {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}
        };

    EdgeCubie edges[12] =
        {
            {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}, {10, 0}, {11, 0}
        };

}

void printCube(CornerCubie corners[8], EdgeCubie edges[12])
{
    int face = 0; // 0 indexed face, U
    printFace(corners[8], edges[12], face);
}