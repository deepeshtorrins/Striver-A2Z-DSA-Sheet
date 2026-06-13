#include <bits/stdc++.h>
using namespace std;

// Q12: Find the number that appears once, and the other numbers twice

/*
Problem Statement: Given a non-empty array of integers arr, 
every element appears twice except for one. Find that single one.

Examples
Example 1:
Input Format: arr[] = {2,2,1}
Result: 1
Explanation: In this array, only the element 1 appear once and so it is the answer.

Example 2:
Input Format: arr[] = {4,1,2,1,2}
Result: 4
Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.
*/

// ! 1. Brute Force Approach
int bruteForceApproach(vector<int> &arr) {  
  int n = arr.size();
  
  for(int i = 0; i < n; i++) {
    int count = 0;
    for(int j = 0; j < n; j++) {
      if(arr[i] == arr[j]) {
        count++;
      }
    }
    if(count == 1) return arr[i];
  }

  return -1;

  // Total T.C: O(n * n)
  // Total S.C: O(1)
}

// ! 2. Better Approach (Hashing)
int betterApproach(vector<int> &arr) {
  // find maximum number from the array
  int n = arr.size();
  int max_num = arr[0];
  for(int i = 0; i < n; i++) {
    if(arr[i] > max_num) {
      max_num = arr[i];
    }
  }
  
  // create hash array
  int hash[max_num+1] = {0};
  
  // put the element count in hash array
  for(int i = 0; i < n; i++) {
    hash[arr[i]]++;
  }
  
  // find the index which have value is 0
  // for(int i = 0; i < max_num+1; i++) {
  //   if(hash[i] == 1) {
  //     return i;
  //   }
  // }
  // or
  for(int i = 0; i < n; i++) {
    if(hash[arr[i]] == 1) {
      return arr[i];
    }
  }
  
  return -1;
  
  // Total T.C: O(n) + O(n) + O(n) = O(3n)
  // Total S.C: O(max_num+1)


  /* Can we use hash everytime? 
    Ans: no because hash is not possible for negatives, or bigger numbers.
    example, -12, 10^9, 10^12.
    for this case we need to use map<long long, int>
  */
}

// ! 2. Better Approach (using map)
int betterApproachUsingMap(vector<int> &arr) {
  int n = arr.size();
  map<long long, int> mpp;

  /* T.C: 
    n is the size of array and m is size of map.
    Ordered map: O(n*logm)
    Unordered map: O(n) is best case or O(n^2) in worst case 
  */
  
  for(int i = 0; i < n; i++) {
    mpp[arr[i]]++;
  }

  // T.C: O(n/2 + 1)
  for(auto it: mpp) {
    if(it.second == 1) {
      return it.first;
    }
  }
  
  return -1;

  // Total T.C: O(n*logm) + O(n/2 + 1)
  // Total S.C: O(n/2 + 1)
}

// ! 3. Optimal Approach (using XOR)
int optimalApproach(vector<int> &arr) {
  int n = arr.size();
  int xorr = 0;

  // XOR all elements. Duplicates cancel out, leaving the single element.
  for(int i = 0; i < n; i++) {
    xorr = xorr ^ arr[i];
  }
  return xorr;

  // Total T.C: O(n)
  // Total S.C: O(1)
}

int main() {
  vector<int> arr = {4, 1, 2, 1, 3, 2, 4};
  // int ans = bruteForceApproach(arr);
  // int ans = betterApproach(arr);
  // int ans = optimalApproach(arr);
  int ans = betterApproachUsingMap(arr);
  cout << "ans: " << ans << endl;
}