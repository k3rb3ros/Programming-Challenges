#ifndef LINES_H
#define LINES_H

#include <stdbool.h> //bool type
#include <stdio.h> //printf()

//define a struct for a 2d point
typedef struct 
{
   double x;
   double y;
} point;

typedef struct
{
   point p1;
   point p2;
} line;

#endif
