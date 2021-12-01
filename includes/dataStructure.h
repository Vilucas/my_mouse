#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define VERBOSE 1
#define WRONG_INPUT -1


typedef struct s_input 
{
    int n;
    int m;
    int full;
    int empty;
    int path;
    int startNode;
    int endNode;
} input_t;


typedef struct  s_vector 
{
    int ok;
}               vector_t;

typedef struct  s_visited
{
    vector_t            path;
    struct s_visited    *next;
}               visited_t;

typedef struct steps_l{
    int x_curr;
    int y_curr;
    int y_prev;
    int x_prev;
    //int layer;
    struct steps_l *next;
} steps;

void            printInputVar(input_t *ret);
int             getNextLine(int fd, char **line);
int             goThroughTheMap(input_t input, char *map);

#endif