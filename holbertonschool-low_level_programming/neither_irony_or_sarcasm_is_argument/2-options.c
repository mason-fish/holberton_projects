#include <stdio.h>
#include <string.h>

int check_back(int ac, char *av[], char *check);

int main(int argc, char *argv[]) {
  int i, flag;
  char *cP;

  for(i = 0, flag = 0; i < argc; i++) {
    if (strcmp(argv[i], "--") == 0) {
      printf("\n");
      return (0);
    }
    if (argv[i][0] == '-' && argv[i][1] == '-') {
      if (check_back(i, argv, &(argv[i][2]))) {
	if (flag) {
	  printf(", ");
	}
	printf("%s", &(argv[i][2]));
	flag = 1;
      }
    }
    else if (argv[i][0] == '-') {
      cP = &argv[i][1];
      while(*cP) {
	if (check_back(i, argv, cP)) {
	  if (flag) {
	    printf(", ");	  
	  }
	  printf("%c", *cP);
	  flag = 1;
	}
	cP++;
      }
    }
  }

  printf("\n");

  return (0);
}

int check_back(int ac, char *av[], char *check) {
  int i;
  char *cP;

  for(i = 0; i < ac; i++) {
    if (av[i][0] == '-' && av[i][1] == '-') {
      if (strcmp(check, &av[i][2]) == 0) {
	return (0);
      }
    }
    else if (av[i][0] == '-') {
      cP = &av[i][1];
      while(*cP) {
	if (*check == *cP) {
	  return (0);
	}
	else {
	  cP++;
	}
      }
    }
  }
  
  return (1);
}
