#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool isValid(string s) {
  stack<char> st;
  char read_char;
  for (int i = 0; i < s.length(); ++i) {
    read_char = s[i];
    if (read_char == '(' || read_char == '{' || read_char == '[') {
      st.emplace(read_char);
    } else {
      if (st.empty()) {
        return false;
      } else {
        char top = st.top();
        switch (top) {
          case '(':
            if (read_char == ')') {
              st.pop();
            } else {
              return false;
            }
            break;
          case '{':
            if (read_char == '}') {
              st.pop();
            } else {
              return false;
            }
            break;
          case '[':
            if (read_char == ']') {
              st.pop();
            } else {
              return false;
            }
            break;
        }
      }
    }
  }
  if (st.empty()) {
    return true;
  }
  return false;
}
int main() {
  cout << isValid("()[]{}") << endl;
  cout << isValid("(]") << endl;
}