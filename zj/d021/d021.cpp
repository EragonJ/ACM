/*
 *  Problem : "E - To and Fro"
 *  id      : d021
 *  Date    : 2011-03-02
 *  Author  : EragonJ
 */
#include <iostream>
#include <string.h>
#define MAX 300
using namespace std;
int main() {

  int row, col;

  while (cin >> col) {
    if ( col == 0 ) {
      break;
    }

    // discard "\n"
    getchar();

    char input[MAX];
    char input_2D[MAX][MAX];
    int i, j, direction;

    cin.getline(input, MAX); 
    row = strlen(input) / col;

    for (i = 0, direction = 0; i < strlen(input); i++) {

      // snake direction
      direction = (i / col) % 2;
      if ( direction == 0) {
        input_2D[i/col][i%col] = input[i];
      }
      else {
        input_2D[i/col][(col - 1) - i%col] = input[i];
      }
    }

    for (i = 0; i < col; i++) {
      for (j = 0; j < row; j++) {
        cout << input_2D[j][i];
      }
    }
    cout << endl;
  }
	return 0;
}

