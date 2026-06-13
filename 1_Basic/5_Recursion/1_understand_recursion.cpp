#include <bits/stdc++.h>
using namespace std;
/*
  1. What we learn
  2. What is Recursion?
  3. How recursion works?
  4. What is Base Condition ?
  5. What is Segmentation fault / Stack Overflow?
  6. What is Recursion Tree?
*/

/*
Q: What is Recursion?
- When a function calls itself
  until a specified condition is met.
*/

int num = 0;

void printN() {
  if(num == 3) {
    return;
  }
  
  cout << num << " ";
  num++;

  printN();
}

int main() {
  printN();
}
