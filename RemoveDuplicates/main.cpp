#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printVector(const vector<int>& nums){
  for(const int& number : nums){
    cout << number << ' ';
  }
  cout << endl;
}
int removeDuplicates(vector<int>& nums) {
  size_t size = nums.size();
  int swap_counter = 0;
  int i = 0;
  while (i < size) {
    int j = i + 1;
    while (j < size && nums[i] == nums[j]) {
      swap_counter++;
      nums[j] = 255;
      j++;
    }
    i=j;
  }
  std::sort(nums.begin(), nums.end());
  printVector(nums);
  return size-swap_counter;
}
int main() {
  vector<int> nums = {0,0,1,1,1,1,2,2,3,3,4};
  cout << removeDuplicates(nums) << endl;
  cout << endl << endl;
  nums = {1,1,2};
  cout << removeDuplicates(nums) << endl;
}