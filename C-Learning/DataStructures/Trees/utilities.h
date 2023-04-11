/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <stdbool.h>
#include "structs.h"

int     **allocate_2d(int, int);
int     count_nodes(char *);
void    display_tree(int, int, t_node *, int **, char *);
bool    compare(int, int);
int     *get_data(char *, int);
int     **get_level_trasversal(t_node **, int, int);

#endif
