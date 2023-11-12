#include <iostream>
#include <vector>

using namespace std;
vector<int> plusOne(vector<int>& digits){
  digits.at(digits.size()-1) +=1;
  for(size_t i=digits.size()-1;i>=1;--i){
    if(digits.at(i)==10){
      digits.at(i) = 0;
      digits.at(i-1)+=1;
    }
    else{
      break;
    }
  }
  if(digits.at(0)==10){
    digits.at(0) = 0;
    digits.insert(digits.begin(),1);
  }
  return digits;
}
int main() {
  vector<int> digits = {4,3,2,1};
  vector<int> digits2 = {9};
  plusOne(digits);
  plusOne(digits2);
}