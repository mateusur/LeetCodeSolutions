#include <vector>
#include <numeric>
using std::vector;
int pivotIndex(vector<int>& nums) {
    int l_sum = 0;
    int p_sum = accumulate(nums.begin()+1,nums.end(),0);
    if(p_sum == l_sum){
        return 0;
    }
    int index = 1;
    
    while (index < nums.size())
    {
        l_sum += nums[index-1];
        p_sum -= nums[index];
        if(p_sum == l_sum){
            return index;
        }
        ++index;
    }
    return -1;
}

int main(){
    vector<int> v0{1,7,3,6,5,6};
    pivotIndex(v0);
    vector<int> v1{1,2,3};
    pivotIndex(v1);
    vector<int> v2{2,1,-1};
    pivotIndex(v2);
    vector<int> v3{2};
    pivotIndex(v3);

    return 0 ;
}