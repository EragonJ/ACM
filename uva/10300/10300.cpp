/*
 *  Problem : "Ecological Premium"
 *  ID      : 10300
 *  Date    : 2011-03-06
 *  Idea    : Nothing
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  int n, f, n1, n2, n3, count; 

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {

    count = 0;
    scanf("%d", &f);

    for (int j = 0; j < f; j++) {
      scanf("%d %d %d", &n1, &n2, &n3);
      count += n1 * n3;
    }

    printf("%d\n", count);
  }
  return 0;
}
