#ifndef HEADER_H
#define HEADER_H

/* Define a Rubik's cube as a data structure combination of 6 fixed centers,
    8 corner cubies and 12 edge cubies.

    Orientation is based on reference facelets,
    as dictated in https://kociemba.org/math/cubielevel.htm

    (Colors have been changed such that F is green and U is yellow on a clean cube instead) */

// define 8 corner cubies, 0-7 indexed

typedef struct
{
    int p; /* POSITION OF CUBIE 0 = upper front left corner of green face (UFL), 1-3 clockwise,
                 4 = upper right back corner of green (front face is blue) (UBR), 5-7 clockwise. */

    int o; // ORIENTATION OF CUBIE 0 = correct orientation, 1 = twisted clockwise, 2 = twisted anticlockwise.
} CornerCubie;

// define 12 edge cubies, 0-11 indexed
typedef struct
{
    int p; /* POSITION OF CUBIE 0 = upper front edge of green face (UF), 1-3 going clockwise,
             4 = upper left  (UL), 5-7 going clockwise  8 = upper back (UB), 9-11 clockwise. */

    int o; // ORIENTATION OF CUBIE 0 = correct orientation, 1 = flipped
} EdgeCubie;

/*Positions of corner cubies making up each face,
    indexed in a Z shape pattern. */
int corner_positions[6][4] =
    {
        {4, 5, 0, 1}, // U (yellow) face
        {3, 2, 7, 6}, // D (white) face
        {0, 1, 3, 2}, // F (green) face
        {5, 4, 6, 7}, // B (blue) face
        {4, 0, 7, 3}, // L (red) face
        {1, 5, 2, 6}, // R (orange) face
};

/* Positions of edge cubies making up each face,
    indexed in a ⭍ shape pattern. */
int edge_positions[6][4] =
    {
        {8, 4, 5, 0},   // U (yellow) face
        {2, 7, 6, 10},  // D (white) face
        {0, 3, 1, 2},   // F (green) face
        {8, 9, 11, 10}, // B (blue) face
        {4, 7, 11, 3},  // L (red) face
        {5, 1, 9, 6},   // R (orange) face
};

// centers of each face
char centers[6] =
    {
        'y', 'w', 'g', 'b', 'r', 'o' // U, D, F, B, L, R
};

// Function prototypes
void printCube(CornerCubie corners[8], EdgeCubie edges[12]);

char getCornerSticker(int cornerIndex, int stickerOrientation);
char getEdgeSticker(int edgeIndex, int stickerOrientation);

#endif