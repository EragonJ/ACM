#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 1200
using namespace std;

typedef struct INFO {
  int index;
  int rating;
  bool played;
} SONG_INFO;

int cmp (const void* a, const void* b) {
  SONG_INFO* _a = (SONG_INFO*) a;
  SONG_INFO* _b = (SONG_INFO*) b;

  // if ratings are equal
  if (_b->rating == _a->rating) {

    // sort by index ASC
    return (_a->index - _b->index);
  }

  // if not equal, sort by rating DESC
  return (_b->rating - _a->rating);
}

int main() {

  int N, T;
  scanf("%d %d", &N, &T);

  SONG_INFO song[MAX];
  for (int i = 0; i < N; i++) {
    song[i].index = i + 1;
    scanf("%d", &song[i].rating); 
  }


  for (int i = 0; i < T; i++) {

    // sort by desc
    qsort(song, N, sizeof(SONG_INFO), cmp);

    int played_song_rating = song[0].rating;
    song[0].rating = 0;

    int each_rating = played_song_rating / (N - 1);
    int remain_rating = played_song_rating % (N - 1);

    for (int i = 1; i < N; i++) {
      song[i].rating += each_rating;

      if ((i <= remain_rating) && (song[i].rating != 0)) {
        song[i].rating += 1;
      }
    }

    for (int i = 1; remain_rating != 0; i = (i + 1) % N) {

      if (song[i].rating != 0) {
        song[i].rating += 1;
        remain_rating--;
      }
    }

    printf("%d\n", song[0].index);
  }

  return 0;
}
