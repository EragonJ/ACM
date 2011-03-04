/*
 *  Problem : "Tanning Salon"
 *  ID      : 1250
 *  Date    : 2011-03-03
 *  Idea    : 這題有陷阱和題目不符合的地方，題目明明有提到 "Customers who leave without tanning always 
 *            depart before customers who are currently tanning"，不過卻有可能會出現 "1 ABCCAB" 這種情況
 *            在這種情況下答案就是 1 而不是 2，所以要特別處理這種情況。這題有一個很重要的概念就是可以把
 *            'A' 轉換成 0，這樣子我們就可以直接在 index 上做處理，是好用的技巧。
 *  Author  : EragonJ
 */
#include <iostream>
#include <string.h>
#define MAX 300
using namespace std;

void print_result(int left_customer_count) {
  if (left_customer_count == 0) {
    printf("All customers tanned successfully.\n");
  }
  else {
    printf("%d customer(s) walked away.\n", left_customer_count);
  }
}

int search(char stack[], char name) {
  for (int i = 0; i < strlen(stack); i++) {
    if (stack[i] == name) {
      return i;
    }
  }
  return -1;
}

int main() {

  int customer_count;
  while (true) {
    scanf("%d", &customer_count);

    if (customer_count == 0) {
      break;
    }
    else {
      char input[MAX];
      int  customer[MAX] = {0};
      int  left_count = 0;
      scanf("%s", input);

      for (int i = 0; i < strlen(input); i++) {
        int index = input[i]-'A';

        // 1 is using
        if (customer[index] == 1) {
          customer[index] = 0;
          customer_count++;
        }
        else {

          // no matter the customer is waiting or doing nowthing, if we have empty seats,
          // then we just assign them into the seat directly and continue
          if (customer_count > 0) {
            customer[index] = 1; // using
            customer_count--;
            continue;
          }

          // 0 is doing nothing 
          if (customer[index] == 0) {
            customer[index] = 2; // waiting
          }
          // 2 is waiting
          else {
            left_count++; // can't wait anymore !
          }
        }
      }
      print_result(left_count);
    }
  }
  return 0;
}
