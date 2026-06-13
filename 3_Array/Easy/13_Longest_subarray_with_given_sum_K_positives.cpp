#include <bits/stdc++.h>
using namespace std;

// ! Q13: Longest Subarray with given Sum K (Positives)
/*
Problem Statement: Given an array nums of size n and an integer k, 
find the length of the longest sub-array that sums to k.
If no such sub-array exists, return 0.

Example 1:
Input: nums = [10, 5, 2, 7, 1, 9], k = 15  
Output: 4  
Explanation: The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. 
This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. 
Therefore, the length of this sub-array is 4.

Example 2:
Input: nums = [-3, 2, 1], k = 6  
Output: 0  
Explanation: There is no sub-array in the array that sums to 6. Therefore, the output is 0.
*/

// ! 1. Brute Force Approach
int bruteForceApproach(vector<int> &arr, int k) {
  int n = arr.size();

  int longestLen = 0;
  for(int i = 0; i < n; i++) {
    int sum = 0;
    for(int j = i; j < n; j++) {
      sum = sum + arr[j];

      if(sum == k) {
        longestLen = max(longestLen, j - i + 1);
      }
    }
  }

  return longestLen;

  // Total T.C: O(n*n)
  // Total S.C: O(1)
}

// ! 2. Better Approach (using Prefix Sum)
// https://www.youtube.com/watch?v=VFF6qWfAql0
int betterApproach(vector<int> &arr, int k) {
  int n = arr.size();
  
  int prefixSum = 0;
  int longestLen = 0;
  map<long long, int> mp;

  for(int i = 0; i < n; i++) {
    prefixSum = prefixSum + arr[i];

    // find longest length if prefixSum is equal to 'k'
    if(prefixSum == k) {
      longestLen = max(longestLen, i+1);
    }

    // push prefixSum in map if it is not present
    if(mp.find(prefixSum) == mp.end()) {
      mp[prefixSum] = i;
    }

    // 
    if(mp.find(prefixSum - k) != mp.end()) {
      longestLen = max(longestLen,  i - mp[prefixSum - k]);
    }
  }

  return longestLen;

  // Total T.C: O(n*logn) if I am using ordered map
  // Total T.C: O(n*1) or O(n*n) if I am using unordered map
  // Total S.C: O(n)
}

// ! 3. Optimal Approach (two pointers approach)
int optimalApproach(vector<int> &arr, int k) {
  int n = arr.size();
  int longestLen = 0;
  // pending need to complete

  return longestLen;
}


int main() {
  vector<int> arr = {10, 5, 2, 7, 1, -10};
  int k = 15;

  // int ans = bruteForceApproach(arr, k);
  // int ans = betterApproach(arr, k);
  int ans = optimalApproach(arr, k);

  cout << "ans: " << ans;

}