/*
 *  Problem : "List of Conquests"
 *  ID      : 10420
 *  Date    : 2011-03-15
 *  Idea    : 題目的人名不重要，只要記錄出現幾次國家名即可，愛用 STL Map。
 *  Author  : EragonJ
 */
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#define MAX 2200
#define NAME_LENGTH 75
using namespace std;

int main() {

  int n;
  cin >> n;

  // discard '\n'
  getchar();

  char names[MAX][NAME_LENGTH];
  map <string, int> country_list;

  for (int i = 0; i < n; i++) {
    cin.getline(names[i], NAME_LENGTH);

    // strtok to get the country_name and insert into map
    string country_name = strtok(names[i], " ");
    country_list[country_name] ++;
  }

  // iterate the map
  for (map <string, int>::iterator i = country_list.begin(); i != country_list.end(); i++) {
    cout << (*i).first << " " << (*i).second << endl;
  }

  return 0;
}
