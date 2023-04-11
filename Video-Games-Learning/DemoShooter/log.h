/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#ifndef _LOG_H_
#define _LOG_H_

#include <stdio.h>

void    log_error(FILE *, char *, const char *, void (*) (void));

#endif