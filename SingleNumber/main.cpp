#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Runtime 12ms Beats 73.96%of users with C++
//Memory 17.30MB Beats 48.62%of users with C++
int singleNumber(vector<int>& nums) {
  if (nums.size() == 1) {
    return nums[0];
  }

  sort(nums.begin(), nums.end());
  int i = 0;
  int j = 1;
  while (nums[i] == nums[j]) {
    i += 2;
    j += 2;
  }
  return nums[i];
}
int main() {
  vector<int> v1 = {2,2,1};
  vector<int> v2 = {4,1,2,1,2};
  cout << singleNumber(v1) << endl; 
  cout << singleNumber(v2) << endl; 
}