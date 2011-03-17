/*
 *  Problem : "Dining Cows"
 *  ID      : 3671
 *  Date    : 2011-03-15
 *  Idea    : 聽說這個是 DP 的問題，不過不太了解其箇中的精華，要了解一下。 BTW ， 要記錄都換成 1 號時所需的
 *            次數，再記錄都換成 2 號時所需的次數，一個從左一個從右來計算，最後再於前後加入 0，使其可以被繞
 *            行所有的配對情況。
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAX 32000
using namespace std;

int main() {

  int N;
  cin >> N;

  int cow[MAX];
  int card_1[MAX] = {0};
  int card_2[MAX] = {0};
  for (int i = 0; i < N; i++) {
    cin >> cow[i];
  }

  for (int i = 1, card_1_count = 0, card_2_count = 0; i <= N; i++) { 
    // Card 1 list
    if (cow[i - 1] != 1) {
      card_1[i] = ++card_1_count;
    }
    else {
      card_1[i] = card_1_count;
    }

    // Card 2 list
    if (cow[N-i] != 2) {
      card_2[N-i+1] = ++card_2_count;
    }
    else {
      card_2[N-i+1] = card_2_count;
    }
  }

  int min = N;
  int card_sum;
  
  for (int i = 0; i <= N; i++) {
    card_sum = card_1[i] + card_2[i + 1];

    if (min > card_sum) {
      min = card_sum;
    }
  }

  cout << min << endl;

  return 0;
}
