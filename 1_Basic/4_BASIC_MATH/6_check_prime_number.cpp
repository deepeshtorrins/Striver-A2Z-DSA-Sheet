#include <bits/stdc++.h>
using namespace std;

// 6. Prime number check
// A number that has only two factors 1 & itself.

/*
N = 11 -> 1 & 11
N = 13 -> 1 & 13
N = 5 -> 1 & 5
N = 4 -> 1, 2, 4
N = 8 -> 1, 2, 4, 8
N = 17 -> 1, 17
*/

// ! 1. Brute Force Approach
int noOfFactor(int n) {
  int count = 0;
  for(int i = 1; i <= n; i++) {
    if(n % i == 0) {
      count++;
    }
  }
  return count;
}

// T.C. -> O(N)
void checkPrimeNumber(int n) {
  int noOfFac = noOfFactor(n);
  cout << noOfFac << endl;

  if(noOfFac == 2) {
    cout << "It is prime number";
  } else {
    cout << "It is not a prime number";
  }
}

// ! 2. Optimal Approach
int noOfFactorOptimal(int n) {
  int count = 0;
  for(int i = 1; i*i <= n; i++) {
    if(n % i == 0) {
      count++;

      if((n/i) != i) {
        count++;
      }
    }
  }
  return count;
}

// T.C. -> O(sqrt(N))
void checkPrimeNumberOptimal(int n) {
  int noOfFac = noOfFactorOptimal(n);
  cout << noOfFac << endl;

  if(noOfFac == 2) {
    cout << "It is prime number";
  } else {
    cout << "It is not a prime number";
  }
}

int main() {
  // checkPrimeNumber(17);
  checkPrimeNumberOptimal(19);
}