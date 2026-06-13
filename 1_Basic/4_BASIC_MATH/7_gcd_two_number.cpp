#include <bits/stdc++.h>
using namespace std;

// 7. GCD of two numbers
// GCD / HCF -> Greatest Common Divisor / Highest Common Factor
/*

n1 = 9
9 = 1, 3, 9
    -  -

n2 = 12
12 = 1, 2, 3, 4, 6, 12
     -     -

GCD/HCF = 3

*/

// 1. Brute Force Approach
// T.C. -> O(min(n1, n2))
int gcdTwoNumbers(int n1, int n2) {
  int gcd = 1;
  for(int i = 1; i <= min(n1, n2); i++) {
    if(n1 % i == 0 && n2 % i == 0) {
      gcd = i;
    }
  }
  return gcd;
}

// 2. Better Approach
// T.C. -> O(min(n1, n2))
int gcdTwoNumbersBetter(int n1, int n2) {
  for(int i = min(n1, n2); i >=1; i--) {
    if(n1 % i == 0 && n2 % i == 0) {
      return i;
      break;
    }
  }
  return 1;
}


// 3. Optimal Approach

/* 

! Euclidean Algorithm
gcd(a, b) = gcd(a-b, b);  a>b

! Example
a = 20, b = 15
gcd(20, 15) -> gcd(5, 15) ->
gcd(15, 5) -> gcd(10, 5) -> gcd(5, 5) -> gcd(0, 5)

when one of the number is zero then other number is actually your gcd.

======================================================

gcd(a, b) -> gcd(a-b, b) - - - -> 0

a = 52, b = 10
gcd(52, 10) -> gcd(42, 10) -> gcd(32, 10) -> gcd(22, 10) -> gcd(12, 10) -> gcd(2, 10) 
another way -> [(52 % 10), 10] -> ([2 % 10], 10)

gcd(10, 2) -> gcd(8, 2) -> gcd(6, 2) -> gcd(4, 2) -> gcd(2, 2) -> gcd(0, 2)
another way -> [(10 % 2), 2] -> [0 % 2]

gcd(a, b) == gcd(a % b, b); a > b

======================================================

T.C. -> O(logQ (min(a, b)))
Q <- theta
why theda ? because here divisor change every time.

*/

int gcdTwoNumbersOptimal(int a, int b) {
  while(a > 0 && b > 0) {
    if(a > b) {
      a = a % b;
    } else {
      b = b % a;
    }
  }

  if(a == 0) return b;
  else return a;
}

int main() {
  // cout << gcdTwoNumbers(9, 12);
  // cout << gcdTwoNumbersBetter(9, 12);
  cout << gcdTwoNumbersOptimal(52, 10);
  
}