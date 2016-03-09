#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int nrows = 5;  // Both of these variables could be evaluated or read in at run time
  int ncols = 10;
  int row;
  int **rowptr;
  rowptr = malloc(nrows * sizeof(int *));
  if (rowptr == NULL) {
    puts("\nFailure to allocate room for row pointers.\n");
    exit(0);
  }

  printf("\n\n\nIndex  Pointer(hex)   Pointer(dec)     Diff.(dec)");

  for (row = 0; row < nrows; row++) {
    rowptr[row] = malloc(ncols * sizeof(int));
    if (rowptr[row] == NULL) {
      printf("\nFailure to allocate for row[%d]\n", row);
      exit(0);
    }

    printf("\n%d          %p           %d", row, rowptr[row], *rowptr[row]);
    if (row > 0) {
      printf("                 %d", (int)(rowptr[row] - rowptr[row - 1]));
    }

    return 0;
  }
}

// rowptr is a pointer to pointer to type int, it points to the first element of an array of pointers to type
// int
//
// To get the array of pointers is one call to malloc(), to get the space for the rows is 5 calls to malloc()
// If you chose to use this approach, you can use the array notation to access individual elements of the
// array; it does not mean that the data in the two dimensional array is contiguous in memory
