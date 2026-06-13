// https://www.youtube.com/watch?v=twuC1F6gLI8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=4

#include <bits/stdc++.h>
using namespace std;

// ! Q1: Reverse an array
// Approach 1:
void reverseArrayArroach1(int l, int r, int arr[]) {
  if(l >= r) {
    return;
  }

  swap(arr[l], arr[r]);
  reverseArrayArroach1(l+1, r-1, arr);
}

// Approach 2:
void reverseArrayArroach2(int i, int arr[], int size) {
  if(i >= size/2) {
    return;
  }

  swap(arr[i], arr[size-1-i]);
  reverseArrayArroach2(i+1, arr, size);
}

// ! Q2: Given string is palindrone or not.
bool checkPalindrone(string str, int i, int n) {
  if(i >= n/2) return true;

  if(str[i] != str[n-1-i]) return false;
  
  return checkPalindrone(str, i+1, n);
}

int main() {
  int arr[] = {8, 6, 4, 2};
  for(int it : arr) cout << it << " ";
  cout << endl;
  
  // reverseArrayArroach1(0, 3, arr);
  reverseArrayArroach2(0, arr, 4);
  
  for(int it : arr) cout << it << " ";
  cout << endl;

  string str = "MADAM";

  cout << checkPalindrone(str, 0, 5);

}
