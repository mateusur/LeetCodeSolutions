#include <iostream>
#include <vector>
using namespace std;
// Runtime 7ms Beats 76.36% of users with C++
// Memory 7.6MB Beats 78.90% of users with C++
bool isAnagram(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }
  vector<int> count(128);
  for (const char& c : s) {
    count[c]++;
  }
  for (const char& c : t) {
    if (--count[c] < 0) {
      return false;
    }
  }
  return true;
}
int main() {
  string s = "anagram", t = "nagaram";
  cout << isAnagram(s,t) << endl;
  s = "rat", t = "car";
  cout << isAnagram(s,t) << endl;
}