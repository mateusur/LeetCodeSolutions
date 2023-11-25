#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
  int majority_element = nums[0];
  int votes = 1;
  for (size_t i = 1; i < nums.size(); ++i) {
    if (votes == 0) {
      majority_element = nums[i];
      votes++;
    } else if (majority_element == nums[i]) {
      votes++;
    } else {
      votes--;
    }
  }
  return majority_element;
}
int main() {
  vector<int> nums = {3,2,3};
  vector<int> nums2 = {2,2,1,1,1,2,2};
  cout << majorityElement(nums) << endl;
  cout << majorityElement(nums2) << endl;
}