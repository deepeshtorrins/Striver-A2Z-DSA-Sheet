#include <bits/stdc++.h>
using namespace std;

// ! Int Hashing
// T.C. -> O(n)
int main() {
  int n;
  cout << "Enter the length of array: ";
  cin >> n;

  int arr[n];

  cout << "Enter " << n << " elements of array: ";
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // precompute (assuming values are between 0 to 12)
  int hash[13] = {0};
  for(int i = 0; i < n; i++) {
    hash[arr[i]] += 1;
  }

  int q;
  cout << "Enter number of queries: ";
  cin >> q;

  cout << "Enter values to find occurrence:\n";
  while(q--) {
    int number;
    cin >> number;
    
    if(number >= 0 && number <= 12) {
      cout << "Count of " << number << " = " << hash[number] << endl;
    } else {
      cout << "Out of range (0-12)" << endl;
    }
  }
}


/*
- If you use an array for hashing (to store frequency/count), 
  then you need to be careful about the range of values in the array.
- If the range is too large, then it will lead to memory overflow.

for example, 
- if the range is 10^9, then you can't use array to store the count of occurrence of elements, 
  because it will lead to memory overflow. 
- In such cases, you can use map or unordered_map (hashing) which will be covered in upcoming videos.

Max limit to store element in array
 
for int ---------------------
inside main() -> arr[10^6]
globally -> arr[10^7]

for bool --------------------
inside main() -> arr[10^7]
globally -> arr[10^8]

for the 10^9, we will be using map or unordered_map (hashing) which will be covered in upcoming videos
*/
