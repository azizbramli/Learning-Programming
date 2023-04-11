/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stdio.h>
#include <stdlib.h>

void                sapin_1(int size)
{
    int nb_spaces   = 4;
    int nb_stars    = 1;
    int pos         = 3;

    putchar('\n');
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < nb_spaces; k++) putchar(' ');
            for (int l = 0; l < nb_stars; l++) putchar('*');
            putchar('\n');
            nb_spaces--;
            nb_stars += 2;
        }
        nb_spaces = 4;
        nb_stars = 1;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < pos; j++) putchar(' ');
        for (int k = 0; k < 3; k++) putchar('|');
        putchar('\n');
    }
    putchar('\n');
}

void                sapin_2(int size)
{
    int stage       = 4;
    int base        = stage * size + 3;
    int nb_spaces   = base >> 1;
    int nb_stars    = 1;
    int width       = 0;
    int pos         = 0;

    putchar('\n');
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < stage; j++) {
            for (int k = 0; k < nb_spaces; k++) putchar(' ');
            for (int l = 0; l < nb_stars; l++) putchar('*');
            putchar('\n');
            nb_spaces--;
            nb_stars += 2;
        }
        nb_spaces += (stage - 1);
        stage++;
        nb_stars -= 2;
        nb_stars >>= 1;
    }
    width = (size << 1) - 1;
    pos = (base >> 1) - width + size;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < pos; j++) putchar(' ');
        for (int k = 0; k < width; k++) putchar('|');
        putchar('\n');
    }
    putchar('\n');
}

int                 main(int argc, char *argv[])
{
    int     size = strtoul(argv[1], NULL, 10);

    return 0;
}