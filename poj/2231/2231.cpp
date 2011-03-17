/*
 *  Problem : "Moo Volume"
 *  ID      : 2231
 *  Date    : 2011-03-13
 *  Idea    : 有公式可以推導，假設為 A     B     C     D
 *                                   |-----|-----|-----|
 *                                      a     b     c
 *            那麼就是 |AB| + |AC| + |AD| +
 *                     |AC| + |AD| +
 *                     |AD| +
 *            然後再乘 2 即可補回剩下空的三角形。
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
#include <math.h>
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

  long long int noise = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - i - 1; j++) { 
      noise += abs(cow[j + i + 1] - cow [j]);
    }
  }

  noise *= 2;
  printf("%lld\n", noise);
  
  return 0;
}
