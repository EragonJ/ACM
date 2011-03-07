/*
 *  Problem : "Peter's Smokes"
 *  ID      : 10346
 *  Date    : 2011-03-07
 *  Idea    : 注意 cigarettes 的數目會超過 int !
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

  int n, k;
  while (scanf("%d %d", &n, &k) != EOF) {
    long long int cigarettes = n;
    int butts = n;

    while (true) {
      if (butts < k) {
        break;
      }
      else {
        n = butts / k;
        cigarettes += n;
        butts = butts % k + n;
      }
    }

    printf("%lld\n", cigarettes);
  }
  return 0;
}
