/*
 *  Problem : "Ultra-QuickSort"
 *  ID      : 10810
 *  Date    : 2011-03-15
 *  Idea    : 這題可以學到很多東西，雖然題目是叫 Quick Sort ，但是它卻要求我們要記錄 swap 的次數，
 *            因此第一時間想到的就是 10327 題的 Flip Sort （即 Bubble Sort），不過這題是其進階版，
 *            最大的問題就是要克服 TLE 的問題（ O(n^2) 一定會超過 3 秒），所以我們從 Merge Sort 下手
 *            然後發現 Merge Sort 其 Left Array & Right Array 之間其實存在一個很奇妙的關係，要記錄
 *            Swap 次數是要在 L > R 的時候才需要，而且公式就是 n1 - i + 1（可在紙上演練一下）。
 *
 *            另外要注意一下就是 count 可能 overflow ，記得 long long !
 *  Author  : EragonJ
 */
#include <iostream>
#define MAX 502000
using namespace std;

long long int count = 0;

void merge(int A[], int p, int q, int r) {
  extern long long int count;

  int n1 = q - p + 1;
  int n2 = r - q;

  int* L = (int*) malloc((n1 + 1) * sizeof(int));
  int* R = (int*) malloc((n2 + 1) * sizeof(int));

  for (int i = 1; i <= n1; i++) {
    L[i] = A[p + i - 1];
  }

  for (int i = 1; i <= n2; i++) {
    R[i] = A[q + i];
  }

  int i, j, k;
  for (k = p, i = 1, j = 1; (k <= r) && (i <= n1) && (j <= n2); k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
      count += (n1 - i + 1); // Important formula
    }
  }

  for (i; i <= n1; i++) {
    A[k++] = L[i]; 
  }

  for (j; j <= n2; j++) {
    A[k++] = R[j];
  }
}

void merge_sort(int A[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(A, p, q); 
    merge_sort(A, q + 1, r);
    merge(A, p, q, r);
  }
}

int main() {

  int n;
  int input[MAX] = {0};
  while (scanf("%d", &n) == 1) {
    if (n == 0) {
      break;
    }

    for (int i = 0; i < n; i++) {
      // Index range : 1 ~ n;
      scanf("%d", &input[i + 1]);
    }

    merge_sort(input, 1, n);

    extern long long int count;
    cout << count << endl;

    count = 0;
  }

  return 0;
}
