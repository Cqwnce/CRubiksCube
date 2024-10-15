#ifndef HEADER_H
#define HEADER_H

/* Define a Rubik's cube as a data structure combination of 6 fixed centers.
    8 corner cubies and 12 edge cubies*/

// define 8 corner cubies, 0-7 indexed
typedef struct
{
    int position;    /*0 = upper front left corner of green face (UFL), 1-3 clockwise,
                        4 = upper right back corner of green (front face is blue) (UBR), 5-7 clockwise*/
    int orientation; // 0 = correct orientation, 1 = twisted clockwise, 2 =  twisted anticlockwise
} CornerCubie;

// define 12 edge cubies, 0-11 indexed
typedef struct
{
    int position;    /*0 = upper front edge of green face (UF), 1-3 going clockwise,
                       4 = upper left middle (ULM), 5-7 going clockwise  8 = upper back (UB), 9-11 clockwise */
    int orientation; // 0 = correct orientation, 1 = flipped
} EdgeCubie;

// Function prototypes for sticker retrieval
char getCornerSticker(CornerCubie corner, int stickerFace);
char getEdgeSticker(EdgeCubie edge, int stickerFace);

#endif