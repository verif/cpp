#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main () {
  #define N 20
  int A[N];

  for (int i = 0; i < N; i++)
    A[i] = i;

  int M = N;
  for (int i = 0; i < N; i++) {
    int rnd = rand() % M;
    printf("%d\n", A[rnd]);
    std::swap(A[rnd], A[M-1]);
    M--;
  }
  return 0;
}
