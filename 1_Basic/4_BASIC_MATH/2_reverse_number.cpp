#include <bits/stdc++.h>
using namespace std;

// 2. Reverse of a number
/*
Note: If a number has trailing zeroes, then its reverse will not include
them. For eg, reverse of 10400 will be 401 instead of 00401.

Input
12345

Output
54321
*/

int reverseNumber(int n) {
  int revNum = 0;
  while(n > 0) {
    int lastDigit = n % 10;
    n = n / 10;
    revNum = revNum * 10 + lastDigit;
  }
  return revNum;
}

int main() {
  int output = reverseNumber(123456);
  cout << output;
}