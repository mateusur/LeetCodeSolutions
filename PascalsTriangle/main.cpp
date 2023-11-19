#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> generate(int numRows) {
  vector<vector<int>> pascalTriangle;
  for (int i = 1; i <= numRows; ++i) {
    pascalTriangle.emplace_back(vector<int>(i, 1));
  }
  for (int i = 2; i < numRows; ++i) {
    for (int j = 1; j < pascalTriangle.at(i).size() - 1; ++j) {
      pascalTriangle.at(i).at(j) =
          pascalTriangle.at(i - 1).at(j - 1) + pascalTriangle.at(i - 1).at(j);
    }
  }
  return pascalTriangle;
}

int main() {
  generate(5);
}