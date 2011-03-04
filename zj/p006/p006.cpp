#include <iostream>
#include <stdio.h>
#include <math.h>
#define MAX 4096
using namespace std;
int main() {

  int n;
  // how many lines inputs
  while(cin >> n) {

    int line[MAX];
    int diff[MAX-1] = {0};
    int i, check = 0;

    for (i = 0; i < n; i++) {
      cin >> line[i]; 
    }
  
    for (i = 0; i < n-1; i++) {
      diff[ abs(line[i+1] - line[i]) ] = 1;
    }

    for (i = 0; i < n-1; i++) {
      if (diff[i+1] == 0) {
        check = 1;
        break;
      }
    }

    if (check) {
      printf("Not jolly\n");
    }
    else {
      printf("Jolly\n");
    }
  }
	return 0;
}

