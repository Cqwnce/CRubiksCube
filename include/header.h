
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

// struct for changing cubie position and orientation
typedef struct
{
    int newCornerPositions[4];
    int newCornerOrientations[4];
    int newEdgePositions[4];
    int newEdgeOrientations[4];
} permuteIndex;

// Declare external arrays
extern int corner_positions[6][4];
extern int edge_positions[6][4];
extern Cubie corners[8];
extern Cubie edges[12];
extern char centers[6];

// Function prototypes

// main.c
void printCube(void);
void performMovesets(char move, char modifier);
bool checkSolved(void);
void resetCube(void);
void scrambleCube(void);


// stickers.c
char getCornerSticker(int cornerIndex, int stickerOrientation);
char getEdgeSticker(int edgeIndex, int stickerOrientation);
int adjustCornerOrientation(int cornerIndex, int orientation, int face);
int adjustEdgeOrientation(int EdgeIndex, int orientation, int face);

// permutations.c
void permuteF(void);
void permuteFprime(void);
void permuteF2(void);

void permuteB(void);
void permuteBprime(void);
void permuteB2(void);

void permuteU(void);
void permuteUprime(void);
void permuteU2(void);

void permuteD(void);
void permuteDprime(void);
void permuteD2(void);

void permuteL(void);
void permuteLprime(void);
void permuteL2(void);

void permuteR(void);
void permuteRprime(void);
void permuteR2(void);

void permuteM(void);
void permuteMprime(void);
void permuteM2(void);

void permuteCycle(const permuteIndex *perm, int face);

#endif