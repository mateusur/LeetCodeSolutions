#include <iostream>

using namespace std;
// Runtime 0ms Beats 100%of users with C++
// Memory 6.2MB Beats 99.35%of users with C++
    int getNextSum(int n){
        int sum =0;
        while(n>9){
            sum += pow(n%10,2);
            n/=10;
        }
        sum += pow(n%10,2);
        return sum;
        
    }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = getNextSum(n);
        while(fast != 1 && fast != slow){
            slow = getNextSum(slow);
            fast = getNextSum(getNextSum(fast));
        }
        if(fast==1){
            return true;
        }
        return false;
    }
int main() {}