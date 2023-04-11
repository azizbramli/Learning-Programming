/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stdlib.h>
#include "log.h"

void    log_error(FILE *stream, char *message, const char *sdl_error, void (*f) (void)) {
  fprintf(stream, "%s error: %s\n", message, sdl_error);
  if (f != NULL) {
    atexit(f);
  }
  exit(EXIT_FAILURE);
}
