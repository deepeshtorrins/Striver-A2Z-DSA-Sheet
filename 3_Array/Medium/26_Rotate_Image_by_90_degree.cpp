#include <bits/stdc++.h>
using namespace std;

// ! Q26: Rotate Image by 90 degree
// Brute -> Optimal
/*
Problem Statement: Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.
The rotation must be done in place, meaning the input 2D matrix must be modified directly..

Examples
Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
Explanation :
First, we transpose the matrix: rows become columns. Then, we reverse each row to simulate 90° clockwise rotation.
So element at (0,0) goes to (0,2), (0,1) goes to (1,2), and so on, achieving the rotated layout.

Input: matrix = [[0, 1, 1, 2], [2, 0, 3, 1], [4, 5, 0, 5], [5, 6, 7, 0]]
Output: matrix = [[5, 4, 2, 0], [6, 5, 0, 1], [7, 0, 3, 1], [0, 5, 1, 2]]
Explanation :
First, the matrix is transposed: rows become columns. Then, each row is reversed. 
This moves the last column to the first row, the second last column to the second row, and so on. 
The original position of each element is rotated 90° clockwise into its new location.
*/

// ! 1. Brute Force Approach
/*
Input:
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

Output:
13 9  5 1
14 10 6 2
15 11 7 3
16 12 8 4

 i  j      i  j
[0][0] -> [0][3]
[0][1] -> [1][3]
[0][2] -> [2][3]
[0][3] -> [3][3]

[1][0] -> [0][2]
[1][1] -> [1][2]
[1][2] -> [2][2]
[1][3] -> [3][2]

          i = j
          j = n-i-1
*/

vector<vector<int>> bruteForceApproach(vector<vector<int>> matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  vector<vector<int>> ans(n, vector<int>(m));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      ans[j][n-i-1] = matrix[i][j];
    }
  }

  return ans;

  // Total T.C: O(n^2)
  // Total S.C: O(n^2)
}

// ! 2. Better Approach
void betterApproach() { 
  // not exist
}

// ! 3. Optimal Approach
vector<vector<int>> optimalApproach(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  // 1. Transpose the matrix
  for(int i = 0; i < n-1; i++) {
    for(int j = i+1; j < n; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // 2. reverse each row
  for(int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }

  return matrix;
  
  // Total T.C: O(n^2)
  // Total S.C: O(1)
}

int main() {
  vector<vector<int>> matrix = {
    {1, 2, 3, 4}, 
    {5, 6, 7, 8}, 
    {9, 10, 11, 12}, 
    {13, 14, 15, 16}, 
  };
  int n = matrix.size();
  int m = matrix[0].size();
  
  // vector<vector<int>> ans = bruteForceApproach(matrix);
  vector<vector<int>> ans = optimalApproach(matrix);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}