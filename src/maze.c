#include "dataStructure.h"
#define WALL -1
#define INF 2147483647
//m = colums
//n = rows
/*
int breathSearch(int start[2],)
{

}
*//*
int **createVisitedArray(input_t input, char entry[2])
{
    int **ret = (int**)malloc(sizeof(int*) * input.m);
    if (!ret)
        return NULL;
    for (int i = 0; i < input.m; i++)
    {
        if ((ret[i] = (char*)malloc(sizeof(char) * input.n)) == NULL)
            exit(-1);
        ret[]

    }
    
}*/

char **createParrentArray(int fd, input_t input)
{
    char **ret = (char**)malloc(sizeof(char*) * input.m + 1);
    char *line;

    if (!ret)
        return NULL;
    for (int i =0; i < input.m; i++)
    {
        getNextLine(fd, &line);
        if ((ret[i] = (char*)malloc(sizeof(char) * (input.n + 1))) == NULL)
            exit(-1);
        strcpy(ret[i], line);
    }
    ret[input.m] = NULL;
    return ret;
}

int goThroughTheMap(input_t input, char *map)
{
    char *line = NULL;
    int fd = open(map, O_RDONLY);

    int entry[2] = {0,0};
    getNextLine(fd, &line);
    char *padding = strchr(line, input.startNode);
    entry[1] = strlen(line) - strlen(padding);
    //------------------------------------------------
    char **parent = createParrentArray(fd, input);
    (void)parent;
    int  **visited = createVisitedArray(input, entry);
    //------------------------------------------------
    //breathSearch(entry);
    return 0;
}