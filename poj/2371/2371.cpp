/*
 *  Problem : "Questions and answers"
 *  ID      : 2371
 *  Date    : 2011-03-15
 *  Idea    : 這題的題意真的是很糟糕，所以如果看不懂絕對不是自己英文太差 ... 是他寫的真的很糟，
 *            大意是說，它的 Input 以 "###" 分成前後兩個部分，前者是 Database 而後者是 Queries 
 *            然後要把 Database 的值先做排序，最後再依 Queries 的順序去把它們一個一個印出來。
 *            這題不難，難的是看懂他的英文 ... 
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdio.h>
#define DB_MAX 102000
#define QUERIES_MAX 200
using namespace std;

int cmp(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int main() {

  int N, K;
  int db[DB_MAX] = {0};
  int queries[QUERIES_MAX] = {0};
  char symbols[4];

  scanf("%d", &N);

  // DB part
  for (int i = 0; i < N; i++) {
    scanf("%d", &db[i]);
  }

  // get rid of '\n'
  getchar(); 
  cin.getline(symbols, 4); // ###

  scanf("%d", &K);

  // Queries part
  for (int i = 0; i < K; i++) {
    scanf("%d", &queries[i]);
  }

  qsort(db, N, sizeof(int), cmp);

  for (int i = 0; i < K; i++) {
    printf("%d\n", db[ queries[i] - 1 ]);
  }

  return 0;
}
