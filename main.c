#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // define cube as a 3d array, 3x3 grid with 6 faces
    // face 0: green/front | face 1: blue/back | face 2: red/left | face 3: orange/right | face 4: yellow/up | face 5: white/down
    char cube[6][3][3] = {
        // face 0: green / F
        {
            {'g', 'g', 'g'}, 
            {'g', 'g', 'g'},
            {'g', 'g', 'g'}
        },

        // face 1: blue / B
        {
            {'b', 'b', 'b'}, 
            {'b', 'b', 'b'},
            {'b', 'b', 'b'}
        },

        // face 2: red / L
        {
            {'r', 'r', 'r'}, 
            {'r', 'r', 'r'},
            {'r', 'r', 'r'}
        },

        // face 3: orange / R
        {
            {'o', 'o', 'o'}, 
            {'o', 'o', 'o'},
            {'o', 'o', 'o'}
        },

        // face 4: yellow / U
        {
            {'y', 'y', 'y'}, 
            {'y', 'y', 'y'},
            {'y', 'y', 'y'}
        },

        // face 5: white / D
        {
            {'w', 'w', 'w'}, 
            {'w', 'w', 'w'},
            {'w', 'w', 'w'}
        }
    };

    
}
    