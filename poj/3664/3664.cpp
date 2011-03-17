/*
 *  Problem : "Election Time"
 *  ID      : 3664
 *  Date    : 2011-03-13
 *  Idea    : 內建的 qsort 是不是有比較快呀？這題用兩次 qsort 就結束了。哦對了，qsort 的 base 和 num 要注意一下！
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 52000
using namespace std;

typedef struct VOTES {
  int index;
  int first;
  int second;
} COW_VOTES;

int cmp_first(const void* a, const void* b) {
  COW_VOTES* _a = (COW_VOTES*) a;
  COW_VOTES* _b = (COW_VOTES*) b;
  return (_a->first - _b->first);
}

int cmp_second(const void* a, const void* b) {
  COW_VOTES* _a = (COW_VOTES*) a;
  COW_VOTES* _b = (COW_VOTES*) b;
  return (_a->second - _b->second);
}

int main() {

  int N, K;
  scanf("%d %d", &N, &K);

  COW_VOTES cow[MAX];
  for (int i = 0; i < N; i++) {
    cow[i].index = i + 1;
    scanf("%d %d", &cow[i].first, &cow[i].second);
  }

  qsort(cow, N, sizeof(COW_VOTES), cmp_first);
  qsort(cow + (N - K), K, sizeof(COW_VOTES), cmp_second);   

  printf("%d\n", cow[N-1].index);

  return 0;
}
