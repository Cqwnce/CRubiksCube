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

void printFirstRow(CornerCubie corners[8], EdgeCubie edges[12], int face)
{
    int i = 0;

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
            char color = getCornerSticker(j, adjustCornerOrientation(i, corners[j].orientation, face));
            printf("%c ", color);
            break;
        };
    };

    // loop through each edgeCubies (k)
    for (int k = 0; k < 12; k++)
    {
        // Check if EDGE Cubie is in position of current Face
        if (edges[k].position == faceEdgePosition)
        {
            // Print sticker color of cubie, depending on orientation
            char color = getEdgeSticker(k, adjustEdgeOrientation(i, edges[k].orientation, face));
            printf("%c ", color);
            break;
        };
    };

    // for i + 1
    i++;
    faceCornerPosition = corner_positions[face][i];
    for (int j = 0; j < 8; j++)
    {
        // Check if CORNER Cubie is in position of current Face
        if (corners[j].position == faceCornerPosition)
        {
            // Print sticker color of cubie, depending on orientation
            char color = getCornerSticker(j, adjustCornerOrientation(i, corners[j].orientation, face));
            printf("%c ", color);
            break;
        };
    };
}

void printSecondRow(CornerCubie corners[8], EdgeCubie edges[12], int face)
{
    
    // loop through each edgeCubies (k)
    for (int i = 1; i <= 2; i++)
    {
        int faceEdgePosition = edge_positions[face][i];

        for (int k = 0; k < 12; k++)
        {
            // Check if EDGE Cubie is in position of current Face
            if (edges[k].position == faceEdgePosition)
            {
                // Print sticker color of cubie, depending on orientation
                char color = getEdgeSticker(k, adjustEdgeOrientation(i, edges[k].orientation, face));
                printf("%c ", color);
                break;
            };
        };

        if (i == 1)
        {
            printf("%c ", centers[face]);
        }
    }
}

void printThirdRow(CornerCubie corners[8], EdgeCubie edges[12], int face)
{
    int i = 2;
    int faceCornerPosition = corner_positions[face][i];

    for (int j = 0; j < 8; j++)
    {
        // Check if CORNER Cubie is in position of current Face
        if (corners[j].position == faceCornerPosition)
        {
            // Print sticker color of cubie, depending on orientation
            char color = getCornerSticker(j, adjustCornerOrientation(i, corners[j].orientation, face));
            printf("%c ", color);
            break;
        };
    };

    i++;
    int faceEdgePosition = edge_positions[face][i];

    for (int k = 0; k < 12; k++)
    {
        // Check if EDGE Cubie is in position of current Face
        if (edges[k].position == faceEdgePosition)
        {
            // Print sticker color of cubie, depending on orientation
            char color = getEdgeSticker(k, adjustEdgeOrientation(i, edges[k].orientation, face));
            printf("%c ", color);
            break;
        };
    };

    faceCornerPosition = corner_positions[face][i];

    for (int j = 0; j < 8; j++)
    {
        // Check if CORNER Cubie is in position of current Face
        if (corners[j].position == faceCornerPosition)
        {
            // Print sticker color of cubie, depending on orientation
            char color = getCornerSticker(j, adjustCornerOrientation(i, corners[j].orientation, face));
            printf("%c ", color);
            break;
        };
    };

}

void printCube(CornerCubie corners[8], EdgeCubie edges[12])
{
    // 0 indexed face, U
    printf("      ");
    printFirstRow(corners, edges, 0);
    printf("\n");
    printf("      ");
    printSecondRow(corners, edges, 0);
    printf("\n");
    printf("      ");
    printThirdRow(corners, edges, 0);
    printf("\n");

    // 4, 2, 5, 3 face (L, F, R, B)

    // First row
    printFirstRow(corners, edges, 4);
    printFirstRow(corners, edges, 2);
    printFirstRow(corners, edges, 5);
    printFirstRow(corners, edges, 3);
    printf("\n");

    // Second row
    printSecondRow(corners, edges, 4);
    printSecondRow(corners, edges, 2);
    printSecondRow(corners, edges, 5);
    printSecondRow(corners, edges, 3);
    printf("\n");

    // Third row
    printThirdRow(corners, edges, 4);
    printThirdRow(corners, edges, 2);
    printThirdRow(corners, edges, 5);
    printThirdRow(corners, edges, 3);
    printf("\n");

    // 1 indexed face, D
    printf("      ");
    printFirstRow(corners, edges, 1);
    printf("\n");
    printf("      ");
    printSecondRow(corners, edges, 1);
    printf("\n");
    printf("      ");
    printThirdRow(corners, edges, 1);
    printf("\n");
}