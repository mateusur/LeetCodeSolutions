#include <iostream>

using namespace std;
// Runtime 4ms Beats 30.51%of users with C++
// Memory 6.2MB Beats 94.14%of users with C++
int hammingWeight(uint32_t n) {
  int anwser = 0;
  for (int i = 0; i < 32; ++i) {
    if (n & (1 << i)) {
      anwser++;
    }
  }
  return anwser;
}
int main() {}