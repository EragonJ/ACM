/*
 *  Problem : "Cow Multiplication"
 *  ID      : 3673
 *  Date    : 2011-03-03
 *  Idea    : count 要先初始化 =_= ... 還有其它的就是照題目說的做而已
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 300
using namespace std;

int main() {
  char input[MAX];
  cin.getline(input, MAX);

  int count = 0;
  char *a , *b;

  a = strtok(input, " ");
  b = strtok(NULL, " ");

  for (int i = 0; i < strlen(a); i++) {
    for (int j = 0; j < strlen(b); j++) {
      count += (a[i] - '0') * (b[j] - '0');
    }
  }

  printf("%d\n", count);
	return 0;
}

