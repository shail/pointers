#include <stdio.h>
#include <stdlib.h>

// We allocate a block of memory to hold the whole array first, then create an array of pointers to point to
// each row. Even though the array of pointers is being used, the actual array in memory is contiguous

int main(void) {
  int **rptr;
  int *aptr;
  int *testptr;
  int k;

  int nrows = 5;
  int ncols = 8;
  int row, col;

  // allocate the memory for the array

  aptr = malloc(nrows * ncols * sizeof(int));

  if (aptr == NULL) {
    puts("\nFailure to allocate room for the array");
    exit(0);
  }

  // allocate room for the pointers to the rows

  rptr = malloc(nrows * sizeof(int *));
  if (rptr == NULL) {
    puts("\nFailure to allocate room for the pointers");
    exit(0);
  }

  // and now we point the pointers

  for (k = 0; k < nrows; k++) {
    rptr[k] = aptr + (k * ncols);
  }

  // Now we illustrate how the row pointers are incremented
  printf("\n\nIllustrating how row pointers are incremented");
  printf("\n\nIndex   Pointer(hex)    Diff.(dec)");

  for (row = 0; row < nrows; row++) {
    printf("\n%d        %p", row, rptr[row]);
    if (row > 0) {
      printf("          %ld", (rptr[row] - rptr[row-1]));
    }
  }

  printf("\n\nAnd now we print out the array\n");
  for (row = 0; row < nrows; row++) {
    for (col = 0; col < ncols; col++) {
      rptr[row][col] = row + col;
      printf("%d ", rptr[row][col]);
    }
    putchar('\n');
  }

  puts("\n");

  // and here we illustrate that we are, in fact, dealing with a 2d array in a contiguous block memory
  printf("And now we demonstrate that they are contiguous in memory\n");

  testptr = aptr;
  for (row = 0; row < nrows; row++) {
    for (col = 0; col < ncols; col++) {
      printf("%d ", *(testptr++));
    }
    putchar('\n');
  }

  return 0;
}

// 2 calls to malloc - 1 to get room for the array itself and 1 to get room for the array of ptrs
