/*
 *  Problem : "The Land of Justice"
 *  ID      : 10499
 *  Date    : 2011-03-05
 *  Idea    : 通常看到題目很簡單的都要特別去注意邊界情況，因為他們才不會這麼好心讓你輕鬆過關，
 *            所以這一題如果陷進去他的邏輯的話，就會沒考慮到 n == 1 的情況 ... （無恥 xD），而
 *            另外要注意的還是大數問題，所以要記得開 long long int ... =_= 真的很無聊
 *  Author  : EragonJ
 */
#include <iostream>
#include <math.h>
using namespace std;

int main() {

  long long int n;
  while (cin >> n) {
    if (n <= 0) {
      break;
    }
    else if (n == 1) {
      printf("0%%\n");
    }
    else {
      printf("%lld%%\n", (long long int) round((n/4.0)*100));
    }
  }
  return 0;
}
