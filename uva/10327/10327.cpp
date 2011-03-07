/*
 *  Problem : "Flip Sort"
 *  ID      : 10327
 *  Date    : 2011-03-07
 *  Idea    : Bubble Sort （敗在自己的 swap ..）
 *  Author  : EragonJ
 */
#include <algorithm>
#include <iostream>
#include <stdio.h>
#define MAX 1200
using namespace std;

int main() {

  int n;
  while (scanf("%d", &n) != EOF) {
    int numbers[MAX];
    int count = 0;

    for (int i = 0; i < n; i++) {
      scanf("%d", &numbers[i]);
    }

    for (int i = n-1; i >= 0; i--) {
      for (int j = 0; j < i; j++) {
        if (numbers[j] > numbers[j+1] ) {
          swap( numbers[j], numbers[j+1]);
          count ++;
        }
      }
    }

    printf("Minimum exchange operations : %d\n", count);
  }
  return 0;
}
