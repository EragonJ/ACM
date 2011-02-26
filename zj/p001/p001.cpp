#include <iostream>
#define MAX 300
using namespace std;

void print_map(int row, int col, char map_n[][MAX], int field_count) {

  int i, j;
  printf("Field #%d:\n", field_count);

  for (i = 1; i <= row; i++) {
    for (j = 1; j <= col; j++) {
      printf("%c", map_n[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {

  int i, j;
  int row, col;
  int field_count = 1;
  int center_x, center_y;

  while (cin >> row >> col) {

    // exit
    if ((row == col) && (col == 0)) {
      break;
    }

    char map_input[MAX][MAX];
    char map_n[MAX][MAX];

    // initialization
    for(i = 0; i < MAX; i++) {
      for( j = 0; j < MAX; j++) {
        map_n[j][i] = '0';
      }
    }

    // Combine input and tranform together
    for(i = 0; i < row; i++) {
      scanf("%s", map_input[i]);    

      for(j = 0; j < col; j++) {
        if (map_input[i][j] == '*') {

          center_x = j + 1;
          center_y = i + 1;

          map_n[center_y+1][center_x+1] = map_n[center_y+1][center_x+1] == '*' ? '*' : map_n[center_y+1][center_x+1] + 1;
          map_n[center_y+1][center_x]   = map_n[center_y+1][center_x]   == '*' ? '*' : map_n[center_y+1][center_x]   + 1;
          map_n[center_y+1][center_x-1] = map_n[center_y+1][center_x-1] == '*' ? '*' : map_n[center_y+1][center_x-1] + 1;
          map_n[center_y][center_x+1]   = map_n[center_y][center_x+1]   == '*' ? '*' : map_n[center_y][center_x+1]   + 1;
          map_n[center_y][center_x]     = '*';
          map_n[center_y][center_x-1]   = map_n[center_y][center_x-1]   == '*' ? '*' : map_n[center_y][center_x-1]   + 1;
          map_n[center_y-1][center_x+1] = map_n[center_y-1][center_x+1] == '*' ? '*' : map_n[center_y-1][center_x+1] + 1;
          map_n[center_y-1][center_x]   = map_n[center_y-1][center_x]   == '*' ? '*' : map_n[center_y-1][center_x]   + 1;
          map_n[center_y-1][center_x-1] = map_n[center_y-1][center_x-1] == '*' ? '*' : map_n[center_y-1][center_x-1] + 1;
        }
      }
    }

    print_map(row, col, map_n, field_count);
    
    field_count++;
  }
	return 0;
}
