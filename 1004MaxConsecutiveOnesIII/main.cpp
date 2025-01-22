#include <vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int window = nums.size();
    while (window>0)
    {
        int64_t c;
        for(int i =0; i+window<=nums.size();++i){
            int c = count(nums.begin()+i,nums.begin()+i+window,0);
            if (c <= k){
                return window;
            }
        }
        --window;
    }
    return  0;
}
int main(){
    vector<int> v0{1,0,1,1,0};
    longestOnes(v0,2);
    vector<int> v1{1,1,1,0,0,0,1,1,1,1,0};
    longestOnes(v1,2);
    vector<int> v2{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    
    longestOnes(v2,4);
    longestOnes(v2,5);
    return 0 ;
}