#include <bits/stdc++.h>
using namespace std;

// ! Q27: Spiral Traversal of Matrix
/*
Problem Statement: Given a Matrix, print the given matrix in spiral order.

Examples
Input: Matrix[][] = { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } }
Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form.

Input: Matrix[][] = { { 1, 2, 3 }, { 4, 5, 6 },{ 7, 8, 9 } }
Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
Explanation: The output of matrix in spiral form.
*/

vector<int> spiralTraversalOfMatrix(vector<vector<int>> matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  int top = 0;
  int bottom = n-1; // no. of row
  int left = 0;
  int right = m-1; // no. of col

  vector<int> ans;

  while(left <= right && top <= bottom) {
    cout << "left: " << left << " | right : " << right << endl;
    cout << "top : " << top << " | bottom: " << bottom << endl;

    // left to right
    for(int i = left; i <= right; i++) {
      ans.push_back(matrix[top][i]);
    }
    top++;
  
    // top to bottom
    for(int i = top; i <= bottom; i++) {
      ans.push_back(matrix[i][right]);
    }
    right--;
    
    // right to left
    if(top <= bottom) {
      for(int i = right; i >= left; i--) {
        ans.push_back(matrix[bottom][i]);
      }
      bottom--;
    }
    
    // bottom to top
    if(left <= bottom) {
      for(int i = bottom; i >= top; i--) {
        ans.push_back(matrix[i][left]);
      }
      left++;
    }
  }

  return ans;

  // Total T.C: O(m*n)
  // Total S.C: O(1)
}

int main() {
  vector<vector<int>> matrix2 = {
    { 1, 2, 3, 4, 5, 6 },
    { 20, 21, 22, 23, 24, 7},
    { 19, 32, 33, 34, 25, 8 },
    { 18, 31, 36, 35, 26, 9 },
    { 17, 30, 29, 28, 27, 10},
    { 16, 15, 14, 13, 12, 11}
  };

  vector<vector<int>> matrix3 = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };

  // perfect example to understand this check "if(top <= bottom) {"
  vector<vector<int>> matrix = {
    {1, 2, 3, 4, 5}
  };

  // perfect example to understand this check "if(left <= bottom) {"
  vector<vector<int>> matrix5 = {
    {1},
    {2},
    {3},
    {4},
    {5}
  };

  vector<vector<int>> matrix6 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  vector<int> ans = spiralTraversalOfMatrix(matrix);

  for(int i = 0; i < ans.size(); i++ ){
    cout << ans[i] << " ";
  }

}