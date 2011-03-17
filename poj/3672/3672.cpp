/*
 *  Problem : "Long Distance Racing"
 *  ID      : 3672
 *  Date    : 2011-03-12
 *  Idea    : No
 *  Author  : EragonJ
 */
#include <iostream>
#define MAX 120000
using namespace std;

int main() {

  int M, T, U, F, D;
  cin >> M >> T >> U >> F >> D;
  getchar();

  int distance = 0;
  int unit = 0;
   
  char path[MAX];
  
  // Main loop
  for (int i = 0; i < T; i++) {
    scanf("%c", &path[i]);
    getchar();

    if (path[i] == 'u' || path[i] == 'd') {
      distance += (U + D);
    }
    else if (path[i] == 'f') {
      distance += (2 * F);
    }

    if (distance > M) { 
      break;
    }
    else {
      unit++;
    }
  }

  printf("%d\n", unit);

  return 0;
}
