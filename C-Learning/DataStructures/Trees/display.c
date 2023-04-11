/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "utilities.h"

void        display_queue(t_node *queue, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[i].elem);
    }
}

void        display_level(int *level, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", level[i]);
    }
}

void        display_matrix_h(int heigth, int length, int **matrix) {
    for (int i = 0; i < heigth; i++) {
        for (int j = 0; j < length; j++) {
            if (matrix[i][j] != 0) {
                printf("%s%d%s", BLUE, matrix[i][j], EMPTY);
            } else {
                printf("%s%s%s", EMPTY, " ", EMPTY);
            }
        }
        printf("\n\n");
    }
}

void        display_matrix_v(int heigth, int length, int **matrix) {
    for (int i = 0; i < heigth; i++) {
        for (int j = 0; j < length; j++) {
            if (matrix[i][j] != 0) {
                printf("%s|%d|%s", BLUE, matrix[i][j], EMPTY);
            } else {
                printf("%s%s%s", EMPTY, "\t", EMPTY);
            }
        }
        printf("\n");
    }
}

int         get_coordinates(int elem, t_node *tree, int n, int in_off) {
    if (tree->elem == elem) {
        return n;
    } else if (elem < tree->elem) {
        return get_coordinates(elem, tree->left, n - (in_off + 1), in_off / 2);
    } else {
        return get_coordinates(elem, tree->right, n + (in_off + 1), in_off / 2);
    }
}

void        display_tree(int depth, int length, t_node *tree, int **matrix, char *mode) {
    int     **m_h       = allocate_2d(depth, length);
    int     **m_v       = allocate_2d(length, depth);
    int     init_offset = pow(2, (depth * 2 - 1) / 2) - 1;
    int     new_offset  = init_offset;

    m_h[0][init_offset] = tree->elem;
    for (int i = 1; i < depth; i++) {
        for (int j = 0; matrix[i][j] != 0 && j < length; j++) {
            int elem    = matrix[i][j];
            int x       = get_coordinates(elem, tree, init_offset, new_offset / 2);
            m_h[i][x]   = elem;
        }
    }
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < length; j++) {
            m_v[j][i] = m_h[i][j];
        }
    }
    if (strncmp(mode, "h", 1) == 0) {
        display_matrix_h(depth, length, m_h);
    } else {
        display_matrix_v(length, depth, m_v);
    }
}
