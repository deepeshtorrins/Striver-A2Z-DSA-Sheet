#include <bits/stdc++.h>
using namespace std;

// ! Q2: Find Second Smallest and Second Largest Element in an array
// https://takeuforward.org/data-structure/find-second-smallest-and-second-largest-element-in-an-array

/*
Problem Statement: Given an array, find the second smallest and second largest element in the array.
  Print ‘-1’ in the event that either of them doesn’t exist.

Example 1:
Input: [1, 2, 4, 7, 7, 5]  
Output:
Second Smallest : 2  
Second Largest : 5  
Explanation: The elements are sorted as 1, 2, 4, 5, 7, 7.  
Hence, the second smallest element is 2, and the second largest element is 5.

Example 2:
Input: [1]
Output:
Second Smallest : -1  
Second Largest : -1  
Explanation: Since there is only one element in the array, it is both the largest and smallest element.  
Therefore, there is no second smallest or second largest element present.
*/

// ! 1. Brute Force Approach
/*
  1. sort the array
  2. find the largest element
  3. Traverse from second last element
    a. Start from n-2 and move backward
    b. Find the first element not equal to largest
*/
int bruteForceApproach(vector<int>& arr) {
  int n = arr.size();

  if (n < 2) return -1;  

  // T.C: O(nlogn)
  sort(arr.begin(), arr.end());

  // T.C: O(n)
  int largest = arr[n-1];
  int secondLargest = largest;

  // It handle the case of duplicate number at the end
  for(int i = n-2; i >= 0; i--) {
    if(arr[i] != largest) {
      secondLargest = arr[i];
      break;
    }
  }

  return secondLargest;

  // T.C: O(nlogn) + O(n)
}

// ! 2. Better Approach
/*
1. Initialize variables
  a. largest = INT_MIN
  b. secondLargest = INT_MIN

2. Find the largest element
  a. Traverse the array
  b. Update largest if current element is greater

3. Find the second largest element
  a. Traverse again
  b. Check:
    Element is not equal to largest
    Element is greater than secondLargest
  c. Update secondLargest

4. Check result
  a. If secondLargest is still INT_MIN
    👉 No second largest exists
  b. Else print it
*/
int betterApproach(vector<int>& arr) {
  int n = arr.size();

  if (n < 2) return -1;

  int largest = INT_MIN;
  int secondLargest = INT_MIN;
  
  // Find largest
  for(int i = 0; i < n; i++) {
    if(arr[i] > largest) {
      largest = arr[i];
    }
  }

  cout << "Largest: " << largest << endl;

  // Find second largest
  for(int i = 0; i < n; i++) {
    if(arr[i] > secondLargest && arr[i] != largest) {
      secondLargest = arr[i];
    }
  }

  return secondLargest;

  // T.C: O(n) + O(n) = O(n)
}

// ! 3. Optimal Approach
int optimalApproach(vector<int>& arr) {
  int n = arr.size();

  if (n < 2) return -1;

  int largest = INT_MIN;
  int secondLargest = INT_MIN;
  for(int i = 0; i < n; i++) {
    if(arr[i] > largest) {
      secondLargest = largest;
      largest = arr[i];
    } else if(arr[i] > secondLargest && arr[i] != largest) {
      secondLargest = arr[i];
    }
  }

  return secondLargest;
}


int main() {
  // vector<int> arr = {1, 2, 4, 5, 7, 7};
  // vector<int> arr = {1, 4, 5, 7, 7, 2};
 
  vector<int> arr = {1, 2, 4, 7, 7, 5};
  // int ans = bruteForceApproach(arr);
  // int ans = betterApproach(arr);
  int ans = optimalApproach(arr);
  cout << "Second Largest: " << ans;
}
