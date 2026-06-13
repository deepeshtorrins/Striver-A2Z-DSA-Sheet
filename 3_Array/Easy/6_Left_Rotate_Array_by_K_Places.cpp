#include <bits/stdc++.h>
using namespace std;

// ! Q6: Left rotate an array by D places
// https://takeuforward.org/data-structure/rotate-array-by-k-elements
/*
Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.

Examples
Input : nums = [1, 2, 3, 4, 5, 6, 7], k = 2, right
Output : [6, 7, 1, 2, 3, 4, 5]
Explanation : rotate 1 step to the right: [7, 1, 2, 3, 4, 5, 6]
rotate 2 steps to the right: [6, 7, 1, 2, 3, 4, 5] 

Input : nums = [1, 2, 3, 4, 5, 6], k=2, left
Output : [3, 4, 5, 6, 1, 2]
Explanation :rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]
*/

// ! 1. Brute Force Approach
void bruteForceApproach(int arr[], int n, int d) {
  // Handle cases where d > n
  d = d % n;

  // T.C. d
  // S.C. O(d)
  // Step 1: Store first d elements in temp array
  int temp[d];
  for(int i = 0; i < d; i++) {
    temp[i] =  arr[i];
  }
  
  // T.C. (n - d)
  // Step 2: Shift remaining elements to the left
  for(int i = d; i < n; i++) {
    arr[i-d] = arr[i];
  }

  // T.C. d
  // Step 3: Copy temp elements back to array
  for(int i = n-d; i < n; i++) {
    arr[i] = temp[i - (n-d)];
  }

  // Total T.C: O(d) + O(n-d) + O(d) = O(n + d)  
  // Total S.C: O(d)
}

// ! 2. Better Approach
void betterApproach() {
  // not exist
}

void reverseArray(int arr[], int start, int end) {

  while(start <= end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }

}

// ! 3. Optimal Approach
void optimalApproach(int arr[], int n, int d) {
  // Reverse first d elements
  reverseArray(arr, 0, d-1);
  
  // Reverse remaining n-d elements
  reverseArray(arr, d, n-1);

  // Reverse the whole array
  reverseArray(arr, 0, n-1);

  // Total T.C: O(d) + O(n-d) + O(n) = O(2n)  
  // Total S.C: O(1)
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int arrLen = 7;
  // bruteForceApproach(arr, arrLen, 3); // 4 5 6 7 1 2 3
  
  optimalApproach(arr, arrLen, 3);

  for(int i = 0; i < arrLen; i++) {
    cout << arr[i] << " ";
  }
}