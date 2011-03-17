/*
 *  Problem : "Costume Party"
 *  ID      : 3663
 *  Date    : 2011-03-13
 *  Idea    : 這題是 TLE 大賽，所以把 iostream 的 I/O function 全換成 stdio 的 I/O function，然後因為有用到 qsort
 *            所以已經先花 O(n) ，這邊如果能夠改良，讓回傳值為 upper_bound 的話，就可以少掉後面為了找 upper_bound
 *            所花的 O(n) ， 最後最花時間的是比對的地方，花了 O(n^2)，所以其實很拼了，最後是 9XX MS 過。
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define MAX 22000
using namespace std;

int cmp(const void* a , const void* b) {
  return (*(int*)a - *(int*)b);
}

int main() {

  int N, S;
  scanf("%d %d", &N, &S);

  int cow[MAX];

  for (int i = 0; i < N; i++) {
    scanf("%d", &cow[i]);
  }

  qsort(cow, N, sizeof(int), cmp);

  int upper_bound = 0;
  for (int i = 0; cow[i] < S && i < N; i++, upper_bound++);

  int pairs = 0;
  for (int i = 0; i < upper_bound - 1; i++) {
    for (int j = i + 1; j < upper_bound; j++) {
      if (cow[i] + cow[j] <= S) {
        pairs ++;
      }
    }
  }

  printf("%d\n", pairs);
  return 0;
}
