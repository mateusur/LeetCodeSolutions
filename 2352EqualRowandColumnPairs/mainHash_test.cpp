#include <algorithm>
#include <gtest/gtest.h>
#include <map>
#include <vector>

using std::vector;

int equalPairs(vector<vector<int>> &grid)
{
  std::map<vector<int>, int> mp;
  int anwser = 0;
  for (const auto &row : grid) { mp[row]++; }
  for (int i = 0; i < grid[0].size(); ++i) {
    vector<int> temp_column;
    for (int j = 0; j < grid.size(); ++j) { temp_column.emplace_back(grid[j][i]); }
    anwser += mp[temp_column];
  }
  return anwser;
}

TEST(equalPairsSuite, equalPairs)
{
  vector<vector<int>> input{ { 3, 2, 1 }, { 1, 7, 6 }, { 2, 7, 7 } };
  constexpr int correct{ 1 };
  EXPECT_EQ(equalPairs(input), correct);
}
TEST(equalPairsSuite, equalPairsOnes)
{
  vector<vector<int>> input{ { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } };
  constexpr int correct{ 9 };
  EXPECT_EQ(equalPairs(input), correct);
}
TEST(equalPairsSuite, equalPairsFourByFour)
{
  vector<vector<int>> input{ { 3, 1, 2, 2 }, { 1, 4, 4, 5 }, { 2, 4, 2, 2 }, { 2, 4, 2, 2 } };
  constexpr int correct{ 3 };
  EXPECT_EQ(equalPairs(input), correct);
}
