#include <bits/stdc++.h>
using namespace std;

// ! Character Hashing

/*
Q1: Given a string 's' consisting of lowercase letters, process multiple queries.
    For each query, return how many times a given character appears in the string.
*/

void findOccurenceOfChar() {
  string s; // abcabc
  cout << "Enter the string: ";
  cin >> s;

  int hash[26] = {0}; // Assume only lowercase letters a-z are present in the string

  // Precompute
  for(int i = 0; i < s.size(); i++) {
    hash[s[i] - 'a']++;
  }

  int q;
  cout << "Enter number of queries: ";
  cin >> q;
  
  cout << "Enter characters to find occurrence:\n";
  while(q--) {
    char c;
    cin >> c;
    
    if(c >= 'a' && c <= 'z') {
      cout << "Count of '" << c << "' = " << hash[c - 'a'] << endl;
    } else {
      cout << "Invalid input (only lowercase a-z allowed)" << endl;
    }
  }

}

/*
Q2: Given a string 's' consisting of lowercase letters, uppercase letters, or any other character,
    process multiple queries. For each query, return how many times a given character appears in the string.
*/
void findOccurenceOfChar2() {
  string s; // abcabc
  cout << "Enter the string: ";
  cin >> s;

  int hash[256] = {0};

  // Precompute
  for(int i = 0; i < s.size(); i++) {
    hash[s[i]]++;
  }

  int q;
  cout << "Enter number of queries: ";
  cin >> q;
  
  cout << "Enter characters to find occurrence:\n";
  while(q--) {
    char c;
    cin >> c;
    
    cout << "Count of '" << c << "' = " << hash[c] << endl;
  }

}

int main() {
  // findOccurenceOfChar();
  findOccurenceOfChar2();
}

/*
1. In integer array we can do hashing using array (if the range is small) or map/unordered_map (if the range is large)
  if the range is 10^9, then we can't use array to store the count of occurrence of elements,

2. but in character array, it has a small range of 256 characters, so we can use array to store the count of occurrence of characters.
  so always prefer to use array for character hashing because of small range of characters.
*/
