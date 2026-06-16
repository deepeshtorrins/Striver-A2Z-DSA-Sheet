#include <bits/stdc++.h>
using namespace std;

// ! Q25: Set Matrix Zero
/*
Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

Examples
Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output:[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0
*/

// ! 1. Brute Force Approach
vector<vector<int>> bruteForceApproach(vector<vector<int>> &matrix) {
  int n = matrix.size(); // number of row
  int m = matrix[0].size(); // number of col

  // Step 1: finding and marking to -1
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(matrix[i][j] == 0) {

        // Mark row to -1
        for(int j = 0; j < m; j++) {
          if(matrix[i][j] != 0) {
            matrix[i][j] = -1;
          }
        }
        
        // Mark column to -1
        for(int i = 0; i < m; i++) {
          if(matrix[i][j] != 0) {
            matrix[i][j] = -1;
          }
        }
      }
    }
  }
  
  // Step 2: marking to zero
   for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(matrix[i][j] == -1) {
        matrix[i][j] = 0;
      }
    }
  }

  return matrix;

  // Total T.C: O(m*n*(m+n))
  // Total S.C: O(1)
}

// ! 2. Better Approach
vector<vector<int>> betterApproach(vector<vector<int>> &matrix) {
  int n = matrix.size(); // number of row
  int m = matrix[0].size(); // number of col
  
  int row[n] = {0};
  int col[m] = {0};

  // Step 1: finding
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(matrix[i][j] == 0) {
        row[i] = 1;
        col[j] = 1;
      }
    }
  }

  // Step 2: marking
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(row[i] == 1 || col[j] == 1) {
        matrix[i][j] = 0;
      }
    }
  }

  return matrix;
  // Total T.C: O(n * m) + O(n * m)
  // Total S.C: O(n + m)
}

// ! 3. Optimal Approach
vector<vector<int>> optimalApproach(vector<vector<int>> &matrix) {
  int n = matrix.size(); // number of row
  int m = matrix[0].size(); // number of col

  // Step 1: mark zero to first row, first col and matrix[row][col] = 0
  int col0 = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(matrix[i][j] == 0) {
        if(j == 0) {
          col0 = 0;
        } else {
          matrix[0][j] = 0;
        }

        matrix[i][0] = 0;
      }
    }
  }

  // Step 2: mark zero to matric except matrix[i][0], matrix[0][j]
  for(int i = 1; i < n; i++) {
    for(int j = 1; j < m; j++) {
      if(matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  // Step 3: set first row to zero
  if(matrix[0][0] == 0) {
    for(int j = 0; j < m; j++) {
      matrix[0][j] = 0;
    }
  }

  // Step 4: set first col to zero
  if(col0 == 0) {
    for(int i = 0; i < n; i++) {
      matrix[i][0] = 0;
    }
  }

  return matrix;

  // Total T.C: O(n * m) + O(n * m)
  // Total S.C: O(1)
}

int main() {
  vector<vector<int>> matrix = {
    {1, 1, 1, 1},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 1}
  };
  int n = matrix.size(); // number of row
  int m = matrix[0].size(); // number of col

  vector<vector<int>> ans = bruteForceApproach(matrix);
  // vector<vector<int>> ans = betterApproach(matrix);
  // vector<vector<int>> ans = optimalApproach(matrix);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}