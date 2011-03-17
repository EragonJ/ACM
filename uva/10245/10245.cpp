#include <iostream>
#include <stdio.h>
#define MAX 12000
using namespace std;

typedef struct Node {
  int x;
  int y;
} MyNode;

int main() {

  int N;
  while (scanf("%d", &N) == 1) {

    if (N == 0) {
      break;
    }
    else {

      MyNode node_list[MAX];

      for (int i = 0; i < N; i++) {
        scanf("%d %d", &node_list[i].x, &node_list[i].y);
      }
      

    }
  }
  
  return 0;
}
