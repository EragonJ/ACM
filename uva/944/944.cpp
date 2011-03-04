/*
 *  Problem : "Happy Number"
 *  ID      : 944
 *  Date    : 2011-03-04
 *  Idea    : 這題有幾個可以學習的重點，因為時間只有 3 sec，所以在爬行 cache array 的時候要
 *            給 length 而不是 MAX 當終止條件（過度爬行會造成TLE），之後還有一個重點就是繞行
 *            數字的各個位數，while loop 的條件式要記得！然後這一題最後一個陰險的地方就是換行
 *            只能出現在 input 與 input 之間，千萬不要一拿到一個 input 就多輸出一個換行，會造
 *            成最後的結果多了一個換行而 WA。
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 300
using namespace std;

bool is_cached(int n, int cache[], int length) {
  for (int i = 0; i < length; i++) {
    if (cache[i] == n){
      return true;
    }
  }
  return false;
}

int get_happy_number(int n) {
  int count = 1;
  int cache[MAX] = {0};
  int cache_tail = 0;

  while ((n != 1) && !is_cached(n, cache, count)) {
    // cache the current number first
    cache[cache_tail++] = n;

    int n_copy = 0;
    int remainder = 0;

    // traverse all digits
    while ( !((n%10) == 0 && (n/10) == 0) ) {
      remainder = n % 10;
      n_copy += (remainder*remainder);
      n /= 10;
    }

    n = n_copy;
    count++;
  }

  if (n == 1) {
    return count;
  }
  else {
    return -1;
  }
}

int main() {
  int low, high;
  bool blink = false;

  while (cin >> low >> high) {
    // trick
    if (blink == true) {
      printf("\n");
    }

    for (int i = low; i <= high; i++) {
      int happy_number = get_happy_number(i);

      if (happy_number == -1) {
        continue;
      }
      else {
        printf("%d %d\n", i, happy_number);
      }
    }

    blink = true;
  }

	return 0;
}
