#include <bits/stdc++.h>
using namespace std;

// Q11: Count Maximum Consecutive One's in the array

/*
Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

Examples
Example 1:
Input: prices = {1, 1, 0, 1, 1, 1}
Output: 3
Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Example 2:
Input: prices = {1, 0, 1, 1, 0, 1} 
Output: 2
Explanation: There are two consecutive 1's in the array. 
*/

int maximumConsecutiveOnes(vector<int>& arr) {
  int n = arr.size();

  // Variable to store current count of consecutive 1's
  int count = 0;
  // Variable to store maximum consecutive 1's
  int maxCount = 0;

  for(int i = 0; i < n; i++) {
    // If current element is 1, increment count
    if(arr[i] == 1) {
      count++;
    } else {
      // If element is 0, reset count
      count = 0;
    }

    // Update maximum if current count is greater
    maxCount = max(maxCount, count);
  }

  return maxCount;
  // Total T.C: O(n)
  // Total S.C: O(1)
}

int main() {
  vector<int> arr = {1, 1, 0, 1, 1, 1, 0, 1, 1};
  int ans = maximumConsecutiveOnes(arr);
  cout << "ans: " << ans;
}