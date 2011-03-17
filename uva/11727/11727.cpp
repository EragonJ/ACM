/*
 *  Problem : "Cost Cutting"
 *  ID      : 11727
 *  Date    : 2011-03-15
 *  Idea    : 水題
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
using namespace std;

int cmp(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int main() {

  int T;
  scanf("%d", &T);

  int salary[3];
  for (int i = 0; i < T; i++) {
    scanf("%d %d %d", &salary[0], &salary[1], &salary[2]); 
    qsort(salary, 3, sizeof(int), cmp);

    printf("Case %d: %d\n", i+1, salary[1]);
  }

  return 0;
}
