/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

static int head        = 0;
static int tail        = 0;
static int nb_elements = 0;

int     **allocate_2d(int height, int width)
{
    int **matrix = calloc(height, sizeof(int *));

    for (int i = 0; i < height; i++) {
        matrix[i] = calloc(width, sizeof(int));
    }

    return matrix;
}

bool    compare(int a, int b)
{
    return a < b;
}

int     count_nodes(char *elements)
{
    char    *token      = NULL;
    int     nb_nodes    = 0;

    token   = strtok(elements, " ");
    while(token != NULL) {
        nb_nodes++;
        token = strtok(NULL, " ");
    }
    return nb_nodes;
}

int      *get_data(char *elements, int size)
{
    char    *token  = NULL;
    int     *nodes  = NULL;
    int     i       = 0;

    nodes   = calloc(size, sizeof(int));
    token   = strtok(elements, " ");
    while(token != NULL) {
        nodes[i++] = strtoul(token, NULL, 10);
        token = strtok(NULL, " ");
    }
    return nodes;
}

void        push(t_node *queue, t_node *elem, int size) {
    if (nb_elements < size) {
        if (elem != NULL) {
            queue[head++] = *elem;
        } else {
            queue[head++].elem  = -1;
        }
        nb_elements++;
    }
    head = (head >= size) ? 0 : head;
}

t_node      pop(t_node *queue, int size) {
    t_node  elem;

    if (nb_elements > 0) {
        elem = queue[tail++];
        nb_elements--;
    }
    tail = (tail >= size) ? 0 : tail;
    return elem;
}

int         **get_level_trasversal(t_node **root, int nb_nodes, int depth)
{
    t_node  *queue      = calloc(nb_nodes, sizeof(t_node));
    t_node  *node       = calloc(1, sizeof(t_node));
    int     length      = pow(2, depth) - 1;
    int     **matrix    = allocate_2d(depth, length);
    int     row         = 0;
    int     col         = 0;

    matrix[0][0] = (*root)->elem;
    row++;
    col = 0;
    push(queue, *root, nb_nodes);
    push(queue, NULL, nb_nodes);
    for (int i = 0; i < nb_nodes; i++) {
        *node = queue[tail];
        pop(queue, nb_nodes);
        if (node->elem == -1) {
           push(queue, NULL, nb_nodes);
           row++;
           col = 0;
        } else {
            if(node->left != NULL) {
                push(queue, node->left, nb_nodes);
                matrix[row][col++] = node->left->elem;
            }
            if(node->right != NULL) {
                push(queue, node->right, nb_nodes);
                matrix[row][col++] = node->right->elem;
            }
        }
    }
    return matrix;
}
