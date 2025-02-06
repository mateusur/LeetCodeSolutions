#include <gtest/gtest.h>
#include <string>
#include <vector>
using std::vector;

int compress(vector<char> &chars)
{
  int i = 0;
  int j = 1;
  int index_to_change = 0;
  while (i < chars.size() && j <= chars.size()) {
    while (j < chars.size() && chars[i] == chars[j]) { ++j; }
    chars[index_to_change] = chars[i];
    ++index_to_change;
    if (j - i > 1) {
      std::string s = std::to_string(j - i);
      for (const char &c : s) {
        chars[index_to_change] = c;
        ++index_to_change;
      }
    }
    i = j;
    ++j;
  }

  return index_to_change;
}
TEST(compressSuite, compress)
{
  vector<char> input{ 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
  int correct{ 6 };

  EXPECT_EQ(compress(input), correct);
}
TEST(compressSuite, compress2)
{
  vector<char> input{ 'a', 'b', 'c' };
  int correct{ 3 };

  EXPECT_EQ(compress(input), correct);
}