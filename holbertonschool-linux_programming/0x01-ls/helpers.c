#include "holberton.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

void _ls(char *inputDir)
{
    int err;
	DIR *dir;
	struct dirent *read;
	struct stat buf;

    err = lstat(inputDir, &buf);
    if (err == -1) {
        perror(inputDir);
        return;
    }
    if (!S_ISDIR(buf.st_mode)) {
        printf("Only supporting directories right now...\n");
        return;
    }
	dir = opendir(inputDir);

	while ((read = readdir(dir)) != NULL) {
		printf("%s  ", read->d_name);
	}
	printf("\n");
	free(dir);
}
