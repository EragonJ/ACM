/*
 *  Problem : "Word Amalgamation"
 *  ID      : 1318
 *  Date    : 2011-03-12
 *  Idea    : 除了熟悉 qsort 的用法外， is_match 是比較有趣的地方，這樣子的做法只要 O(n) 而不用 O(n^2)。
 *            還有 string functions 的用法。
 *  Author  : EragonJ
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX 120
#define ALPHA_LENGTH 26

using namespace std;

char dictionary[MAX][10];
char scramble[MAX][10];

bool is_match(char scramble[], char dictionary[]) {

  // scramble's length is equal to dictionary's length
  int length = strlen(scramble);
  int scr_list[ALPHA_LENGTH] = {0};
  int dic_list[ALPHA_LENGTH] = {0};

  for (int i = 0; i < length; i++) {
    scr_list[scramble[i] - 'a'] ++;
    dic_list[dictionary[i] - 'a'] ++;
  }

  for (int i = 0; i < ALPHA_LENGTH; i++) {
    if (scr_list[i] != dic_list[i]) {
      return false;
    }
  }

  return true;
}

void search_and_print(int dic_index, int scr_index) {

  int count;

  for (int i = 0; i < scr_index; i++) {

    count = 0;
    for (int j = 0; j < dic_index; j++) {
      
      // Use short circuit evalutaion to speed up
      if (strlen(scramble[i]) == strlen(dictionary[j]) && is_match(scramble[i], dictionary[j])) {
        count ++;
        printf("%s\n", dictionary[j]);
      }
    }

    if (count != 0) {
      printf("******\n");
    }
    else {
      printf("NOT A VALID WORD\n");
      printf("******\n");
    }
  }
}

int cmp (const void* a, const void* b) {
  return strcmp((const char*)a, (const char*)b);
}

int main() {

  int end = 0;
  int dic_index = 0;
  int scr_index = 0;

  while (end < 2) {
    char temp[10];
    cin >> temp;

    if (temp[0] == 'X') {
      end++;
      continue;
    }

    if (end == 0) {
      strcpy(dictionary[dic_index++], temp);
    } 
    else if (end == 1) {
      strcpy(scramble[scr_index++], temp);
    }
  }

  qsort(dictionary, dic_index, 10 * sizeof(char), cmp);
  search_and_print(dic_index, scr_index);

  return 0;
}
