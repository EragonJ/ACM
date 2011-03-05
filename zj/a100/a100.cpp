/*
 *  Problem : "Sample Assignment"
 *  ID      : a100
 *  Date    : 2011-03-05
 *  Idea    : 這題比較不公平一點，因為他沒有說他的 incoming message 有多長，是看了討論才知道會長到數十萬，
 *            所以要記得把 MAX 開大一點（無恥），然後因為 message 內也有可能會有 space ，所以請用 getline，
 *            要不然又會被陰一次 ...
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500000
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

  // get rid of the newline
  getchar();

  // how many rounds
  for (i = 0; i < count; i++) {

    // provide blank line 
    if (count > 1 && i > 0) {
      printf("\n");
    }

    // each round with 5 input
    char input[5][MAX];
    for (j = 0; j < 5; j++) {
      cin.getline(input[j], MAX);
    }

    for (j = 1; j < 5; j++) {
      print_line(input[0], input[j]);
    }
  }
  return 0;
}

