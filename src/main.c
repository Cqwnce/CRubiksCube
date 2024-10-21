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
        printf("Usage: ./rubiks_cube print");
        return 0;
    }

    // define cubies object, initialise all cubies to solved state
    CornerCubie corners[8] =
        {
            {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}};

    EdgeCubie edges[12] =
        {
            {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}, {10, 0}, {11, 0}};

    if (strcmp(argv[1], "print") == 0)
    {
        printCube(corners, edges);
        return 0;
    }
}

void printFace(CornerCubie corners[8], EdgeCubie edges[12], int face, bool newLine)
{
    // loop through each CORNER and EDGE POSITIONS of the FACE (each face has 4 corners)
    for (int i = 0; i < 4; i++)
    {
        // get CORNER and EDGE POSITION making up the CURRENT FACE (index "face" of corner_positions 2d array)
        int faceCornerPosition = corner_positions[face][i];
        int faceEdgePosition = edge_positions[face][i];

        // loop through each cornerCubies (j)
        for (int j = 0; j < 8; j++)
        {
            // Check if CORNER Cubie is in position of current Face
            if (corners[j].position == faceCornerPosition)
            {
                // Print sticker color of cubie, depending on orientation
                char color = getCornerSticker(j, corners[j].orientation);
                printf("%c", color);
                break;
            };
        };

        // Formatting
        printf(" ");

        // Special case for middle row 
        if (i == 1)
        {
            printf("\n");

            for (int k = 0; k < 12; k++)
            {
                // Check if EDGE Cubie is in position of current Face
                if (edges[k].position == faceEdgePosition)
                {
                    // Print sticker color of cubie, depending on orientation
                    char color = getEdgeSticker(k, edges[k].orientation);
                    printf("%c", color);
                    break;
                };
            };

            printf(" ");

            // Print center
            printf("%c ", centers[face]);

            for (int k = 0; k < 12; k++)
            {
                // Check if EDGE Cubie is in position 2 of current Face
                if (edges[k].position == edge_positions[face][2])
                {
                    // Print sticker color of cubie, depending on orientation
                    char color = getEdgeSticker(k, edges[k].orientation);
                    printf("%c", color);
                };
            };
            printf("\n");
            continue;
        };

        // loop through each edgeCubies (k)
        for (int k = 0; k < 12; k++)
        {
            // Check if EDGE Cubie is in position of current Face
            if (edges[k].position == faceEdgePosition)
            {
                // Print sticker color of cubie, depending on orientation
                char color = getEdgeSticker(k, edges[k].orientation);
                printf("%c", color);
                break;
            };
        };

        // Formatting
        printf(" ");

    };
}

void printCube(CornerCubie corners[8], EdgeCubie edges[12])
{
    // 0 indexed face, U
    printFace(corners, edges, 0, true);
}