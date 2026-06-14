#include <bits/stdc++.h>
using namespace std;

// ! Q22: Next Permutation: find next lexicographically greater permutation
/*
Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

Examples

Input: Arr[] = {1,3,2}
Output: {2,1,3}
Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,1,3} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.

Input : Arr[] = {3,2,1}
Output: {1,2,3}
Explanation : As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. So, we have to return the lowest permutation.
*/

// ! 1. Brute Force Approach
vector<int> bruteForceApproach(vector<int> &arr) {
  // Step 1: Generate all permutations
  // Step 2: then linear search
  // Step 3: find next permutation, if there is no one after then fallback to first

  // Total T.C: O(n! * n)
  // Total S.C: O(n!)
  return arr;
}

// ! 2. Better Approach (using stl library) (this approach only for c++)
vector<int> betterApproach(vector<int> &arr) {
  next_permutation(arr.begin(), arr.end());

  return arr;

  // Total T.C: O()
  // Total S.C: O()
}

// ! 3. Optimal Approach
vector<int> optimalApproach(vector<int> &arr) {
  int n = arr.size();
  
  int index = -1;

  // Step 1: find the first decreasing element from end.
  for(int i = n-2; i >= 0; i--) {
    if(arr[i] < arr[i+1]) {
      index = i;
      break;
    }
  }

  // Step 2: if no such index found (means there is no such next permutation elements found, then return first element)
  if(index == -1) {
    reverse(arr.begin(), arr.end());
    return arr;
  }

  // Step 3: find element just greater than arr[index]
  for(int i = n-1; i >= index; i--) {
    if(arr[i] > arr[index]) {
      swap(arr[i], arr[index]);
      break;
    }
  }

  // Step 4: reverse the array after index
  reverse(arr.begin()+index+1, arr.end());

  return arr;
  // Total T.C: O(2n)
  // Total S.C: O(1) but we are modifying the array then O(n)
}

int main() {
  vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
  // bruteForceApproach(arr);
  // betterApproach()
  vector<int> ans = optimalApproach(arr);

  for(int i = 0; i < ans.size(); i++) { // 2 3 0 0 1 4 5
    cout << ans[i] << " ";
  }
}