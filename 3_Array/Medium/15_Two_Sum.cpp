#include <bits/stdc++.h>
using namespace std;

// ! Q15: Two Sum : Check if a pair with given sum exists in Array
// https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array
/*
Problem Statement: Given an array of integers arr[] and an integer target.
1st variant of question: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
2nd variant of question: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Input: N = 5, arr[] = {2,6,5,8,11}, target = 14
Output : YES
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for first variant for second variant output will be : [1,3].

Input: N = 5, arr[] = {2,6,5,8,11}, target = 15
Output : NO.
Explanation: There exist no such two numbers whose sum is equal to the target. 
*/

// ! 1. Brute Force Approach
string bruteForceApproach(vector<int> &arr, int target) {
  int n = arr.size();

  for(int i = 0; i < n; i++) {
    for(int j = i +1; j < n; j++) {
      if(arr[i] + arr[j] == target) {
        return "YES"; // return {i, j}
      }
    }
  }

  return "NO"; // return {-1, -1};

  // Total T.C: O(n*n)
  // Total S.C: O(1)
}

// ! 2. Better Approach (using hashmap)
string betterApproach(vector<int> &arr, int target) {
  int n = arr.size();
  map<int, int> mpp;
  // Iterate over all elements
  for(int i = 0; i < n; i++) {
    int complement = target - arr[i];  // Needed value to reach target sum
    // Check if complement is already in map
    if(mpp.find(complement) != mpp.end()) {
      return "YES"; // Pair found // return {i, mpp[complement]};
    }

    // Store current element with its index for future reference
    mpp[arr[i]] = i;
  }

  // No pair found
  return "NO"; // return {-1, -1};
  
  // Total T.C: O(n * nlogn) for ordered map
  // Total T.C: O(n * 1) or O(n * n) for unordered map
  // Total S.C: O(n)
}

// ! 3. Optimal Approach (using Two pointer approach)
string optimalApproach(vector<int> &arr, int target) {
  int n = arr.size();

  // T.C: O(n*logn)
  sort(arr.begin(), arr.end());

  // T.C: O(n)
  int l = 0;
  int r = n -1;
  // Loop until pointers cross
  while(l < r) {
    int sum = arr[l] + arr[r];
    if(sum == target) {
      return "YES"; // Pair found
    } else if(sum <  target) {
      l++; // Need bigger sum, move left pointer right
    } else {
      r--; // Need smaller sum, move right pointer left
    }
  }

  return "NO";
  
  // Total T.C: O(n*logn) + O(n)
  // Total S.C: O(1) / O(n) because while sorting it took space
}

// ! for priting the "YES"/"NO" optimalApproach() is best 
// ! but for priting the "indexes" betterApproach() is best 

int main() {
  vector<int> arr = {2, 6, 5, 8, 11};
  int target = 14;
  // string ans = bruteForceApproach(arr, target);
  // string ans = betterApproach(arr, target);
  string ans = optimalApproach(arr, target);
  cout << "ans: " << ans << endl;
}