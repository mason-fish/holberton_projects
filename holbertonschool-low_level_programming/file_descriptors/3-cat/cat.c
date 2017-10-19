#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **argv) {
  int fd, i;
  char bf;

  if(ac == 1) {
    while(read(0, &bf, 1)) {
      write(1, &bf, 1);
    }
    return(0);
  }

  if (ac >= 2) {
    i = 1;
    while(i < ac) {
      fd = open(argv[i], O_RDONLY);
      while(read(fd, &bf, 1)) {
	write(1, &bf, 1);
      }
      
      if(close(fd)){
	return (1);
      }

      i++;
    }
    return(0);
  }
  
  return(1);
}
