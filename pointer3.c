#include <stdio.h>

char strA[80] = "A string to be used for demonstration purposes";
char strB[80] = "123456789011111234567890234567890234567890234567890234567890";

char *my_strcpy(char *destination, const char *source) {
  char *p = destination;
  while (*source != '\0') {
    *p++ = *source++;
  }
  *p = '\0';
  return destination;
}

int main(void) {
  char *pa; // pointer to char
  char *pb; // another pointer to char
  puts(strA); // show string A
  pa = strA; // point pa at string A
  puts(pa);
  pb = strB;
  putchar('\n');
  while(*pa != '\0') {
    *pb++ = *pa++;
  }
  *pb = '\0';
  puts(strB);
  return 0;
}


