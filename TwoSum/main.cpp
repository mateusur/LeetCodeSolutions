#include <iostream>
#include <vector>
using std::vector;

vector<int> twoSum(vector<int>& nums, int target) {
         vector<int> anwser;
        for(int i=0; i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                if(nums.at(i)+nums.at(j)==target){
                   anwser.push_back(i);
                   anwser.push_back(j);
                    return anwser;
                }
            }
        }
        return anwser;
}

int main(){
    vector<int> nums{2,7,11,15};
    int target{9};
    vector<int> anwser{0,1};
    if(twoSum(nums,target) == anwser){
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test failed" << std::endl;
    }
}