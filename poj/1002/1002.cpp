/*
 *  Problem : "487-3279"
 *  ID      : 1002
 *  Date    : 2011-03-11
 *  Idea    : 因為習慣用 Associtative Array ，所以這題用了 STL 的 map 來解題。這題用 map 可以避免掉很多問題，
 *            第一個是因為題目有要求要依 Key 遞增輸出，而這是 map 實作時內部的設計，所以就可以不用再 Sorting，
 *            第二個是因為其與預設值是 0 ，所以直接 ++ 而不需初始化。
 *            第三個是拿來熟悉一下 STL xD ...
 *            
 *            題目有些地方很陰險，就是只能輸出那些出現多於一次的號碼，如果都不大於一次的話，那就要輸出 "No duplicates."
 *            它寫的位置很容易讓人忽略 .... 
 *  Author  : EragonJ
 */
#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#define MAX 512
using namespace std;

bool is_valid (char phone_number) {
  char invalid_pattern = '-';
  if (phone_number == invalid_pattern) {
    return false;
  }
  return true;
}

char transform (char phone_number) {
  char pattern[8][4] = {
    {"ABC"},{"DEF"},{"GHI"},
    {"JKL"},{"MNO"},{"PRS"},
    {"TUV"},{"WXY"}
  };

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++) {
      if (phone_number == pattern[i][j]) {
        return '0' + i + 2;
      }
    }
  }

  return phone_number;
}

string get_standard_form_index(char phone[]) {

  string standard_form;

  for (int i = 0, j = 0; i < strlen(phone); i++) {
    if (j == 3) {
      standard_form += '-';
      j++;
    }

    if (is_valid(phone[i])) {
      standard_form += transform(phone[i]);
      j++;
    }
  }

  return standard_form;
}

int main() {

  // Create associative array of standard_forms
  map <string, int> standard_forms;

  int n;
  cin >> n;

  // Discard "\n"
  getchar();

  // Use associative array to store informations
  for (int i = 1; i <= n; i++) {
    char phone[MAX];
    cin.getline(phone, MAX);
    
    standard_forms[ get_standard_form_index(phone) ]++;
  }

  bool duplicate = false;

  // Print out the result
  for (map <string, int>::iterator i = standard_forms.begin(); i != standard_forms.end(); i++) {

    // which appears more than 1 time
    if ((*i).second > 1) {

      duplicate = true;
      cout << (*i).first << " " << (*i).second << endl;
    }
  }

  if (duplicate == false) {
    cout << "No duplicates." << endl;
  }

  return 0;
}
