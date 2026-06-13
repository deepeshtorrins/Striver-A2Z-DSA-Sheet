#include <bits/stdc++.h>
using namespace std;

// Q9: Union of Two Sorted Arrays 
/*
Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.
The union of two arrays can be defined as the common and distinct elements in the two arrays.
NOTE: Elements in the union should be in ascending order.


Input: n = 5, m = 5 arr1[] = {1,2,3,4,5}  arr2[] = {2,3,4,4,5}
Output: {1,2,3,4,5}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elements in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5}

Input:n = 10,m = 7,arr1[] = {1,2,3,4,5,6,7,8,9,10}arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elements in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12}
*/

// ! 1. Brute Force Approach (Using Map)
vector<int> bruteForceApproach(vector<int> a, vector<int> b) {  
  // Step 1: put all the value of arr1, arr2 into set
  // T.C. O(n1*logn + n2*logn)
  // S.C. O(n1+n2)
  set<int> st;
  int n1 = a.size();
  int n2 = b.size();
  for(int i = 0; i < n1; i++) {
    st.insert(a[i]);
  }
  for(int i = 0; i < n2; i++) {
    st.insert(b[i]);
  }

  // Step 2: put values of set into temp arrray
  // T.C. O(n1+ n2)
  // S.C. O(n1+n2) // This space is used to return the answer
  vector<int> temp;
  for(auto it: st) {
    temp.push_back(it);
  }

  return temp;
  // Total T.C: O(n1*logn + n2*logn) + O(n1+n2)
  // Total S.C: O(n1+n2) + O(n1+n2)
}

// ! 2. Better Approach
void betterApproach() {  
}

// vector<int> a = {1,2,3,4,5};
// vector<int> b = {2,3,4,4,5};
// ! 3. Optimal Approach
vector<int> optimalApproach(vector<int> a, vector<int> b) {
  int n1 = a.size();
  int n2 = b.size();
  int i = 0;
  int j = 0;
  vector<int> unionArr;
  while(i < n1 && j < n2) {
    // If current element in arr1 is smaller or equal
    if(a[i] <= b[j]) {
      // Add element if union empty or different from last added
      if(unionArr.size() == 0 || unionArr.back() != a[i]) {
        unionArr.push_back(a[i]);
      }
      i++; // Move pointer in arr1
    } 
    // If current element in arr2 is smaller
    else {
      // Add element if union empty or different from last added
      if(unionArr.size() == 0 || unionArr.back() != b[j]) {
        unionArr.push_back(b[j]);
      }
      j++; // Move pointer in arr2
    }
  }

  // Append remaining elements from arr1
  while(i < n1) {
    if(unionArr.size() == 0 || unionArr.back() != a[i]) {
      unionArr.push_back(a[i]);
    }
    i++;
  }

  // Append remaining elements from arr2
  while(j < n2) {
    if(unionArr.size() == 0 || unionArr.back() != b[j]) {
      unionArr.push_back(b[j]);
    }
    j++;
  }

  return unionArr;

  // Total T.C: O(n1 + n2)
  // Total S.C: O(n1+n2) // using only for retuning the value
}

int main() {
  vector<int> a = {1,2,3,4,5};
  vector<int> b = {2,3,4,4,5};
  
  // vector<int> output = bruteForceApproach(a, b);
  vector<int> output = optimalApproach(a, b);

  for(int i = 0; i < output.size(); i++) {
    cout << output[i] << " "; // 1 2 3 4 5
  }
}
