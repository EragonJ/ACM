/*
 *  Problem : "Hashmat the Brave Warrior"
 *  ID      : 10055
 *  Date    : 2011-03-04
 *  Idea    : 這一題也很陰險，因為題目說 "The input numbers are not greater than 2^32"，但是 int 界線通常是 
 *            (- 2^31) ~ (2^31 - 1) 而 unsigned int 則是 0 ~ (2^32 - 1) 怎麼樣都會比測資小，所以會 overflow
 *            因此我們要利用 long long int 來解決。
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main() {
  long long int x, y;
  while (scanf("%lld %lld", &x, &y) != EOF) {
    printf("%lld\n",abs(x-y));
  }
  return 0;
}

