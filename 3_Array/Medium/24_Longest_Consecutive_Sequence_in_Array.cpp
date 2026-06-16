#include <bits/stdc++.h>
using namespace std;

// ! Q24: Longest Consecutive Sequence in an Array
/*
Problem Statement: Given an array nums of n integers.
Return the length of the longest sequence of consecutive integers. 
The integers in this sequence can appear in any order.

Example 1:
Input: nums = [100, 4, 200, 1, 3, 2]  
Output: 4
Explanation: The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

Example 2:
Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]  
Output: 9
Explanation: The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9.
*/

// ! 1. Brute Force Approach
bool linearSearch(vector<int> arr, int k) {
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i] == k) {
      return true;
    }
  }
  return false;
}

/*
- pick a element.
- iterate through the entire array and search consecutive numbers like (x+1, x+2, x+3)
  and increase count by one.
- based on max count, update longSeq value. 
*/
// arr = {102, 4, 100, 1, 101, 3, 2, 1, 1}
int bruteForceApproach(vector<int> arr) {
  int n = arr.size();
  int longSeq = 0;

  for(int i = 0; i < n; i++) {
    int ele = arr[i];
    int count = 1;

    while(linearSearch(arr, ele + 1) == true) {
      ele++;
      count++;
    }

    longSeq = max(longSeq, count);
  }

  return longSeq;
  // Total T.C: O(n^2)
  // Total S.C: O(1)
}

// ! 2. Better Approach
// arr[] = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2}
int betterApproach(vector<int> &arr) {
  int n = arr.size();

  // Return 0 if array is empty
  if (n == 0) return 0; 

  // Step 1:
  sort(arr.begin(), arr.end());
  // after sorting -> {1, 1, 1, 2, 2, 2, 3, 3, 4, 100, 100, 101, 101, 102}

  // Step 2:
  int lastSmaller = INT_MIN;  
  int currentCount = 0;
  int maxCount = 1;

  for(int i = 0; i < n; i++) {
    // case a: If consecutive number exists
    if(arr[i]-1 == lastSmaller) {
      currentCount++;
      lastSmaller = arr[i];
    } 
    // case b: If consecutive number doesn't exists
    else if(arr[i] != lastSmaller) {
      currentCount = 1;
      lastSmaller = arr[i];
    }
    maxCount = max(maxCount, currentCount);
  }
  return maxCount;
  
  // Total T.C: O(nlogn)
  // Total S.C: O(1)
}

// ! 3. Optimal Approach
int optimalApproach(vector<int> &arr) {
  int maxCount = 0;

  // 1. push all element in the set data structure
  int n = arr.size();
  unordered_set<int> st;
  for(int i = 0; i < n; i++) {
    st.insert(arr[i]);
  }

  for(auto it : st) {
    // 2. find wheather a element is first consective element or not?
    if(st.find(it - 1) == st.end()) {

      // 3. if it is first consecutive element then find +1 element and update the currentCount, maxCount
      int currentCount = 0;
      int ele = it;
      while(st.find(ele) != st.end()) {
        currentCount++;
        ele++;
      }
      maxCount = max(maxCount, currentCount);
    }
  }

  return maxCount;
  // Total T.C: O(n) + O(2n) = O(3n)
  // Total S.C: O(n)
}

int main() {
  vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
  // int ans = bruteForceApproach(arr);
  // int ans = betterApproach(arr);
  int ans = optimalApproach(arr);

  cout << "ans: " << ans;
}