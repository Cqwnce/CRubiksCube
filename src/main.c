#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#include "header.h"

#define MAX_SIZE 10

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

void clear_input_buffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void)
{
    printCube();

    char input[MAX_SIZE];
    int moves_number;

    // Intialise cube to be not scrambled
    bool scrambled = false;

    while (1) 
    {

        printf("Input a move to perform. (Type \"help\" for list of inputs): ");
    
        if (fgets(input, MAX_SIZE, stdin) != NULL)
        {
            size_t length = strlen(input);

            // Check if input exceed max size and is truncated
            if (length == MAX_SIZE - 1 && input[length - 1] != '\n')
            {
                printf("Invalid input.\n");
                clear_input_buffer();
                continue;
            }
            else
            {
                // Remove newline character
                input[strcspn(input, "\n")] = 0;
            }
        }

        size_t inputLength = strlen(input);
        
        if (strcmp(input, "help") == 0) 
        {
            printf("\n--------------------------------\n");
            printf("Moves:\n(F, B, U, D, L, R, M)\n");
            printf("\nModifiers:\n");
            printf("(') for counterclockwise e.g. F'.\n");
            printf("(2) for 2 moves e.g. F2.\n");
            printf("\nMiscellaneous:\n");
            printf("(end) to quit program.\n");
            printf("(scramble) to scrambling cube to solve.\n");
            printf("(reset) to reset cube to solved state.\n");
            printf("--------------------------------\n\n");
            continue; // Prompt for input again
        }

        if (strcmp(input, "end") == 0) 
        {
            break; // Exit the loop
        }

        if (strcmp(input, "scramble") == 0)
        {
            scrambleCube();
            scrambled = true;
            printCube();
            continue;
        }

        if (strcmp(input, "reset") == 0)
        {
            resetCube();
            printCube();
            continue;
        }

        if (inputLength == 1)
        {
            performMovesets(toupper(input[0]), '\0');
            printCube();

            if (checkSolved() == true && scrambled == true)
            {
                // only print "Cube solved" if cube was scrambled using command
                printf("Cube solved!\n");
                scrambled = false;
            }
            continue;
        } 
        else if (inputLength == 2)
        {
            if (input[1] == '2' || input[1] == '\'')
            {
                performMovesets(toupper(input[0]), input[1]);
                printCube();
                if (checkSolved() == true && scrambled == true)
                {
                    // only print "Cube solved" if cube was scrambled using command
                    printf("Cube solved!\n");
                    scrambled = false;
                }
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

bool checkSolved(void)
{
    for (int i = 0; i < 8; i++)
    {
        // return not solved if any corners not solved
        if (corners[i].position != i || corners[i].orientation != 0)
        {
            return false;
        }
    }

    for (int j = 0; j < 12; j++)
    {
        // return not solved if any edges not solved
        if (edges[j].position != j || edges[j].orientation != 0)
        {
            return false;
        }
    }

    // else, return true
    return true;
}

void scrambleCube(void)
{
    // randomise movesets to scramble cube
    srand(time(NULL));

    // number of moves to be performed randomly
    unsigned int movesetNumber = 20;

    char moves[6] = {'U', 'D', 'L', 'R', 'B', 'F'};
    char modifiers[3] = {'2', '\'', '\0'};

    for (int i = 0; i < movesetNumber; i++)
    {
        int random_move = rand() % 6;
        int random_modifier = rand() % 3;

        performMovesets(moves[random_move], moves[random_modifier]);
    }
}

void resetCube(void)
{
    // reset corners
    for (int i = 0; i < 8; i++)
    {
        corners[i].position = i;
        corners[i].orientation = 0;
    }

    // reset edges
    for (int j = 0; j < 12; j++)
    {
        edges[j].position = j;
        edges[j].orientation = 0;
    }

    // reset centers
    char defaultCenters[6] = {'y', 'w', 'g', 'b', 'r', 'o'};
    for (int k = 0; k < 6; k++)
    {
        centers[k] = defaultCenters[k];
    }
}
