#include "_getline.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

char *_getline(const int fd)
{
    static char *buffer;

    buffer = malloc(sizeof(char) * READ_SIZE);
    if (buffer == NULL) {
        return NULL;
    }

    /*if (!fillBuffer(&buffer, fd)) {
        printf("hit the end of file\n");
    }*/
    fillBuffer(buffer, fd);
    return nextBufferLine(buffer, fd);
}

int fillBuffer(char *buffer, const int fd)
{
    memset(buffer, '\0', READ_SIZE);
    return read(fd, buffer, sizeof(READ_SIZE));
}

char *nextBufferLine(char *buffer, const int fd)
{
    static int i;
    int start = i;
    char *line = NULL;

    while(i < READ_SIZE && buffer[i] != '\n') {
        /*if (buffer[i] == '\0' && !fillBuffer(buffer, fd)) {
            printf("hit the end of file while grabbing line\n");
        }*/
        if (buffer[i] == '\0') {
            printf("hit the end of file while grabbing line, fd: %d, i: %d\n", fd, i);
            break;
        }
        i++;
    }
    line = malloc(sizeof(char) * (i - start + 1));
    if (line == NULL) {
        return NULL;
    }
    strncpy(line, &buffer[start], (i - start + 1));
    line[i] = '\0';

    return line;
}
