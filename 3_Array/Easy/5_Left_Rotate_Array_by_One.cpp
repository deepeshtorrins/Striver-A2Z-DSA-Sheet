#include <bits/stdc++.h>
using namespace std;

// ! Q5: Left rotate the array by one place.
// https://takeuforward.org/data-structure/left-rotate-the-array-by-one
// What is the space used to solve the problem is O(N).
// What is the extra space used to solve the problem is O(1).
/*
Problem Statement: Given an integer array nums, rotate the array to the left by one.
Note: There is no need to return anything, just modify the given array.

Example 1:
Input: nums = [1, 2, 3, 4, 5]  
Output: [2, 3, 4, 5, 1]  
Explanation: Initially, nums = [1, 2, 3, 4, 5]  
Rotating once to the left results in nums = [2, 3, 4, 5, 1].

Example 2:
Input: nums = [-1, 0, 3, 6]  
Output: [0, 3, 6, -1]  
Explanation: Initially, nums = [-1, 0, 3, 6]  
Rotating once to the left results in nums = [0, 3, 6, -1].
*/

// ! 1. Brute Force Approach
/*
- Store element first element in temp
- Shift all element to left
- assign last element to temp
*/
void bruteForceApproach(int arr[], int n) {  
  int temp = arr[0];
  for(int i = 1; i < n; i++) {
    arr[i-1] = arr[i];
  }
  arr[n-1] = temp;

  // T.C -> O(n)
  // Extra S.C -> O(1)
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = 5;
  bruteForceApproach(arr, n);

  // Print the array
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
