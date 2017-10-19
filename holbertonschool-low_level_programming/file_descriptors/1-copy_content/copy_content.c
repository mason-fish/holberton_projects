#include <fcntl.h>
#include <unistd.h>

/* This function behaves similarly to cp in bash */
int main(int ac, char **argv) {
  int fd_src, fd_dest;
  char c;

  if (ac != 3) {
    return (1);
  }
  
  if((fd_src = open(argv[1], O_RDONLY)) < 0) {
    return (1);
  }

  fd_dest = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644);
  while(read(fd_src, &c, 1)) {
    write(fd_dest, &c, 1);
  }

  if (close(fd_src) || close(fd_dest)) {
    return (1);
  }

  return (0);
}
