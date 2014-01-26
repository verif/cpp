#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

inline void swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void merge_sort(int A[], int N) {
  if (N < 2) return;
  if (N == 2) {
    if (A[0] > A[1]) {
      swap(A[0], A[1]);
    }
    return;
  }

  int middle = N/2;
  merge_sort(A, middle);
  merge_sort(&A[middle], N - middle);

  // the merge part
  // allocate a new array with same size as temporay storage
  int * B = new int[N];
  int i = 0;
  int j = middle;
  for (int idx = 0; idx < N; idx++) {
    if (i < middle && j < N) {
      if (A[i] < A[j]) {
        B[idx] = A[i];
        i++;
      }
      else {
        B[idx] = A[j];
        j++;
      }
    }
    else if (i < middle) {
      B[idx] = A[i];  
      i++;
    }
    else if (j < N) {
      B[idx] = A[j];  
      j++;
    }
    else {
      assert(0);
    }
  }
  for (int idx = 0; idx < N; idx++)
    A[idx] = B[idx];
  delete [] B;
}

void quick_sort (int A[], int left, int right) {
  int pivot = A[(left+right)/2];

  int i = left;
  int j = right;
  while (i <= j) {
    while (A[i] < pivot)
      i++;
    while (A[j] > pivot)
      j--;
    if (i <= j) {
      // swap A[i] and A[j]
      swap(A[i], A[j]);
      i++;
      j--;
    }
  }
  if (left < i - 1)
    quick_sort(A, left, i - 1);
  if (i < right)
    quick_sort(A, i, right);
}

void disp_array(int A[], int N) {
  for (int i = 0; i < N; i++) {
    printf("%d\n", A[i]);
  }
}

int main () {
  int N = 1 << 17;
  int * A = new int[N];
  int * B = new int[N];
  for (int i = 0; i < N; i++) {
    A[i] = rand() & 0xffff;
    B[i] = A[i];
  }
  merge_sort(A, N);
  quick_sort(B, 0, N-1);
  if (memcmp(A, B, N*sizeof(int))) {
    printf("Error, mismatch found\n");
    for (int i = 0; i < N; i++)
      if (A[i] != B[i])
        printf("%2d: %6d %6d *\n", i, A[i], B[i]);
      else
        printf("%2d: %6d %6d\n", i, A[i], B[i]);
  }
  //disp_array(B, N);
  return 0;
}
