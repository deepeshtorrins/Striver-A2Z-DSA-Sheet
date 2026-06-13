#include <bits/stdc++.h>
using namespace std;

// ! Q7: Move all zeroes to the end of the array
// https://takeuforward.org/data-structure/move-all-zeros-to-the-end-of-the-array
/*
Problem Statement: You are given an array of integers, 
your task is to move all the zeros in the array to the end of the array and 
move non-negative integers to the front by maintaining their order.

Examples -

Input: 1,0,2,3,0,4,0,1
Output: 1,2,3,4,1,0,0,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

Input : 1,2,0,1,0,4,0
Output: 1,2,1,4,0,0,0
Explanation : All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

Problem Link: https://www.naukri.com/code360/problems/ninja-and-the-zero-s_6581958
*/

// ! 1. Brute Force Approach
/**
 * 1. iterate the array and copy the all non-zeroes number to temp array.
 * 2. then will be copy from temp to original array and rest will be mark as zeroes
 */
void bruteForceApproach(int arr[], int n) {
  
  // Step 1: store non-zero elements
  // T.C. O(n)
  // S.C. O(x) where x is number of non zero number
  vector<int> temp;

  for(int i = 0; i < n; i++) {
    if(arr[i] != 0) {
      temp.push_back(arr[i]);
    }
  }

  // Step 2: copy back non-zero elements
  // T.C. O(x)
  int nz = temp.size();
  for(int i = 0; i < nz; i++) {
    arr[i] = temp[i];
  }

  // Step 3: fill remaining with zero
  // T.C. O(n-x)
  for(int i = nz; i < n; i++) {
    arr[i] = 0;
  }

  // Total T.C: O(n) + O(x) + O(n-x) = O(2n)
  // Total S.C: O(x)
}

// ! 2. Better Approach
void betterApproach() {
  // not exist
}

// ! 3. Optimal Approach (Two Pointer Approach)
void optimalApproach(int arr[], int n) {

  // Step 1: find first zero index
  // T.C. O(x)
  int j = -1;
  for(int i = 0; i < n; i++) {
    if(arr[i] == 0) {
      j = i;
      break;
    }
  }

  // if no zero found
  if(j == -1) return;
  
  // Step 2: swap non-zero with zero with two pointer approach
  // T.C. O(n-x)
  for(int i = j+1; i < n; i++) {
    if(arr[i] != 0) {
      swap(arr[i], arr[j]);
      j++;
    }
  }

  // Total T.C: O(x) + O(n-x) = O(n)
  // Total S.C: O(1)

  /*
    If interviewer asks: "Why find first zero?"
    
    Answer:
    To avoid unnecessary swaps
    Makes solution slightly optimized
  */
}

int main() {
  int arr[] = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  // bruteForceApproach(arr, size);
  optimalApproach(arr, size);

  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}