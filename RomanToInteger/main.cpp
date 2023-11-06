#include <iostream>
#include <map>
#include <string>

using namespace std;
int romanToInt(string s) {
  int anwser = 0;
  int current, previous = 0;
  map<char, int> mapper = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                           {'C', 100}, {'D', 500}, {'M', 1000}};
  for (auto i = s.rbegin(); i != s.rend(); ++i) {
    current = mapper[*i];
    if (current < previous) {
      anwser -= current;
    } else {
      anwser += current;
    }
    previous = current;
  }
  return anwser;
}
int main() {
  cout << romanToInt("III") << endl;
  cout << romanToInt("LVIII") << endl;
}