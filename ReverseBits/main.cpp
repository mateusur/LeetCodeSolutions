#include <iostream>
#include <bitset>

using namespace std;
// Runtime 0ms Beats 100%of users with C++
// Memory 6.2MB Beats 93.78%of users with C++
uint32_t reverseBits(uint32_t n) {
  uint32_t anwser = 0;
  for (int i = 0; i < 32; ++i) {
    if (n & (1 << i)) {
      anwser = anwser | (1 << (31 - i));
    }
  }
  return anwser;
}
int main() {
  uint32_t num1 = 0b11111111111111111111111111111101;
  uint32_t num2 = 0b00000010100101000001111010011100;
  cout << std::bitset<32>(reverseBits(num1)) << endl;
  cout << std::bitset<32>(reverseBits(num2)) << endl;

}