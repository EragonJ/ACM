#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;

typedef struct MyNode {
  float x1, y1, x2, y2, coefficient;
} NODE_TYPE;

int cmp(const void* a, const void* b) {
  NODE_TYPE* _a = (NODE_TYPE*)a;
  NODE_TYPE* _b = (NODE_TYPE*)b;
  return (_a->x1 - _b->x1);
}

int main() {

  int cases;
  scanf("%d", &cases);

  for (int i = 0; i < cases; i++) {

    // two consecutive cases will be separated by a blank line
    if (i >= 1) {
      printf("\n");
    }

    int NL;
    scanf("%d", &NL);

    float max_x1;

    // Input
    NODE_TYPE* node = (NODE_TYPE*) malloc(NL * sizeof(NODE_TYPE));
    for (int j = 0; j < NL; j++) {
      scanf("%f %f %f %f %f", &node[j].x1, &node[j].y1, &node[j].x2, &node[j].y2, &node[j].coefficient); 
      
      // Make x1 smaller than x2
      if (node[j].x1 > node[j].x2) {
        swap(node[j].x1, node[j].x2);
        swap(node[j].y1, node[j].y2);
      }

      // Store the max of x1
      if (j == 0) {
        max_x1 = node[j].x1;
      }
      else {
        max_x1 = (max_x1 < node[j].x1) ? node[j].x1 : max_x1;
      }
    }

    // sort by x1
    qsort(node, NL, sizeof(NODE_TYPE), cmp);

    // sort all points in a seg list
    map <float, float> seg;
    for (int j = 0; j < NL; j++) {

      float x1 = node[j].x1;
      float x2 = node[j].x2;
      float coefficient = node[j].coefficient;

      seg[ x1 ] = coefficient;
      seg[ x2 ] = coefficient;
    }

    // Traverse all nodes in a seg list
    for (map <float, float>::iterator k = seg.begin(); k != seg.end(); k++) {

      for (int j = 0; j < NL; j++) {

        float x1 = node[j].x1;
        float x2 = node[j].x2;
        float coefficient = node[j].coefficient;

        // If there is one point within x1 ~ x2
        if ((*k).first < x2 && (*k).first > x1) {
          (*k).second *= coefficient;
        }
      }
    }

    map <float, float>::iterator temp = seg.begin();
    printf("%s %.3f 1.000\n", "-inf", (*temp).first);

    for (map <float, float>::iterator j = seg.begin(); j != seg.end(); j++) {
    
      // get the next one
      map <float, float>::iterator k = ++j;
      --j;

      // don't print the last one
      if (k == seg.end()) {
        break;
      }

      if ( (*j).first <= max_x1 ) {
        printf("%.3f %.3f %.3f\n", (*j).first, (*k).first, (*j).second);
      }
      else {
        printf("%.3f %.3f %.3f\n", (*j).first, (*k).first, (*k).second);
      }
    }

    temp = --seg.end();
    printf("%.3f %s 1.000\n", (*temp).first, "+inf");
  }

  return 0;
}
