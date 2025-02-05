#include <algorithm>
#include <gtest/gtest.h>
#include <set>
#include <string>
#include <vector>

using std::vector;
using std::string;

int equalPairs(vector<vector<int>>& grid) {
  vector<vector<int>> rows;
  vector<vector<int>> columns;
  
  
  for(const auto& row : grid){
    vector<int> temp_row;
    for(const auto& i : row){
      temp_row.emplace_back(i);
    }
    rows.emplace_back(temp_row);
  }
  
  for(int i = 0; i<grid[0].size(); ++i){
    vector<int> temp_column;
    for(int j = 0; j<grid.size(); ++j){
      temp_column.emplace_back(grid[j][i]);
    }
    columns.emplace_back(temp_column);
  }
  int anwser = 0;
  for(auto row : rows){
    anwser += std::count(columns.begin(),columns.end(),row);
  }
  return anwser;
}

TEST(equalPairsSuite, equalPairs)
{
  vector<vector<int>> input{{3,2,1},{1,7,6},{2,7,7}};
  constexpr int correct{1};
  EXPECT_EQ(equalPairs(input), correct);
}
TEST(equalPairsSuite, equalPairsOnes)
{
  vector<vector<int>> input{{1,1,1},{1,1,1},{1,1,1}};
  constexpr int correct{9};
  EXPECT_EQ(equalPairs(input), correct);
}
TEST(equalPairsSuite, equalPairsFourByFour)
{
  vector<vector<int>> input{{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
  constexpr int correct{3};
  EXPECT_EQ(equalPairs(input), correct);
}
