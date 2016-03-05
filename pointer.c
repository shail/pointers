#include <stdio.h>

int strlena(char *string) {
  int counter = 0;
  while (*string) {
    counter += 1;
    string++;
  }
  return counter;
}

void strncata(char *stringa, const char *stringb, int n) {
  while (*stringa != '\0') {
    *stringa++;
  }

  do {
    *stringa++ = *stringb++;
    n--;
  } while (n > 0);
}

int main(void) {
  char string[10] = "Blah";
  char *stringB = "Tree";
  int j = strlena(string);
  printf("Value :%d\n", j);
  strncata(string, stringB, 4);
  printf("String : %s\n", string);
}
