#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300
using namespace std;

void print_line(char base[], char input[]) {
  int i, j;

  for (i = 0; i < strlen(input); i++) {
    int check = 0;

    for (j = 1; j < strlen(base); j+=2) {
      if ( input[i] == base[j-1] ) {
        check = 1;
        break;
      }
    }

    if (check) {
      printf("%c", base[j]);
    }
    else {
      printf("%c", input[i]);
    }
  }
  printf("\n");
}

int main() {

  int i, j;
  int count;
  scanf("%d", &count);

  // how many rounds
  for (i = 0; i < count; i++) {

    // each round with 5 input
    char input[5][MAX];
    for (j = 0; j < 5; j++) {
      fgets(input[j], MAX, stdin);
    }

    for (j = 1; j < 5; j++) {
      print_line(input[0], input[j]);
    }

  }

  return 0;
}

