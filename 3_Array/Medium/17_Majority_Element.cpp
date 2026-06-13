#include <bits/stdc++.h>
using namespace std;

// ! Q17: Find the Majority Element that occurs more than N/2 times
/*
Problem Statement: Given an integer array nums of size n, return the majority element of the array.
The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.

Example 1:
Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]  
Output: 7  
Explanation: The number 7 appears 5 times in the 9-sized array, making it the most frequent element.

Example 2:
Input: nums = [1, 1, 1, 2, 1, 2]  
Output: 1  
Explanation: The number 1 appears 4 times in the 6-sized array, making it the most frequent element.
*/

// ! 1. Brute Force Approach
int bruteForceApproach(vector<int> arr) {
  int n = arr.size();

  for(int i = 0; i < n; i++) {
    int ele = arr[i];
    int count = 0;

    for(int j = 0; j < n; j++) {
      if(ele == arr[j]) {
        count++;
      }
    }

    if(count > n/2) {
      return ele;
    }
  }

  return -1;

  // Total T.C: O(n*n)
  // Total S.C: O(1)
}

// ! 2. Better Approach (use hashmap)
int betterApproach(vector<int> arr) {
  int n = arr.size();

  map<int, int> mapp;

  // T.C. O(n * logn)
  for(int i = 0; i < n; i++) {
    mapp[arr[i]]++;
  }

  // T.C. O(n)
  for(auto it: mapp) {
    if(it.second > n /2) {
      return it.first;
    }
  }

  return -1;

  // Total T.C: O(n * logn) + O(n)
  // Total S.C: O(n)
}

// ! 3. Optimal Approach (Moore's voting algorithm)
int optimalApproach(vector<int> arr) {
  int n = arr.size();
  
  int count=0;
  int ele=arr[0];

  for(int i = 0; i < n; i++) {
    if(count == 0) {
      ele = arr[i];
      count++;
    } else if(ele == arr[i]) {
      count++;
    } else {
      count--;
    }
  }

  // Checking if the stored element is the majority element
  int count2 = 0;
  for(int i = 0; i < n; i++) {
    if(arr[i] == ele) {
      count2++;
    }
  }

  //return element if it is a majority element
  if(count2 > n/2) {
    return ele;
  }

  //return -1 if no such element found
  return -1;

  // Total T.C: O(n) + O(n)
  // Total S.C: O(1)
}

int main() {
  // vector<int> arr = {7, 0, 0, 1, 7, 7, 2, 7, 7};
  vector<int> arr = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};

  // int ans = bruteForceApproach(arr);
  // int ans = betterApproach(arr);
  int ans = optimalApproach(arr);
  
  cout << "Ans: " << ans;
}