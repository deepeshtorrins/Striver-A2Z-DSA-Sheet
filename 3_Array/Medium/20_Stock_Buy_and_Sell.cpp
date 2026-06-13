#include <bits/stdc++.h>
using namespace std;

// Q20: Stock Buy And Sell
/*
Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.

Examples

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

// ! 1. Brute Force Approach
void bruteForceApproach() {
  // Total T.C: O()
  // Total S.C: O()
}

// ! 3. Optimal Approach
int optimalApproach(vector<int> & arr) {
  int n = arr.size();
  int minPriceForBuy = arr[0];
  int maxProfit = 0; // profit can be zero but not negative

  for(int i = 1; i < n; i++) {
    int calProfit = arr[i] - minPriceForBuy;

    maxProfit = max(calProfit, maxProfit);

    minPriceForBuy = min(arr[i], minPriceForBuy);
  }

  return maxProfit;

  // Total T.C: O(n)
  // Total S.C: O(1)
}

int main() {
  // bruteForceApproach();
  vector<int> arr = {7,1,5,3,6,4};
  int ans = optimalApproach(arr);
  cout << "Ans: " << ans;
}
