#include <bits/stdc++.h>
using namespace std;

// Q1: Print name n times using recursion.
// T.C. -> O(n)
// S.C. -> (stack space) -> O(N) 
void question1(int i, int n) {
  // Base Condition
  if(i > n) {
    return;
  }
  cout << "Rohan" << endl;
  question1(i + 1, n);
}

// Q2: Print linearly from 1 to N.
void question2(int i, int n) {
  if(i > n) return;
  cout << i << endl;
  question2(i+1, n);
}

// Q3: Print from N to 1.
void question3(int i, int n) {
  if(i < 1) return;
  cout << i << endl;
  question3(i-1, n);
}

// Q4: Print linearly from 1 to N. (but by breaktrack)
void question4(int i, int n) {
  if(i < 1) return;
  question3(i-1, n);
  cout << i << endl;
}

// Q5: Print from N to 1. (by backtrack).
void question5(int i, int n) {
  if(i > n) return;
  question5(i+1, n);
  cout << i << endl;
}

int main() {
  int n;
  cin >> n;
  // question1(1, n);
  // question2(1, n);
  // question3(n, n);
  // question4(n, n);
  question5(1, n);

}