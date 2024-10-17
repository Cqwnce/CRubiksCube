#include <stdio.h>

char getCornerSticker(int cornerIndex, int stickerOrientation)
{
    // Define colors of each sticker of a corner cubies
    // Front (F) face is Green, Bottom (B) face is white
    char colors[8][3] = // 8 corner cubies, each have 3 stickers
        {
            /*index of each color based on reference facelets (Refer header.h)
            e.g color[0] is color of reference facelet relative to clean cube when orientation 0*/

            {'y', 'r', 'g'}, // ULF
            {'y', 'g', 'o'}, // UFR
            {'w', 'o', 'g'}, // DRF
            {'w', 'g', 'r'}, // DFL
            {'y', 'b', 'r'}, // UBL
            {'y', 'o', 'b'}, // URB
            {'w', 'b', 'o'}, // BDR
            {'w', 'r', 'b'}, // BDL
        };

    return colors[cornerIndex][stickerOrientation];
}

char getEdgeSticker(int edgeIndex, int stickerOrientation)
{
    // Define colors of each sticker of an edge cubie
    // Front (F) face is Green
    char colors[12][2] = // 12 edge cubies, each have 2 stickers
        {
            {'y', 'g'}, // UF
            {'g', 'o'}, // FR
            {'w', 'g'}, // DF
            {'g', 'r'}, // FL
            {'y', 'r'}, // UL
            {'y', 'o'}, // UR
            {'w', 'o'}, // DR
            {'w', 'r'}, // DL
            {'y', 'b'}, // UB
            {'b', 'o'}, // BR
            {'w', 'b'}, // BD
            {'b', 'r'}, // BL
        };

    return colors[edgeIndex][stickerOrientation];
}
