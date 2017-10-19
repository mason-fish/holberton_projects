#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **argv) {
  int fd;
  char bf;

  if (ac != 2) {
    return (1);
  }

  fd = open(argv[1], O_RDONLY);
  while(read(fd, &bf, 1)) {
    write(1, &bf, 1);
  }

  if(close(fd)){
    return (1);
  }
  
  return(0);
}
