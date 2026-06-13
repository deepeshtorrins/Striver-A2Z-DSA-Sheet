#include <bits/stdc++.h>
using namespace std;

/*
Functions are set of code which performs something for you
Functions are used to modularise code
Functions are used to increase readability
Functions are used to use same code multiple times.

# Types of function
1. void -> which does not returns anything
2. return,
3. parameterised,
4. non-parameterised.
*/

//! 1. It is a void function as well as parameterised function.
/*
void printName(string name) {
  cout << "Hey, " << name << endl;
}

int main() {
  string name;
  cin >> name;
  printName(name);
}
*/

//! 2. Return, parameterised function.
// Question1: Take two numbers and print its sum.
/*
int sum(int num1, int num2) {
  int num3 = num1 + num2;
  return num3;
}

int main() {
  int num1 = 5;
  int num2 = 10;
  cout << sum(num1, num2);
}
*/

// ! 3. return function must have 'return'.
/*
int maxx(int num1, int num2) {
  if(num1 >= num2) {
    return num1;
  }

  // looking for a return line. otherwise it will print garbage.
  // means return is imp in return function!
  // return num2;
}

int main() {
  int num1, num2;
  cin >> num1 >> num2;
  int maximum = maxx(num1, num2);
  cout << maximum; // ! print garbage
  return 0;
}
*/

//! 4. pass by value

//# Example 1
/*
void doSomething(int num) {
  cout << num << endl;
  num += 5;
  cout << num << endl;
  num += 5;
  cout << num << endl;
}

int main() {
  int num = 10;
  doSomething(num);
  cout << num << endl;
  return 0;
}
*/

/*
OUTPUT
10
15
20
10
*/


//# Example 2
/*
void doSomething(string s) {
  s[0] = 't';
  cout << s << endl;
}

int main() {
  string s = "raj";
  doSomething(s);
  cout << s << endl;
  return 0;
}
*/

/*
OUTPUT
taj
raj
*/

//! 5. pass by reference
//# Example 1
/*
void doSomething(string &s) {
  s[0] = 't';
  cout << s << endl;
}

int main() {
  string s = "raj";
  doSomething(s);
  cout << s << endl;
  return 0;
}
*/

/*
OUTPUT
taj
taj
*/

//# Example 2
/*
void doSomething(int &num) {
  cout << num << endl;
  num += 5;
  cout << num << endl;
  num += 5;
  cout << num << endl;
}

int main() {
  int num = 10;
  doSomething(num);
  cout << num << endl;
  return 0;
}
*/

/*
OUTPUT
10
15
20
20
*/

//# Example 3
void doSomething(int arr[], int size) {
  arr[0] += 100;
  cout << "Value inside function: " << arr[0] << endl;
}

int main() {
  int arr[5];
  for(int i = 0; i < 5; i++) {
    cin >> arr[i];
  }

  doSomething(arr, 5);

  for(int i = 0; i < 5; i++) {
    cout << arr[i] << endl;
  }
}
