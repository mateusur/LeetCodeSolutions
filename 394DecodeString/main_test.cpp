#include <algorithm>
#include <gtest/gtest.h>
#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::string;

string decodeString(string s)
{
  int i = 0;
  std::stack<char> st;
  string temp;
  while (i < s.size()) {

    if (s[i] != ']') {
      st.push(s[i]);
    } else {
      temp = "";
      while (st.top() != '[') {
        temp += st.top();
        st.pop();
      }
      st.pop();
      int repeats = 0;
      int multiplier = 1;
      do {
        repeats = ((st.top() - '0') * multiplier) + repeats;
        multiplier *= 10;
        st.pop();
      } while (!st.empty() && isdigit(st.top()));
      std::reverse(temp.begin(), temp.end());
      string multi;
      for (int i = 0; i < repeats; ++i) { multi += temp; }
      for (const char &c : multi) { st.push(c); }
    }
    ++i;
  }
  string anwser;
  while (!st.empty()) {
    anwser += st.top();
    st.pop();
  }
  std::reverse(anwser.begin(), anwser.end());
  return anwser;
}
TEST(decodeStringSuite, decodeString)
{
  string input{ "3[a2[c]]" };
  string correct{ "accaccacc" };

  EXPECT_EQ(decodeString(input), correct);
}
TEST(decodeStringSuite, decodeString2)
{
  string input{ "13[a]2[bc]" };
  string correct{ "aaaaaaaaaaaaabcbc" };

  EXPECT_EQ(decodeString(input), correct);
}
TEST(decodeStringSuite, decodeString3)
{
  string input{ "2[abc]3[cd]ef" };
  string correct{ "abcabccdcdcdef" };

  EXPECT_EQ(decodeString(input), correct);
}
TEST(decodeStringSuite, decodeString4)
{
  string input{ "3[a2[c3[xyz]]]" };
  string correct{ "acxyzxyzxyzcxyzxyzxyzacxyzxyzxyzcxyzxyzxyzacxyzxyzxyzcxyzxyzxyz" };

  EXPECT_EQ(decodeString(input), correct);
}