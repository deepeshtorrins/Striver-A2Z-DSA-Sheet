#include <bits/stdc++.h>
using namespace std;

// ! Q18: Kadane's Algorithm : Maximum Subarray Sum in an Array
/*
Problem Statement: Given an integer array nums, find the subarray with the largest sum and
return the sum of the elements present in that subarray.
A subarray is a contiguous non-empty sequence of elements within an array.

Examples
Example 1:
Input: nums = [2, 3, 5, -2, 7, -4]  
Output: 15
Explanation: The subarray from index 0 to index 4 has the largest sum = 15, which is the maximum sum of any contiguous subarray.

Example 2:
Input: nums = [-2, -3, -7, -2, -10, -4]  
Output: -2
Explanation: The largest sum is -2, which comes from taking the element at index 0 or index 3 as the subarray.
Since all numbers are negative, the subarray with the least negative number gives the largest sum.
*/

// ! 1. Brute Force Approach
int bruteForceApproach(vector<int> arr) {
  int size = arr.size();
  int maxi = INT_MIN;

  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      int sum = 0;
      for(int k = i; k < j; k++) {
        sum = sum + arr[k];
      }

      if(maxi < sum) {
        maxi = sum;
      }
    }
  }

  return maxi;

  // Total T.C: O(n^3)
  // Total S.C: O(1)
}

// ! 2. Better Approach
int betterApproach(vector<int> arr) {
  int size = arr.size();
  int maxi = INT_MIN;
  
  for(int i = 0; i < size; i++) {
    int sum = 0;
    for(int j = i; j < size; j++) {
      sum = sum + arr[j];

      if(maxi < sum) {
        maxi = sum;
      }
    }
  }

  return maxi;

  // Total T.C: O(n^2)
  // Total S.C: O(1)
}

// ! 3. Optimal Approach (Using Kadane's Algorithm)
/*
"The idea of Kadane's algorithm is to traverse over the array from left to right and for each element,
find the maximum sum among all subarrays ending at that element. 
The result will be the maximum of all these values."


 */
int optimalApproach(vector<int> arr) {
  int size = arr.size();
  int maxi = INT_MIN;

  // current sum of subarray
  int currentSubarraySum = 0;

  // Iterate through the array
  for(int i = 0; i < size; i++) {
    currentSubarraySum = currentSubarraySum + arr[i];

    // Update maxi if current sum is greater
    maxi = max(currentSubarraySum, maxi);

    // Reset sum to 0 if it becomes negative
    if(currentSubarraySum < 0) currentSubarraySum = 0;
  }

  return maxi;

  // Total T.C: O(n)
  // Total S.C: O(1)
}

// ! (Optimal Approach) Follow-up Question: Can you print the subarray that has the maximum sum?
int optimalApproachPrintSubarray(vector<int> arr) {
  int size = arr.size();
  int maxi = INT_MIN;

  // current sum of subarray
  int currentSubarraySum = 0;

  // starting index of current subarray
  int start = 0;

  // indices of the maximum sum subarray
  int ansStart = -1, ansEnd = -1;
  
  // Iterate through the array
  for(int i = 0; i < size; i++) {
    if(currentSubarraySum == 0) start = i;

    currentSubarraySum = currentSubarraySum + arr[i];

    // Update maxi if current sum is greater
    if(currentSubarraySum > maxi) {
      maxi = currentSubarraySum;
      ansStart = start;
      ansEnd = i;
    }

    // Reset sum to 0 if it becomes negative
    if(currentSubarraySum < 0) {
      currentSubarraySum = 0;
    }
  }

  cout << "[ ";
  for(int i = ansStart; i < ansEnd; i++) {
    cout << arr[i] << " ";
  }
  cout << "]" << endl;

  return maxi;

  // Total T.C: O(n)
  // Total S.C: O(1)
}

int main() {
  vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
  // vector<int> arr = {-4, -2, -3, -1};
  // int ans = bruteForceApproach(arr);
  int ans = betterApproach(arr);
  // int ans = optimalApproach(arr2);
  // int ans = optimalApproachPrintSubarray(arr);
  cout << "Ans: " << ans;
}