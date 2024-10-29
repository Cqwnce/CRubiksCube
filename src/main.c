#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "header.h"

// define cubies object, initialise all cubies to solved state
Cubie corners[8] =
    {
        {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}
    };

Cubie edges[12] =
    {
        {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}, {10, 0}, {11, 0}
    };

// centers of each face, initialised to solved state
char centers[6] =
    {
        'y', 'w', 'g', 'b', 'r', 'o' // U, D, F, B, L, R
};


int main(void)
{
    printCube();

    char input[10];

    while (1) 
    {
        printf("Input a move to perform. (Type \"help\" for list of inputs): ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "help") == 0) 
        {
            printf("\n--------------------------------\n");
            printf("Moves:\n(F, B, U, D, L, R, M)\n");
            printf("\nModifiers:\n");
            printf("(') for counterclockwise e.g. F'.\n");
            printf("(2) for 2 moves e.g. F2.\n");
            printf("\nMiscellaneous:\n");
            printf("(end) for quitting program.\n");
            printf("--------------------------------\n\n");
            continue; // Prompt for input again
        }

        if (strcmp(input, "end") == 0) 
        {
            break; // Exit the loop
        }

        if (strlen(input) == 1)
        {
            performMovesets(toupper(input[0]), '\0');
            printCube();
            continue;
        } 
        else if (strlen(input) == 2)
        {
            if (input[1] == '2' || input[1] == '\'')
            {
                performMovesets(toupper(input[0]), input[1]);
                printCube();
                continue;
            }
        }
        printf("Invalid input.\n");
    }

    return 0;
}

void printFirstRow(int face)
{
    int i = 0;

    // get CORNER and EDGE POSITION making up the CURRENT FACE (index "face" of corner_positions 2d array)
    int faceCornerPosition = corner_positions[face][i];
    int faceEdgePosition = edge_positions[face][i];

    // loop through each Corner Cubies (j)
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

    // loop through each Edge Cubies (k)
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

void printSecondRow(int face)
{
    // loop through each Edge Cubies (k)
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

void printThirdRow(int face)
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

void printCube(void)
{
    // 0 indexed face, U
    printf("      ");
    printFirstRow(0);
    printf("\n");
    printf("      ");
    printSecondRow(0);
    printf("\n");
    printf("      ");
    printThirdRow(0);
    printf("\n");

    // 4, 2, 5, 3 face (L, F, R, B)

    // First row
    printFirstRow(4);
    printFirstRow(2);
    printFirstRow(5);
    printFirstRow(3);
    printf("\n");

    // Second row
    printSecondRow(4);
    printSecondRow(2);
    printSecondRow(5);
    printSecondRow(3);
    printf("\n");

    // Third row
    printThirdRow(4);
    printThirdRow(2);
    printThirdRow(5);
    printThirdRow(3);
    printf("\n");

    // 1 indexed face, D
    printf("      ");
    printFirstRow(1);
    printf("\n");
    printf("      ");
    printSecondRow(1);
    printf("\n");
    printf("      ");
    printThirdRow(1);
    printf("\n");
}

void performMovesets(char move, char modifier)
{
    // Switch case for face of move
    switch (move)
    {
        case 'F':
            if (modifier == '2')
            {
                permuteF2();
            }
            else if (modifier == '\'')
            {
                permuteFprime();
            }
            else
            {
                permuteF();
            }
            break;

        case 'B':
            if (modifier == '2')
            {
                permuteB2();
            }
            else if (modifier == '\'')
            {
                permuteBprime();
            }
            else
            {
                permuteB();
            }
            break;

        case 'U':
            if (modifier == '2')
            {
                permuteU2();
            }
            else if (modifier == '\'')
            {
                permuteUprime();
            }
            else
            {
                permuteU();
            }
            break;

        case 'D':
            if (modifier == '2')
            {
                permuteD2();
            }
            else if (modifier == '\'')
            {
                permuteDprime();
            }
            else
            {
                permuteD();
            }
            break;

        case 'L':
            if (modifier == '2')
            {
                permuteL2();
            }
            else if (modifier == '\'')
            {
                permuteLprime();
            }
            else
            {
                permuteL();
            }
            break;
            
        case 'R':
            if (modifier == '2')
            {
                permuteR2();
            }
            else if (modifier == '\'')
            {
                permuteRprime();
            }
            else
            {
                permuteR();
            }
            break;

        case 'M':
            if (modifier == '2')
            {
                permuteM2();
            }
            else if (modifier == '\'')
            {
                permuteMprime();
            }
            else
            {
                permuteM();
            }
            break;


        default:
            printf("Invalid move.\n");
            break;
    };
}

