#include <bits/stdc++.h>
using namespace std;

/*
! Q. Sum of first N number using recursion.
There are two to solve this
  - one way is parameterised
  - another way is functional
*/

void sumFirstNParameterised(int i, int sum) {
  if(i < 1) {
    cout << sum << endl;
    return;
  }
  sumFirstNParameterised(i-1, sum + i);
}

// T.C. -> O(N)
// S.C. -> O(N)
int sumFirstNFunctional(int i) {
  if(i == 0) {
    return 0;
  }
  return i + sumFirstNFunctional(i-1);  
}

// ! Q2: Find factorial of n using recursion.
int factorial(int i) {
  if(i == 1) {
    return 1;
  }
  return i * factorial(i - 1);
}

int main() {
  // sumFirstNParameterised(5, 0); // 15
  // cout << sumFirstNFunctional(3); // 6
  
  cout << factorial(4); // 24
}