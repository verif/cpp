#include <stdio.h>

// Swap without using temporary variable

void swap(int & i, int & j) {
  i = i ^ j;
  j = i ^ j; // now j has old i
  i = i ^ j; // now i has old j
}

int main () {
  int i = 2;
  int j = 3;
  printf("i=%d j=%d\n", i, j);
  swap(i, j);
  printf("i=%d j=%d\n", i, j);
  return 0;
}
