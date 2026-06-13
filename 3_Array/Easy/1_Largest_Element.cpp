#include <bits/stdc++.h>
using namespace std;

// ! Q1: Find the Largest element in an array
// https://takeuforward.org/data-structure/find-the-largest-element-in-an-array
/*
Problem Statement: Given an array, we have to find the largest element in the array.

Example 1:
Input: arr[] = {2, 5, 1, 3, 0}  
Output: 5
Explanation: 5 is the largest element in the array.

Example 2:
Input: arr[] = {8, 10, 5, 7, 9}  
Output: 10  
Explanation: 10 is the largest element in the array.
*/

// ! 1. Brute Force Approach
/*
- Sort the array in ascending order.
- Print the element at the (size of the array - 1)th index, 
  which corresponds to the largest element in the array.
*/
int bruteForceApproach(vector<int>& arr) {
  int n = arr.size();

  // sort the array
  // T.C. O(nlogn)
  sort(arr.begin(), arr.end());

  // return nth-1 index element
  return arr[n-1];
  
  // Total T.C: O(nlogn)
  // Total S.C: O(1)
}

// ! 2. Better Approach
// have no better solution
void betterApproach() { 
}

// ! 3. Optimal Approach
/*
- Initialise first variable as max element
- iterate through all element in array if current element greater than max value then update the max value with current element's value
- after completing the loop, print the max value
*/
int optimalApproach(vector<int>& arr) {
  int n = arr.size();
  int largest = arr[0];

  for(int i = 0; i < n; i++) {
    if(arr[i] > largest) {
      largest = arr[i];
    }
  }

  return largest;
}
// TC: O(n)
// SC: O(1)

int main() {
  vector<int> arr = {3, 2, 1, 5, 2};
  int ans = bruteForceApproach(arr);
  // int ans = optimalApproach(arr);.
  cout << "Largest Element: " << ans;
}