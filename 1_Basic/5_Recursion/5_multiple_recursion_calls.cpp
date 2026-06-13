// Multiple Recursion Calls
#include <bits/stdc++.h>
using namespace std;

int nthFibonacci(int n) {
  if(n <= 1) {
    return n;
  }
  int last = nthFibonacci(n-1);
  int secondLast= nthFibonacci(n-2);
  return last + secondLast;
}

int main() {
  cout << nthFibonacci(8); // 21
}
