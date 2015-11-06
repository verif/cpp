#include <stdio.h>

int main() {

  int i = 1;
  char * c = (char*) &i;
  printf("%c\n", *c + '0');
  return 0;
}
