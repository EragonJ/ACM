#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
  int n;
  long long int k;

  while (cin >> n) {

    k = 1;
    int count = 1;

    while ((k % n) != 0) {
      count++;
      k = k*10 + 1;
    }
    
    printf("%d\n", count);
  }
	return 0;
}

