
/*  Positions of corner cubies making up each face,
    indexed in a Z shape pattern. 
*/
int corner_positions[6][4] =
    {
        {4, 5, 0, 1}, // U (yellow) face
        {3, 2, 7, 6}, // D (white) face
        {0, 1, 3, 2}, // F (green) face
        {5, 4, 6, 7}, // B (blue) face
        {4, 0, 7, 3}, // L (red) face
        {1, 5, 2, 6}, // R (orange) face
};

/*  Positions of edge cubies making up each face,
    indexed in a ⭍ shape pattern. 
*/
int edge_positions[6][4] =
    {
        {8, 4, 5, 0},   // U (yellow) face
        {2, 7, 6, 10},  // D (white) face
        {0, 3, 1, 2},   // F (green) face
        {8, 9, 11, 10}, // B (blue) face
        {4, 11, 3, 7},  // L (red) face
        {5, 1, 9, 6},   // R (orange) face
};

// centers of each face
char centers[6] =
    {
        'y', 'w', 'g', 'b', 'r', 'o' // U, D, F, B, L, R
};

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

int adjustCornerOrientation(int cornerIndex, int orientation, int face)
{
    int orientationOffsets[6][4] = {

        // Adjustments for each face to get sticker
        {0, 0, 0, 0}, // U (yellow) face (no adjustment needed)
        {0, 0, 0, 0}, // D (white) face
        {2, 1, 1, 2}, // F (green) face
        {2, 1, 1, 2}, // B (blue) face
        {2, 1, 1, 2}, // L (red) face
        {2, 1, 1, 2}  // R (orange) face
    };

    return (orientation + orientationOffsets[face][cornerIndex]) % 3;
}

int adjustEdgeOrientation(int EdgeIndex, int orientation, int face)
{
    int orientationOffsets[6][4] = {

        // Adjustments for each face to get sticker
        {0, 0, 0, 0}, // U (yellow) face (no adjustment needed)
        {0, 0, 0, 0}, // D (white) face
        {1, 0, 0, 1}, // F (green) face
        {1, 0, 0, 1}, // B (blue) face
        {1, 1, 1, 1}, // L (red) face
        {1, 1, 1, 1}  // R (orange) face
    };

    int newOrientation = (orientation + orientationOffsets[face][EdgeIndex]) % 2;

    return newOrientation;
}
