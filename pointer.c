#include <stdio.h>

int strlena(char *string) {
  int counter = 0;
  while (*string) {
    counter += 1;
    string++;
  }
  return counter;
}

int main(void) {
  char *string = "Blah";
  int j = strlena(string);
  printf("Value :%d\n", j);
}
