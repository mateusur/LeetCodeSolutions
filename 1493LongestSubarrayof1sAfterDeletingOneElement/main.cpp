#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int l=0,r=0;
    int cmax=0;
    int to_erase=1;
    while (r<nums.size())
    {
        if(nums[r]==1){
            r++;
        }else if(nums[r]==0 && to_erase==1){
            r++;
            to_erase--;
        }else if(nums[r]==0 && to_erase==0){
            cmax = max(cmax,r-l-1);
            while (nums[l]==1 && l<r)
            {
                l++;
            }
            l++;
            to_erase++;
        }
    }
    
    return max(cmax,r-l-1);;    
}
int main(){
    vector<int> v0{1,1,0,1};
    longestSubarray(v0);
    vector<int> v1{0,1,1,1,0,1,1,0,1};
    longestSubarray(v1);
    vector<int> v2{1,1,1};
    longestSubarray(v2);
    return 0 ;
}