/*
 *  Problem : "f91"
 *  ID      : 10696
 *  Date    : 2011-03-04
 *  Idea    : Recursive only
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
#define MAX 300
using namespace std;

int f91(int n) {
  if (n <= 100) {
    return f91(f91(n + 11));
  }
  else {
    return n - 10;
  }
}

int main() {
  int n;
  int cache[MAX] = {0};
  while (scanf("%d", &n) == 1) {
    if (n == 0) {
      break;
    }
    else {
      printf("f91(%d) = %d\n", n, f91(n));
    }
  }
	return 0;
}

