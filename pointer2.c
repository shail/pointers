#include <stdio.h>

int my_array[] = {1,2,3,4,5};
int *ptr;

int main(void) {
  int i;
  ptr = &my_array[0];

  printf("\n\n");
  for (i = 0; i < 6; i++) {
    printf("my_array[%d] = %d  ", i, my_array[i]);
    printf("ptr + %d = %d\n", i, *(++ptr));
  }
  return 0;
}
