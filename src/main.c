#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "helper.h"

// printCube prototype
void printCube(char cube[6][3][3]);

int main(int argc, char *argv[])
{

    rotateClockwiseF();

    // define cube as a 3d array, 3x3 grid with 6 faces
    // face 0: green/front | face 1: blue/back | face 2: red/left | face 3: orange/right | face 4: yellow/up | face 5: white/down
    char cube[6][3][3] = {
        // face 0: green / F
        {{'g', 'g', 'g'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}},

        // face 1: blue / B
        {{'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'}},

        // face 2: red / L
        {{'r', 'r', 'r'}, {'r', 'r', 'r'}, {'r', 'r', 'r'}},

        // face 3: orange / R
        {{'o', 'o', 'o'}, {'o', 'o', 'o'}, {'o', 'o', 'o'}},

        // face 4: yellow / U
        {{'y', 'y', 'y'}, {'y', 'y', 'y'}, {'y', 'y', 'y'}},

        // face 5: white / D
        {{'w', 'w', 'w'}, {'w', 'w', 'w'}, {'w', 'w', 'w'}}};

    if (strcmp(argv[1], "print") == 0)
    {
        printCube(cube);
    };

    return 0;
}

// Print (U) Top and (D) Bottom faces
void printFace(char face[3][3])
{
    for (int i = 0; i < 3; i++)
    {

        printf("      "); // Padding for the top/bottom face

        for (int j = 0; j < 3; j++)
        {
            printf("%c ", face[i][j]);
        }
        printf("\n");
    }
}

void printCube(char cube[6][3][3])
{

    printFace(cube[4]); // Print U face

    // Print the left (L), front (F), right (R), and back (B) faces
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
            printf("%c ", cube[2][i][j]); // L face
        printf("  ");                     // Spacing between faces

        for (int j = 0; j < 3; j++)
            printf("%c ", cube[0][i][j]); // F face
        printf("  ");                     // Spacing between faces

        for (int j = 0; j < 3; j++)
            printf("%c ", cube[3][i][j]); // R face
        printf("  ");                     // Spacing between faces

        for (int j = 0; j < 3; j++)
            printf("%c ", cube[1][i][j]); // B face
        printf("\n");
    };

    printFace(cube[5]); // Print D face
}
