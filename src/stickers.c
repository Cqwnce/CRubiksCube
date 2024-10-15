#include <stdio.h>
#include "header.h"

char getCornerSticker(CornerCubie corner, int stickerFace)
{
    // Define colors of each sticker of a corner cubies
    // Front (F) face is Green
    char colors[8][3] = // 8 corner cubies, each have 3 stickers
        {
            {'g', 'y', 'r'}, // FUL
            {'g', 'y', 'o'}, // FUR
            {'g', 'w', 'r'}, // FDL
            {'g', 'w', 'o'}, // FDR
            {'b', 'y', 'r'}, // BUL
            {'b', 'y', 'o'}, // BUR
            {'b', 'w', 'r'}, // BDL
            {'b', 'w', 'o'}, // BDL
        };

    return 0;
};

char getEdgeSticker(EdgeCubie edge, int stickerFace)
{
    // Define colors of each sticker of an edge cubie
    // Front (F) face is Green
    char colors[12][2] = // 12 edge cubies, each have 2 stickers
        {
            {'g', 'y'}, // FU
            {'g', 'o'}, // FR
            {'g', 'w'}, // FD
            {'g', 'r'}, // FL
            {'y', 'r'}, // MUL
            {'y', 'o'}, // MUR
            {'w', 'o'}, // MDR
            {'w', 'r'}, // MDL
            {'b', 'y'}, // BU
            {'b', 'o'}, // BR
            {'b', 'w'}, // BD
            {'b', 'r'}, // BL
        };
    return 0;
};