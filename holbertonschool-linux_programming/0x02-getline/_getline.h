#ifndef _GETLINE_H
#define _GETLINE_H

#define READ_SIZE 256

char *nextBufferLine(char *buffer, const int fd);
int fillBuffer(char *buffer, const int fd);
char *_getline(const int fd);
#endif /* _GETLINE_H */