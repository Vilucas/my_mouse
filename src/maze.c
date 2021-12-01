#include "dataStructure.h"
#define WALL -1
#define INF 2147483647
//m = colums
//n = rows


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

//creating array of areas that we have visited
int **createVisitedArray(input_t input, int *entry)
{
    int **cost = (int**)malloc(sizeof(int*) * input.m + 1);

    for(int i = 0; i < input.m; i++)
    {
        cost[i] = (int*)malloc(sizeof(int) * input.n + 1);
        for(int j = 0; j < input.n; j++)
        {
            cost[i][j] = INF;
        }
    }
    cost[entry[0]][entry[1]] = 0;
    return cost;
}

void breathSearch(char **parent, int **visited)
{

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
