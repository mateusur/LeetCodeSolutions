#include <iostream>
#include <vector>
using namespace std;
//To slow
int climbStairsRecursive(int k){
  switch (k)
  {
  case 1:
    return 1;
  case 2:
    return 2;
  default:
    return climbStairsRecursive(k-1) + climbStairsRecursive(k-2);
  }
}
int climbStairsDynamicProgramming(int k){
  vector<int> memory(k+3,-1);
  memory.at(0) = 0;
  memory.at(1) = 1;
  memory.at(2) = 2;
  for(int i = 3; i<=k;++i){
    memory.at(i) = memory.at(i-1) + memory.at(i-2);
  }
  return memory.at(k);
}
int main() {
  cout << climbStairsDynamicProgramming(3) << endl;
  cout << climbStairsDynamicProgramming(2) << endl;
  cout << climbStairsDynamicProgramming(45) << endl;
}