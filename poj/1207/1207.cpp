/*
 *  Problem : "The 3n+1 problem"
 *  id      : 1207
 *  Date    : 2011-03-02
 *  Author  : EragonJ
 */
#include <iostream>
using namespace std;

int calculate_3n_1(int n) {
  int cycle_length = 1;

  while (n != 1) {
    if ( n%2 == 1) {
      n = 3*n + 1;
    }
    else {
      n = n/2;
    }
    cycle_length++;
  }

  return cycle_length;
}

int process(int low, int high) {
  int i, j;
  int max_cycle_length = 0;
  int cycle_length;

  for (i = low; i <= high; i++) {

    cycle_length = calculate_3n_1(i);
    max_cycle_length = (max_cycle_length < cycle_length) ? cycle_length : max_cycle_length;
  }

  return max_cycle_length;
}

// Make sure that i is the smaller one
void max_min(int* i, int* j) {
  if (*i > *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
  }
}

int main() {

  int i, j;
  int ori_i, ori_j;
  while (scanf("%d %d", &i, &j) == 2) {

    ori_i = i;
    ori_j = j;

    max_min(&i, &j);
    printf("%d %d %d\n", ori_i, ori_j, process(i, j));
  }
	return 0;
}

