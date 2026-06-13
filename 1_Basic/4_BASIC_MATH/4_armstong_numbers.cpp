#include <bits/stdc++.h>
using namespace std;

// 4. Check if the Number is Armstrong
/* An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.

// Example 1
N = 371
3^3 + 7^3 + 1^3 = 371

// Example 2

N = 1634
1^4 + 6^4 + 3^4 + 4^4 = 1634
*/

/*
Input
1634

Output
true
*/

// Count Digits
int countDigits(int n) {
  int count = 0;
  while(n != 0) {
    count++;
    n = n / 10;
  }
  return count;
}

void isArmStoneNumber(int n) {
  int originalNum = n;
  int armStrong = 0;
  int cntDigits = countDigits(n);
  
  while(n > 0) {
    int lastDigit = n % 10;
    n = n / 10;
    armStrong += pow(lastDigit, cntDigits);
  }

  if(armStrong == originalNum) {
    cout << "It is arm strong number";
  } else {
    cout << "It is not arm strong number";
  }
}

int main() {
  isArmStoneNumber(1634);
}