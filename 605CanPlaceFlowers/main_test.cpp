#include <gtest/gtest.h>
#include <string>
#include <vector>

using std::vector;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
  int i = 1;
  int max = flowerbed.size() - 1;
  if (flowerbed.size() == 0) {
    return n == 0;
  } else if (flowerbed.size() == 1 && flowerbed[0] == 0) {
    return n <= 1;
  } else if (flowerbed.size() == 1 && flowerbed[0] == 1) {
    return n == 0;
  }
  if (flowerbed[0] == 0 && flowerbed[1] == 0) {
    --n;
    flowerbed[0] = 1;
  }
  while (i < max && n > 0) {
    if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
      --n;
      flowerbed[i] = 1;
    }
    ++i;
  }
  if (n > 0 && flowerbed[max - 1] == 0 && flowerbed[max] == 0) {
    --n;
    flowerbed[max] = 1;
  }
  return n <= 0;
}
TEST(canPlaceFlowersSuite, canPlaceFlowers)
{
  vector<int> input{ 1, 0, 0, 0, 1 };
  int input2{ 1 };
  bool correct{ true };

  EXPECT_EQ(canPlaceFlowers(input, input2), correct);
}
TEST(canPlaceFlowersSuite, canPlaceFlowers2)
{
  vector<int> input{ 1, 0, 0, 0, 1 };
  int input2{ 2 };
  bool correct{ false };

  EXPECT_EQ(canPlaceFlowers(input, input2), correct);
}
