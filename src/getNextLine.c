#define BUFF_SIZE 30
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *g_nextBuff;

int treatBuffer(char *treat, char **line)
{
    char *rest;
    rest = strchr(treat, '\n');

    if (!rest)
    {
        *line = (char*)malloc(sizeof(char) * (strlen(treat) + 1));
        strcpy(*line, treat);
        g_nextBuff = NULL;
        return 1;
    }
    rest += 1;
    *line = (char*)malloc(sizeof(char) * (strlen(treat) - strlen(rest) + 1));
    strncpy(*line, treat, strlen(treat) - strlen(rest));
    g_nextBuff = (char*)malloc(strlen(rest) + 1);
    strcpy(g_nextBuff, rest);
    return (1);
}

int getNextLine(int fd, char **line)
{
    char buff[BUFF_SIZE + 1];
    int bitRead;
    char *tmp = NULL;
    if (!line)
    {
     
        return -1; 
    }
    if (g_nextBuff && strchr(g_nextBuff, '\n') != NULL)
        return treatBuffer(g_nextBuff, line);
    else if (g_nextBuff)
    {
        tmp = (char*)malloc(sizeof(char) * strlen(g_nextBuff) + 1);
        strcpy(tmp, g_nextBuff);
    }
    while ((bitRead = read(fd, buff, BUFF_SIZE)) > 0)
    {
        buff[bitRead] = '\0';
        if (tmp)
        {
            tmp = realloc(tmp, strlen(tmp) + strlen(buff));
            strcat(tmp, buff);
        }
        else 
        {
            tmp = (char*)malloc(sizeof(char) * strlen(buff) + 1);
            strcpy(tmp, buff);
        }
        if (strchr(tmp, '\n') != NULL)
            return treatBuffer(tmp, line);
    }
    if (buff[0])
    {
        buff[bitRead] = '\0';
        strcpy(*line, buff);
    }
    return bitRead;
} 