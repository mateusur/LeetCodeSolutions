#include <iostream>
#include <vector>

using namespace std;

// Too slow
int maxProfit2(vector<int>& prices) {
  int best_profit = 0;
  int temp;
  int left_price;
  for (size_t left = 0; left < prices.size() - 1; ++left) {
    left_price = prices[left];
    for (size_t right = left + 1; right < prices.size(); ++right) {
      if (prices[right] > left_price) {
        temp = prices[right] - left_price;
        if (temp > best_profit) {
          best_profit = temp;
        }
      }
    }
  }
  return best_profit;
}
// Runtime: 112 ms, Beats 7.53%of users with C++.
// Memory Usage: 93.69 MB, Beats 57.00%of users with C++.
int maxProfit(vector<int>& prices) {
  int best_profit = 0;
  int smallest_yet = INT_MAX;
  for (int i = 0; i < prices.size(); ++i) {
    if (prices[i] < smallest_yet) {
      smallest_yet = prices[i];
    } else if (prices[i] - smallest_yet > best_profit) {
      best_profit = prices[i] - smallest_yet;
    }
  }
  return best_profit;
}
int main() {
  vector<int> prices1 = {7, 1, 5, 3, 6, 4};
  vector<int> prices2 = {7, 6, 4, 3, 1};
  cout << maxProfit(prices1) << endl;
  cout << maxProfit(prices2) << endl;
}