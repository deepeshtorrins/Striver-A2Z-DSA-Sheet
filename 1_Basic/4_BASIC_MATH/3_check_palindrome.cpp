#include<bits/stdc++.h>
using namespace std;

// 3. Check palindrone
/*
Write a program to determine if given number is palindrone or not.
Print true if it is palindrone, false otherwise.

Palindrone are the numbers for which reverse is exactly 
same as the original one. For eg, 121

Input
121

Output
It is palindrone
*/

// from previous question
int reverseNumber(int n) {
  int revNum = 0;
  while(n > 0) {
    int lastDigit = n % 10;
    n = n / 10;
    revNum = (revNum * 10) + lastDigit;
  }
  return revNum;
}

bool checkPalindrone(int n) {
  if(reverseNumber(n) == n) return true;
  return false;
}

int main() {
  bool output = checkPalindrone(1331);
  if(output == 1) {
    cout << "It is palindrone";
  } else {
    cout << "It is not palindrone";
  }
}
