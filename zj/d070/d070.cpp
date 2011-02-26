#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 999
using namespace std;

/*
 *  print specific element in 2D array
 */
void zz_print(int i, int j, char input2D[][MAX]) {
  printf("%c", input2D[i][j]);
}

void zz_print_all(int row, int col, char input2D_original[][MAX]) {
  int i, j;
  for (i = 0; i < col; i++) {
    for (j = 0; j < row; j++) {
      if ( input2D_original[j][i] != '*') {
        zz_print(j, i, input2D_original);
      }
    }
  }
  printf("\n");
}

/*
 *  This is for debug
 */
void zz_debug(int row, int col, char input2D[][MAX]) {
  int i, j;

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      zz_print(i, j, input2D);
    }
    cout << endl;
  }
}

void zz_traverse(int row, int col, char input[]) {

  int bound_x = col - 1;
  int bound_y = row - 1;
  int x = 0, y = 0;
  int line = 0;
  int i;
  int toggle = 0;
  int check = 1;
  int inputIndex = 0;

  // transform 1D back to original 2D
  char input2D_original[MAX][MAX];

  // Start point
  while (check) {

    // up
    if (toggle == 1) {
      for (i = 0; i <= line; i++) {

        if (x + (line - i) > bound_x || y + i > bound_y) {
          continue;
        }

        //zz_print(y + i, x + (line - i), input2D);
        input2D_original[y+i][x+(line-i)] = input[inputIndex++];

        if (y + i == bound_y && x + (line - i) == bound_x) {

          check = 0;
          break;
        }
      }
    }
    // down
    else {
      for (i = 0; i <= line; i++) {

        if (x + i > bound_x || y + (line - i) > bound_y) {
          continue;
        }

        //zz_print(y + (line - i), x + i, input2D);
        input2D_original[y+(line-i)][x+i] = input[inputIndex++];

        if (x + i == bound_x && y + (line - i) == bound_y) {
          check = 0;
          break;
        }
      }
    }

    line++;
    toggle = (toggle + 1) % 2;
  }

  zz_print_all(row, col, input2D_original);
  //zz_debug(row, col, input2D_original);
}

int main() {

  int row, col;
  char options[MAX];
  
  while (cin.getline(options, MAX)) {
    if('#' == options[0]) {
      break;
    }
    else {

      // for options
      char* pch;
      pch = strtok(options, " ");
      row = atoi(pch);
      pch = strtok(NULL, " ");
      col = atoi(pch);

      char input[MAX];
      cin.getline(input, MAX);

      if (strlen(input) != row * col) {
        printf("%s\n","<encrypted length error>");
      }
      else {
        zz_traverse(row, col, input);
      }
    }
  }

	return 0;
}

