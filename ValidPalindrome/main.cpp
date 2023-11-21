#include <iostream>
#include <string>
using namespace std;
//Runtime 4ms Beats 80.46%of users with C+
//7.56MB 81.75%of users with C++
bool isPalindrome(string s) {
  for (char& c : s) {
    if (c >= 65 && c <= 90) {
      c += 32;
    }
  }

  int i = 0;
  int j = s.size() - 1;
  char left_char;
  char right_char;
  while (i < j) {
    left_char = s[i];

    if ((left_char < 97 || left_char > 122) &&
        (left_char < 48 || left_char > 57)) {
      i++;
      continue;
    }
    right_char = s[j];
    if ((right_char < 97 || right_char > 122) &&
        (right_char < 48 || right_char > 57)) {
      j--;
      continue;
    }
    if (left_char != right_char) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}
int main() {
  string s = "A man, a plan, a canal: Panama";
  cout << isPalindrome(s);
  string s2 = "race a car";
  cout << isPalindrome(s2);
  string s3 = "0P";
  cout << isPalindrome(s3);
}