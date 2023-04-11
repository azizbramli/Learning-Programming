/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include "bst.h"
#include "utilities.h"

int         main(int argc, char *argv[])
{
    t_node  *tree       = NULL;
    int     *nodes      = NULL;
    char    *args       = NULL;
    int     nb_nodes    = 0;
    int     depth       = 0;
    predicat p          = &compare;

    args        = strdup(argv[1]);
    nb_nodes    = count_nodes(args);
    printf("Number of nodes: %d\n", nb_nodes);

    nodes       = get_data(argv[1], nb_nodes);
    for (int i = 0; i < nb_nodes; i++) {
        insert(&tree, nodes[i], p);
    }

    depth = get_depth(tree);
    int length      = pow(2, depth) - 1;
    int **matrix    = allocate_2d(depth, length);
    matrix = get_level_trasversal(&tree, nb_nodes, depth);

    display_tree(depth, length, tree, matrix, argv[2]);

    //printf("\nDepth of the tree: %s%d%s\n", RED, depth, EMPTY);
    //printf("%s\nLevel by level trasversal: %s\n", PINK, EMPTY);
    /*
    printf("%s\n\nPrefix trasversal.%s\n\n", TCYAN, EMPTY);
    prefix(tree, NULL);
    printf("%s\n\nInfix trasversal.%s\n\n", TCYAN, EMPTY);
    infix(tree, NULL);
    printf("%s\n\nPostfix trasversal.%s\n\n", TCYAN, EMPTY);
    postfix(tree, NULL);
    printf("%s\n\nSearch function.%s\n", TCYAN, EMPTY);
    printf("Search element: %d\n", search(&tree, strtoul(argv[2], NULL, 10)));
    */

    free_bst(tree);
    tree = NULL;

    return 0;
}
