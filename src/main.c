#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "header.h"

int main(int argc, char *argv[])
{

    // check for two command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./program print");
        return 0;
    }

    if (strcmp(argv[1], "print") == 0)
    {
        return 0;
    }

    // define cube object
    CornerCubie corners[8];
    EdgeCubie edges[12];
}