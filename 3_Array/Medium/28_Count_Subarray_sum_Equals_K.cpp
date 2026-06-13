#include <bits/stdc++.h>
using namespace std;

// Q28: Count Subarray sum Equals K
/*
Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.
A subarray is a contiguous non-empty sequence of elements within an array.

Examples
Input : N = 4, array[] = {3, 1, 2, 4}, k = 6
Output: 2
Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

Input: N = 3, array[] = {1,2,3}, k = 3
Output: 2
Explanation: The subarrays that sum up to 3 are [1, 2], and [3].
*/

// ! 1. Brute Force Approach
void bruteForceApproach(vector<int> &arr, int k) {

  // Total T.C: O()
  // Total S.C: O()
}

// ! 2. Better Approach
void betterApproach() { 
}

// ! 3. Optimal Approach
int optimalApproach(vector<int> &arr, int k) {
  int n = arr.size();

  unordered_map<int, int> mpp;
  int prefixSum = 0;
  int count = 0;

  mpp[0] = 1;

  for(int i = 0; i < n; i++) {
    prefixSum += arr[i];

    if(mpp.find(prefixSum - k) != mpp.end()) {
      count += mpp[prefixSum - k];
    }

    mpp[prefixSum] += 1;
  }

  return count;

  // Total T.C: O(n)
  // Total S.C: O(n)
}

int main() {
  // bruteForceApproach();
  // betterApproach()
  vector<int> arr = {3, 1, 2, 4};
  int k = 6;

  vector<int> arr2 = {3, 9, -2, 4, 1, -7, 2, 6, -5, 8, -3, -7, 6, 2, 1};
  int k2 = 5;
  int count = optimalApproach(arr2, k2);
  cout << "Count: " << count;
}