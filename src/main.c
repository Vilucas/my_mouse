
#include "dataStructure.h"
#define READ_PACE 50


//get input from the user and store the variables in the input_t struct instance
int processRawInput(char **av, input_t *ret)
{
    char *BUFF = (char*)malloc(sizeof(char) * READ_PACE + 1);
    int fd = 0;
    int bitRead = 0;
    char *endOfLine;

    //try to open map
    if ((fd = open(av[1], O_RDONLY)) == -1)
         return WRONG_INPUT;
    //try to read the map
    if ((bitRead = read(fd, BUFF, READ_PACE)) == -1)
        return WRONG_INPUT;
    
    BUFF[bitRead] = '\0';
    //check if first line is well formated
    if ((endOfLine = strchr(BUFF, '\n')) == NULL)
        return WRONG_INPUT;
    //int length = abs((int)((char*)BUFF - (char*)endOfLine));
    ret->n = strtol(BUFF, &BUFF, 10);
    ret->m = strtol(BUFF + 1, &BUFF, 10);
    ret->full = *BUFF++;
    ret->empty = *BUFF++;
    ret->path = *BUFF++;
    ret->startNode = *BUFF++;
    ret->endNode = *BUFF++;
    if (VERBOSE)
        printInputVar(ret);
    close(fd);
    return 0;
}

//Dijkstra algorithm
int main(int argc, char **argv)
{
    (void)argc; //unused variable
    //process the input
    input_t input;
    
    memset(&input, 0, sizeof(input_t));
    if (processRawInput(argv, &input) == -1) {
        printf("ERROR: Wrong Input");
        return -1;
    }
    goThroughTheMap(input, argv[1]);
    //prepare storage for 
    return 0;
}