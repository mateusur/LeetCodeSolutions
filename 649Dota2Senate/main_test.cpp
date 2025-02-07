#include <gtest/gtest.h>
#include <queue>
#include <string>

using std::string;

string predictPartyVictory(string senate)
{
  std::queue<int> R;
  std::queue<int> D;
  const int size = senate.size();
  for (int i = 0; i < size; ++i) {
    if (senate[i] == 'R') {
      R.push(i);
    } else {
      D.push(i);
    }
  }
  int r_top;
  int d_top;
  while (!R.empty() && !D.empty()) {
    r_top = R.front();
    d_top = D.front();
    if (r_top < d_top) {
      D.pop();
      R.pop();
      R.push(r_top + size);
    } else {
      R.pop();
      D.pop();
      D.push(d_top + size);
    }
  }
  return R.empty() ? "Dire" : "Radiant";
}
TEST(predictPartyVictorySuite, predictPartyVictory)
{
  string input{ "RD" };
  string correct{ "Radiant" };

  EXPECT_EQ(predictPartyVictory(input), correct);
}
TEST(predictPartyVictorySuite, predictPartyVictory2)
{
  string input{ "RDD" };
  string correct{ "Dire" };

  EXPECT_EQ(predictPartyVictory(input), correct);
}
