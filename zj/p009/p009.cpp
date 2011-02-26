#include <iostream>
#define MAX 100
using namespace std;

char fix_typo(char x) {
  int i;
  char code[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

  for (i = 0; code[i] != x; i++);

  return code[i-1];
}

int main() {
  char input[MAX];
  int i;

  while (cin.getline(input, MAX)) {
    for (i = 0; i < strlen(input); i++) {
      if (input[i] == ' ') {
        printf(" "); 
      }
      else {
        printf("%c", fix_typo(input[i]));
      }
    }
    printf("\n");
  }
	return 0;
}

