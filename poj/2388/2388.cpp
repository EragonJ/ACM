/*
 *  Problem : "Who's in the Middle"
 *  ID      : 2388
 *  Date    : 2011-03-13
 *  Idea    : qsort 取中位數
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 12000
using namespace std;

int cmp(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int main() {

  int N;
  scanf("%d", &N);

  int cow[MAX];
  for (int i = 0; i < N; i++) {
    scanf("%d", &cow[i]); 
  }

  qsort(cow, N, sizeof(int), cmp);
  printf("%d\n", cow[((N + 1) / 2) - 1]);
  return 0;
}
