/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#ifndef _BST_H_
#define _BST_H_

#include <stdbool.h>
#include "structs.h"

typedef bool (*predicat)(int, int);

void    free_bst(t_node *);
int     get_depth(t_node*);
void    infix(t_node *, int (*f)(int));
void    insert(t_node **, int, predicat);
void    postfix(t_node *, int (*f)(int));
void    prefix(t_node *, int (*f)(int));
int     search(t_node **, int);

#endif
