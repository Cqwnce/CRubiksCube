
#ifndef HEADER_H
#define HEADER_H

/* Define a Rubik's cube as a data structure combination of 6 fixed centers,
*   8 corner cubies and 12 edge cubies.
*
*   Orientation is based on reference facelets,
*   as dictated in https://kociemba.org/math/cubielevel.htm
*
*   (Colors have been changed such that F is green and U is yellow on a clean cube instead) 
*/
    

typedef struct
{
    int position; /* 0-7 for corners| 0-12 for edges
                    indexed clockwise starting from UFL corner, GREEN(F) and YELLOW(U)*/ 

    int orientation; // 0,1,2 for corners| 0,1 for edges
} Cubie;

// Declare external arrays
extern int corner_positions[6][4];
extern int edge_positions[6][4];
extern char centers[6];

// Function prototypes
void printCube(Cubie corners[8], Cubie edges[12]);

char getCornerSticker(int cornerIndex, int stickerOrientation);
char getEdgeSticker(int edgeIndex, int stickerOrientation);
int adjustCornerOrientation(int cornerIndex, int orientation, int face);
int adjustEdgeOrientation(int EdgeIndex, int orientation, int face);

// Function prototype
void permuteF(Cubie corners[8], Cubie edges[12]);

void permuteCycle(Cubie corners[8], Cubie edges[12], 
    int newCornerPositions[4], int newEdgePositions[4], int face,
        int newCornerOrientations[4], int newEdgeOrientations[4]);
        
bool checkModified(int modifiedCubies[4], int j);


#endif