#include "holberton.h"
#include <stdio.h>

#define UNUSED(x) (void)(x)

int main (int argc, char *argv[])
{
    int i;

    if (argc < 2) {
        return (0);
    }
    for (i = 1; i < argc; i++) {
        _ls(argv[i]);
    }
	return (0);
}
