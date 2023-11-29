#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Runtime 91ms Beats 80.98%of users with C++
// Memory 57.62MB Beats 86.62%of users with C++
bool containsDuplicate(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  for (int i = 0, j = i + 1; j < nums.size(); ++i, ++j) {
    if (nums[i] == nums[j]) {
      return true;
    }
  }
  return false;
}
int main() {}