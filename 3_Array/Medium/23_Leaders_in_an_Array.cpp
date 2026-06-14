#include <bits/stdc++.h>
using namespace std;

// Q23: Leaders in an Array
/*
Example 1:
Input: arr = [4, 7, 1, 0]  
Output: 7 1 0  
Explanation:
The rightmost element (0) is always a leader.  
7 and 1 are greater than the elements to their right, making them leaders as well.

Example 2:
Input: arr = [10, 22, 12, 3, 0, 6]  
Output: 22 12 6  
Explanation:
6 is a leader because there are no elements after it.  
12 is greater than all the elements to its right (3, 0, 6), and 22 is greater than 12, 3, 0, 6, making them leaders as well.
*/

// ! 1. Brute Force Approach
vector<int> bruteForceApproach(vector<int> &arr) {
  int n = arr.size();
  vector<int> ans;
  for(int i = 0; i < n; i++) {
    bool leader = true;
    for(int j = i+1; j < n; j++) {
      if(arr[j] >= arr[i]) {
        // If any element to the right is greater or equal, nums[i] is not a leader
        leader = false;
        break;
      }
    }

    if(leader) {
      ans.push_back(arr[i]);
    }
  }

  return ans;

  // Total T.C: O(n^2)
  // Total S.C: O(n)
}

// ! 2. Better Approach
void betterApproach() {
  // not exist
}

// ! 3. Optimal Approach
vector<int> optimalApproach(vector<int> &arr) {
  int n = arr.size();

  vector<int> ans;

  int maxValue = INT_MIN;
  for(int i = n-1; i >= 0; i--) {
    if(arr[i] > maxValue) {
      ans.push_back(arr[i]);
      maxValue = arr[i];
    }
  }

  // Reverse the vector to match the required output order
  reverse(ans.begin(), ans.end());

  return ans;
  
  // Total T.C with reverse as well: O(nlogn) with reverse
  // Total T.C without reverse as well: O(n)
  // Total S.C: O(n)
}

int main() {
  vector<int> arr = {10, 22, 12, 3, 0, 6};
  // vector<int> ans = bruteForceApproach(arr);
  vector<int> ans = optimalApproach(arr);

  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " "; // 10 22 12
  }
}