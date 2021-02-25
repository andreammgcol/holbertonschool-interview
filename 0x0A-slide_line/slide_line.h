#ifndef SLIDE_H
#define SLIDE_H

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void left(int *line, size_t size);
void right(int *line, size_t size);

#endif
