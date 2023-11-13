#include <iostream>

using namespace std;
int mySqrt(int x) {
  int left = 0;
  int right = x;
  int middle = x / 2;
  int best = INT_MAX;
  int err = INT_MAX;
  do {
    err = x - (middle * middle);
    if (err == 0) {
      best = middle;
      break;
    } else if (err < 0) {
      right = middle - 1;
    } else {
      best = middle;
      left = middle + 1;
    }
    middle = (right + left) / 2;

  } while (left <= right);
  return best;
}

int main() {
    mySqrt(9);
    mySqrt(8);
}