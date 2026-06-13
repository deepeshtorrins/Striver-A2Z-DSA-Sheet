#include <bits/stdc++.h>
using namespace std;

// Q9: Intersection of Two Sorted Arrays 
/*
Input:
arr1[] = {1, 2, 2, 3, 3, 4, 5, 6}  arr2[] = {2, 3, 3, 5, 6, 6, 7}
Output: {2, 3, 3, 5, 6}
*/

// ! 1. Brute Force Approach
vector<int> bruteForceApproach(vector<int> arr1, vector<int> arr2) {
  int n = arr1.size();
  int m = arr2.size();

  int temp[m] = {0};
  vector<int> ans;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if((arr1[i] == arr2[j]) && temp[j] == 0 ) {
        ans.push_back(arr1[i]);
        temp[j] = 1;
        break;
      }

      if(arr2[j] > arr1[i]) break;
    }
  }

  return ans;

  // Total T.C: O(n1*n2)
  // Total S.C: O(n2)
}

// ! 2. Better Approach
void betterApproach() {  
}

// ! 3. Optimal Approach (2 pointer approach)
vector<int> optimalApproach(vector<int> a, vector<int> b) {
  int i = 0;
  int j = 0;

  vector<int> ans;

  int n1 = a.size();
  int n2 = b.size();

  while(i < n1 && j < n2) {
    if(a[i] < b[j]) {
      i++;
    } else if(a[i] > b[j]){
      j++;
    } else {
        ans.push_back(a[i]);
        i++;
        j++;
    }
  }

  return ans;
  
  // Total T.C: O(n1+n2) 
  // S.C: O(1) // we are not using any extra space to solve the problem
  // Total S.C: O(n1+n2) // in worst case to store ans and return
}

int main() {
  vector<int> a = {1,2,3,4,5};
  vector<int> b = {2,3,4,4,5};
  
  vector<int> output = bruteForceApproach(a, b);
  // vector<int> output = optimalApproach(a, b);

  for(int i = 0; i < output.size(); i++) {
    cout << output[i] << " ";
  }
}
