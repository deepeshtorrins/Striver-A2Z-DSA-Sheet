#include <bits/stdc++.h>
using namespace std;

// Q8: Linear Search
/*
Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. 
If present print the index of the element or print -1.

Example 1:
Input: arr[] = 1 2 3 4 5, num = 3  
Output: 2
Explanation: 3 is present at the 2nd index of the array.

Example 2:
Input: arr[] = 5 4 3 2 1, num = 5  
Output: 0  
Explanation: 5 is present at the 0th index of the array.
*/

int linearSearch(int arr[], int n, int num) {  
  for(int i = 0; i < n; i++) {
    if(arr[i] == num) {
      return i;
    }
  }

  return -1;

  // Total T.C: O(n)
  // Total S.C: O(1)
}

int main() {
  int arr[] = {6, 7, 8, 4, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  int num = 8;

  int index = linearSearch(arr, size, num);
  cout << "Index: " << index;
}