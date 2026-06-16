#include <bits/stdc++.h>
using namespace std;

// ! Q21: Rearrange Array Elements by Sign
/*
Problem Statement: There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.
Without altering the relative order of positive and negative elements,
you must return an array of alternately positive and negative values.

Example 1:
Input: arr[] = {1,2,-4,-5}, N = 4
Output: 1 -4 2 -5
Explanation: 
Positive elements = 1,2
Negative elements = -4,-5
To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.

Example 2:
Input: arr[] = {1,2,-3,-1,-2,3}, N = 6
Output: 1 -3 2 -1 3 -2
Explanation: 
Positive elements = 1,2,3
Negative elements = -3,-1,-2
To maintain relative ordering, 1 must occur before 2, and 2 must occur before 3.
Also, -3 should come before -1, and -1 should come before -2.
*/

// ! 1. Brute Force Approach
vector<int> bruteForceApproach(vector<int> arr) {
  int n = arr.size();

  // Step 1: seperate +ve and -ve
  vector<int> pos;
  vector<int> neg;

  for(int i = 0; i < n; i++) {
    if(arr[i] > 0) { // +ve
      pos.push_back(arr[i]);
    } else { // -v2
      neg.push_back(arr[i]);
    }
  }

  // Step 2: place +ve on even indices and -ve on odd indices
  for(int i = 0; i < n/2; i++) {
    arr[i*2] = pos[i];
    arr[i*2 + 1] = neg[i];
  }

  return arr;

  // Total T.C: O(n) + O(n/2)
  // Total S.C: O(n/2) + O(n/2)
}

// ! 2. Better Approach
void betterApproach() {
  // not exist
}

// ! 3. Optimal Approach (when number of positive and negative is equal)
vector<int> optimalApproach(vector<int> arr) {
  int n = arr.size();
  
  // Create a result array of size n initialized with 0
  vector<int> ans(n, 0);

  int posIndex = 0;
  int negIndex = 1;

  for(int i = 0; i < n; i++) {
    if(arr[i] < 0) {
      ans[negIndex] = arr[i]; 
      negIndex+=2;
    } else {
      ans[posIndex] = arr[i];
      posIndex+=2;
    }
  }

  return ans;

  // Total T.C: O(n)
  // Total S.C: O(n)
}

// ! 2nd variant of this question
// If number of positive number or negative number may equal or not.

vector<int> secondVariant(vector <int> &arr) {
  int n = arr.size();

  // Step 1: find number of +ve and -ve numbers
  vector<int> pos;
  vector<int> neg;

  // T.C: O(n)
  for(int i = 0; i < n; i++) {
    if(arr[i] > 0) {
      pos.push_back(arr[i]);
    } else {
      neg.push_back(arr[i]);
    }
  }

  // Step 2: interleave for the shorter length, then append the leftover
  int posLen = pos.size();
  int negLen = neg.size();
  if(posLen > negLen) {
    // interleave first negLen pairs: pos[i], neg[i]
    // T.C: O(min(posLen, negLen))
    for(int i = 0; i < negLen; i++) {
      arr[2*i] = pos[i];
      arr[2*i + 1] = neg[i];
    }

    // append remaining positives after the interleaved section
    // T.C: O(leftover element)
    int index = 2 * negLen;
    for(int i = negLen; i < posLen; i++) {
      arr[index] = pos[i];
      index++;
    }
  } else {
    // interleave first posLen pairs: pos[i], neg[i]
    for(int i = 0; i < posLen; i++) {
      arr[2*i] = pos[i];
      arr[2*i + 1] = neg[i];
    }

    // append remaining negatives after the interleaved section
    int index = 2 * posLen;
    for(int i = posLen; i < negLen; i++) {
      arr[index] = neg[i];
      index++;
    }
  }

  return arr;

  // Total T.C: O(n) + O(min(posLen, negLen)) + O(leftover element) = O(n) + O(n) = O(2n)
  // Total S.C: O(n)
}

int main() {
  vector<int> arr = {1,2,3,-3,-1,-2};
  // vector<int> ans = bruteForceApproach(arr);
  // vector<int> ans = optimalApproach(arr);

  vector<int> arr2 = {-1, 2, 3, 4, -3, 1};
  vector<int> ans = secondVariant(arr2);

  for(int i = 0; i < ans.size(); i++) { // 1 -3 2 -1 3 -2
    cout << ans[i] << " ";
  }
}