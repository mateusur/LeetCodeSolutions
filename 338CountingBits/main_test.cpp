#include <bit>
#include <gtest/gtest.h>
#include <vector>
using std::vector;

vector<int> CountBits(unsigned int n)
{
  vector<int> anwser;
  for (unsigned int i = 0; i <= n; ++i) { anwser.push_back(std::popcount(i)); }
  return anwser;
}

TEST(countBitsSuite, countBits)
{
  constexpr unsigned int kInput{ 5 };
  vector<int> correct{ 0, 1, 1, 2, 1, 2 };
  EXPECT_EQ(CountBits(kInput), correct);
}
