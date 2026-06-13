// 1. Count all Digits of a Number

/*
Given the number 'n'. 
find out and return the number of digits present in a number.

Input
5678

Output
4
*/

#include <iostream>
using namespace std;

// T.C. O(log10(N))
int count(int n) {
  int cnt = 0;
  while(n > 0) {
    cnt++;
    n = n / 10;
  }
  return cnt;
}
/*
In the above problem, if division is happening by 10 that's means
n/10 -> log10(n)
n/5 -> log5(n)
n/2 -> log2(n)
*/

/* 
! Another approach 
int n = 67887;
int cnt = (int)(log10(n) + 1); // 5
cout << cnt;
*/

int main() {
  int output = count(4565);
  cout << output;
}
