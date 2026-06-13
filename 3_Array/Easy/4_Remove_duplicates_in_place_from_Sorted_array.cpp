#include <bits/stdc++.h>
using namespace std;

// ! Q4: Remove duplicates in-place from Sorted array
// https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array
/*
Problem Statement: Given an integer array sorted in non-decreasing order, 
remove the duplicates in place such that each unique element appears only once. 
The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. 
It does not matter what you leave beyond the first k elements.

Example 1
Input: arr[]=[1,1,2,2,2,3,3]
Output: [1,2,3,_,_,_,_]
Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.

Example 2
Input: arr[]=[1,1,1,2,2,3,3,3,3,4,4]
Output: [1,2,3,4,_,_,_,_,_,_,_]
Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.
*/

// ! 1. Brute Force Approach
int bruteForceApproach(int arr[], int n) {
  set<int> st;

  // T.C. O(n log n)  → insertion in set
  for(int i = 0; i < n; i++) {
    st.insert(arr[i]);
  }

  // T.C. O(n)  → copying elements back
  int index = 0;
  for(auto it: st) {
    arr[index] = it;
    index++;
  }

  // Total T.C: O(n log n + n) ≈ O(n log n)
  // S.C: O(n)  → extra set used

  return index;
}

// ! 2. Optimal Approach (using Two Pointer Approach)
// We are using 2 pointer approach
int optimalApproach_my(int arr[], int n) {
  int p1 = 0;
  int p2 = 1;
  while(p2 <= n) {
    if(arr[p1] == arr[p2]) {
      
    } else {
      arr[p1+1] = arr[p2];
      p1++;
    }
    p2++;
  }
  return p1;
}

int optimalApproach(int arr[], int n) {
  int i = 0;

  // Traverse the array starting from the second element
  for(int j = 1; j < n; j++) {
    // If current element is different from last unique element
    if(arr[j] != arr[i]) {
      arr[i+1] = arr[j];
      i++;
    }
  }
  return i+1;
}

int main() {
  int arr[] = {1, 1, 2, 2, 2, 3, 3};

  // int newLength = bruteForceApproach(arr, 7);
  int newLength = optimalApproach(arr, 7);

  for(int i = 0; i < newLength; i++) {
    cout << arr[i] << " ";
  }
}