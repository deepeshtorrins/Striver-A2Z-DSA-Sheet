#include <bits/stdc++.h>
using namespace std;

// ! Q3: Check if an Array is Sorted
// https://takeuforward.org/data-structure/check-if-an-array-is-sorted

/*
Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not.
  If the array is sorted then return True, Else return False.

Example 1:
Input: N = 5, array[] = {1,2,3,4,5}
Output: True.
Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.

Example 2:
Input: N = 5, array[] = {5,4,6,7,8}
Output: False.
Explanation: The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, So the answer is False.
Here element 5 is not smaller than or equal to its future elements.
*/

// ! 3. Optimal Approach
bool isSorted(int arr[], int n) {
  for(int i = 1; i < n; i++) {
    if(arr[i-1] <= arr[i]) {
      
    } else {
      return false;  // If any element is smaller than the previous one, return false
    }
  }
  return true; // Return true if the array is sorted
}

int main() {
  int arr1[] = {1, 2, 2, 3, 3, 4};
  int arr2[] = {1, 2, 1, 3, 4};

  cout << isSorted(arr1, 6) << endl; // 1
  cout << isSorted(arr2, 5); // 0
}
