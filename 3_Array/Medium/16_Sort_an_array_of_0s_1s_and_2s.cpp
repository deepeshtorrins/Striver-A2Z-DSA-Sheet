#include <bits/stdc++.h>
using namespace std;

// ! Q16: Sort an array of 0s, 1s and 2s
/*
Problem Statement: Given an array nums consisting of only 0, 1, or 2. 
Sort the array in non-decreasing order. The sorting must be done in-place, without making a copy of the original array.

Examples
Input: nums = [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two

Input: nums = [0, 0, 1, 1, 1]
Output: [0, 0, 1, 1, 1]
Explanation: The nums array in sorted order has 2 zeroes, 3 ones and zero twos.
*/

// ! 1. Brute Force Approach (Use Merge Sort)
void bruteForceApproach() {  
  // Use merge sort

  // Total T.C: O(nlogn)
  // Total S.C: O(n)
}

// ! 2. Better Approach
void betterApproach(vector<int> &arr) {
  int n = arr.size();
  int countZero = 0;
  int countOne = 0;
  int countTwo = 0;

  for(int i = 0; i < n; i++) {
    if(arr[i] == 0) countZero++;
    if(arr[i] == 1) countOne++;
    if(arr[i] == 2) countTwo++;
  }

  for(int i = 0; i < countZero; i++) arr[i] = 0;
  for(int i = countZero; i < countZero + countOne; i++) arr[i] = 1;
  for(int i = countZero + countOne; i < countZero + countOne + countTwo; i++) arr[i] = 2;
}

// ! 3. Optimal Approach (Dutch National Flag Algorithm)
void optimalApproach(vector<int> &arr) {
  // still pending...
}

int main() {
  vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0};
  int n = arr.size();
  // bruteForceApproach();
  betterApproach(arr);
  // optimalApproach();

  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}