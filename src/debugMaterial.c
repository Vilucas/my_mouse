#include "dataStructure.h"

void printInputVar(input_t *ret)
{
    printf("matrix = %dx%d\n", ret->n, ret->m);
    printf("full '%c'\nempty '%c'\npath '%c'\nstartNode '%c'\nendNode '%c'\n", ret->full, ret->empty, ret->path, ret->startNode, ret->endNode);
}