/*
 *  Problem : "D - Document Shuffler"
 *  ID      : d040
 *  Date    : 2011-03-03
 *  Idea    : 此題是依照題目的流程來模擬繞行的情況，主要是先建出 Order
 *            然後利用已選定的 TEST_INDEX 來跑流程，直到回到原點為止。
 *  Author  : EragonJ
 */
#include <iostream>
#define MAX 350000
#define TEST_INDEX 1
using namespace std;

int get_shuffle_cycle(int order[], int pages_count) {
  int count = 1;
  int next_index = order[TEST_INDEX];

  while (next_index != TEST_INDEX) {
    next_index = order[next_index];
    count ++;
  }

  return count;
}

void build_order(int order[], int pages_count) {
  int i;
  int odd_count  = 0;
  int even_count = 0;

  for (i = 0; i < pages_count; i++) {
    if ( i % 2 == 0) {
      order[i] = odd_count++;
    }
    else {
      order[i] = (pages_count / 2) + odd_count - 1; // index problem
    }
  }
}

int main() {
  
  int lines;
  int pages_count;
  int i;

  cin >> lines;

  for(i = 0; i < lines; i++) {

    scanf("%d", &pages_count);
    int order[MAX];

    build_order(order, pages_count);
    printf("%d\n", get_shuffle_cycle(order, pages_count));
  }
	return 0;
}

