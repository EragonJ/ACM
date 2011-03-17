/*
 *  Problem : "DNA Sorting"
 *  ID      : 1007
 *  Date    : 2011-03-12
 *  Idea    : 題目不難，但是因為想要寫的漂亮，所以用了 structure + qsort（順便複習一下），
 *            然後試著找出可以提昇效率的地方（在 get_inversion 內）
 *  Author  : EragonJ
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define MAX 100

using namespace std;

// This structure is helpful when sorting by inversion
typedef struct DNA_BASIC {
  char* DNA;
  int inversion;
} DNA_INFO;

char* create_DNA(int n) {

  char* DNA = (char*)malloc(n * sizeof(char));
  return DNA;
}

int get_inversion(char DNA[]) {

  int length = strlen(DNA);
  int inversion = 0;

  for (int i = 0; i < length - 1; i++) {

    // This will enhace 16 MS
    if (DNA[i] == 'A') {
      continue;
    }

    for (int j = i + 1; j < length; j++) {
      if (DNA[i] > DNA[j]) {
        inversion++;
      }
    }
  }

  return inversion;
}

int compare(const void* a, const void* b) {
  DNA_INFO* _a = (DNA_INFO*) a;
  DNA_INFO* _b = (DNA_INFO*) b;
  return (_a->inversion - _b->inversion);
}

int main() {

  int n, m;
  cin >> n >> m;
  getchar();

  // Create a list of DNA_INFO which stores DNA and inversion
  DNA_INFO DNA_list[MAX];

  for (int i = 0; i < m; i++) {

    // Store each DNA sequence into DNA_list[i].DNA first
    DNA_list[i].DNA = create_DNA(n);
    scanf("%s", DNA_list[i].DNA);

    // Use the fetched DNA sequence to get inversion and store it into DNA_list[i].inversion
    DNA_list[i].inversion = get_inversion(DNA_list[i].DNA);
  }

  qsort(DNA_list, m, sizeof(DNA_INFO), compare);

  // Result
  for (int i = 0; i < m; i++) {
    printf("%s\n", DNA_list[i].DNA);
  }

  return 0;
}
