#include <bits/stdc++.h>
using namespace std;

// Print all Divisors
/*
Input
36

Output
1 2 3 4 6 9 12 18 36
*/

// ! Approach 1: Brute Force Approach
// ! TC = O(N)
void printAllDivisors(int n) {
  for(int i = 1; i <= n; i++) {
    if(n % i == 0) {
      cout << i << " ";
    }
  }
}

// Approach 2: Optimal Approach
/*
1 x 36
2 x 18
3 x 12
4 x 9
--------
6 x 6
--------
9 x 4
12 X 3 
18 x 2
36 x 1
*/

// ! TC = O(sqrt(N))
// ! SC = O(2*sqrt(N))
void printAllDivisorsOptimalApproach(int n) {
  vector<int> ans;

  // for(int i = 1; i <= sqrt(n); i++) {

  // T.C. of this loop is O(sqrt(n))
  for(int i = 1; i*i <= n; i++) {
    if(n % i == 0) {
      // cout << i << " ";
      ans.push_back(i);

      if((n/i) != i) {
        // cout << n / i << " ";
        ans.push_back(n/i);
      }
    }
  }

  // T.C. -> O(number of factors * log(number of factors))
  sort(ans.begin(), ans.end());
  
  // T.C. -> O(number of factors)
  for(auto it : ans) {
    cout << it << " ";
  }
}

int main() {
  // printAllDivisors(36);
  printAllDivisorsOptimalApproach(36);
}