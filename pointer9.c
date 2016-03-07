#include <stdio.h>
#include <stdlib.h>

#define COLS 5
typedef int RowArray[COLS];
RowArray *rptr;

int main(void) {
  int nrows = 10;
  int row, col;
  rptr = malloc(nrows * COLS * sizeof(int));
  for (row = 0; row < nrows; row++) {
    for (col = 0; col < COLS; col++) {
      rptr[row][col] = 1;
    }
  }
  return 0;
}

// rptr has all the characteristics of an array name, except that rptr is modifiable, and array notation may
// be used throughout the rest of the program, if you intend to write a function to modify the array contents,
// you must use COLS as a part of the formal parameter in the function
