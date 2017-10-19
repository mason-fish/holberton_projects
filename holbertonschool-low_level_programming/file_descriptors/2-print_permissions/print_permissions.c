#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* This function writes the current permissions of a given file */
int main(int ac, char **argv) {  
  struct stat fs;

  if (ac != 2) {
    return (1);
  }

  if (stat(argv[1], &fs)) {
    return (1);
  }

  write(1, ((S_ISDIR(fs.st_mode)) ? "d" : "-"), 1);
  write(1, ((fs.st_mode & S_IRUSR) ? "r" : "-"), 1);
  write(1, ((fs.st_mode & S_IWUSR) ? "w" : "-"), 1);
  write(1, ((fs.st_mode & S_IXUSR) ? "x" : "-"), 1);
  write(1, ((fs.st_mode & S_IRGRP) ? "r" : "-"), 1);
  write(1, ((fs.st_mode & S_IWGRP) ? "w" : "-"), 1);
  write(1, ((fs.st_mode & S_IXGRP) ? "x" : "-"), 1);
  write(1, ((fs.st_mode & S_IROTH) ? "r" : "-"), 1);
  write(1, ((fs.st_mode & S_IWOTH) ? "w" : "-"), 1);
  write(1, ((fs.st_mode & S_IXOTH) ? "x" : "-"), 1);
  write(1, "\n", 1);

  return (0);
}
