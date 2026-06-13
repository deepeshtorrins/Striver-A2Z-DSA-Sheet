#include <bits/stdc++.h>
using namespace std;

// Q10: Find Missing number
/*
Given an array arr[] of size n-1 with distinct integers in the range of [1, n].
This array represents a permutation of the integers from 1 to n with one element missing.
Find the missing element in the array.

Examples: 

Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: Here the size of the array is 4, so the range will be [1, 5]. The missing number between 1 to 5 is 4
*/

// ! 1. Brute Force Approach
/*
Approach (Brute Force):
1. The missing number must be between 1 to n.
2. Check each number from 1 to n one by one.
3. For every number, traverse the entire array to see if it exists.
4. If the number is not found, return that number as the missing element.
5. If all numbers are found, return -1 (though this case won't happen as per problem statement).
*/
int bruteForceApproach(vector<int> &arr) {
  int n = arr.size() + 1;

  for(int i = 1; i <= n; i++) {
    int flag = 0;
    for(int j = 0; j < n-1; j++) {
      if(arr[j] == i) {
        flag = 1;
        break;
      }
    }
    if(flag == 0) {
      return i;
    }
  }

  return -1;

  // Total T.C: O(n*n)
  // Total S.C: O(1)
}

// ! 2. Better Approach (using Hashing)
/*
Approach (Hashing):
1. The missing number lies between 1 to n.
2. Create a hash array of size n+1 and initialize all values with 0.
3. Traverse the given array and mark the उपस्थित numbers in the hash array.
   - If a number exists in the array, increase its count in the hash array.
4. Traverse from 1 to n and check the hash array.
5. The index whose value is 0 means that number is missing.
6. Return the missing number.

Example:
arr = [1, 2, 3, 5]
n = 5

Hash after storing:
index:  0 1 2 3 4 5
value:  0 1 1 1 0 1

Check from 1 to 5:
1 → Present
2 → Present
3 → Present
4 → Missing (hash[4] == 0) → Return 4
*/
int betterApproach(vector<int> &arr) {
  int n = arr.size() + 1;
  
  // Create hash array of size n+1
  vector<int> hash(n+1, 0);

  // Store frequencies of elements
  for(int i = 0; i < n-1; i++) {
    hash[arr[i]]++;
  }

  // Find the missing number
  for(int i = 1; i <= n; i++) {
    if(hash[i] == 0) {
      return i;
    }
  }

  return -1;

  // Total T.C: O(n) + O(n)
  // Total S.C: O(n)
}

// ! 3. Optimal Approach (Using Sum of n terms Formula)
/*
Approach (Sum Formula):
1. The array contains numbers from 1 to n, with one number missing.
2. Find the sum of all elements present in the given array.
3. Calculate the expected sum of numbers from 1 to n using the formula:
   Sum = n * (n + 1) / 2
4. Subtract the actual array sum from the expected sum.
5. The remaining value will be the missing number.

Example:
arr = [1, 2, 3, 5]
n = 5

Actual sum = 1 + 2 + 3 + 5 = 11
Expected sum = 5 * 6 / 2 = 15

Missing number = 15 - 11 = 4
*/
int optimalApproach(vector<int> &arr) {
  int n = arr.size() + 1;

  // Calculate the sum of array elements
  int sum = 0;
  for(int i = 0; i < n-1; i++) {
    sum = sum + arr[i];
  }

  // Calculate the expected sum
  long long expSum = (n * (n+1))/ 2;

  // Return the missing number
  int missingNum = expSum - sum;

  return missingNum;

  // Total T.C: O(n)
  // Total S.C: O(1)
}

// ! 4. Optimal Approach #2 (using XOR)
/*
What is XOR?
XOR (Exclusive OR) is a bitwise operator represented by the caret symbol ^.
It compares two operands bit by bit 
and returns 1 if the bits are different, and 0 if they are the same.

2^2 = 0
2^2^2 = 2
2^2^2^2 = 0
2^2^5^5 = 0
2^2^2^2^2 = 2
*/

int optimalApproach2(vector<int> arr) {
  int n = arr.size() + 1;

  // int xor1 = 0;
  // for(int i = 0; i < n; i++) {
  //   xor1 = xor1 ^ (i+1);
  // }

  // int xor2 = 0;
  // for(int i = 0; i < n-1; i++) {
  //   xor2 = xor2 ^ arr[i];
  // }
  
  int xor1 = 0;
  int xor2 = 0;
  for(int i = 0; i < n-1; i++) {
    xor2 = xor2 ^ arr[i];
    xor1 = xor1 ^ (i+1);
  }
  xor1 = xor1 ^ n;

  return xor1 ^ xor2;

  // Total T.C: O(n)
  // Total S.C: O(1)
  // optimalApproach2 is slightly better than optimalApproach1 beause optimalApproach1 will take more space whike doing muliplication.
}

int main() {
  vector<int> arr = {1, 2, 4, 5};
  // int missingNumber = bruteForceApproach(arr);
  // int missingNumber = betterApproach(arr);
  // int missingNumber = optimalApproach(arr);
  int missingNumber = optimalApproach2(arr);
  cout << "Missing Number: " << missingNumber << endl;
}