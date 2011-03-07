/*
 *  Problem : "Summation of Polynomials"
 *  ID      : 10302
 *  Date    : 2011-03-07
 *  Idea    : 這邊要特別注意 i*i*i ，會先相乘完再 assign，但是如果位數不夠就會暴了
 *  Author  : EragonJ
 */
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
long long int sum(int k) {
  long long int result = 0;
  for(long long int i = 1; i <= k; i++) {
    result = result + i*i*i;
  }

  return result;
}
int main() {

  int x;
  while (scanf("%d", &x) != EOF) {
    printf("%lld\n", sum(x));  
  }

  return 0;
}
