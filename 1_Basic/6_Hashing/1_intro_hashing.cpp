#include <bits/stdc++.h>
using namespace std;

//! Introduction of hashing
// T.C. = n * m  (n = array length, m = number of values to find)

/*
n = 10^5
m = 10^5
T.C. = 10^10

if 10^8 -> 1 sec
then, 10^10 -> 100 sec (we can't wait for 100 sec for this execute)
where is something like hashing comes technique which will help you to
do it in a much faster way

Hashing -> it is something like pre-storing and fetch when required.
*/

void findOccurrences(int arr[], int n, int findNums[], int m) {
  
  for(int j = 0; j < m; j++) {
    int count = 0;
  
    for(int i = 0; i < n; i++) {
      if(arr[i] == findNums[j]) {
        count = count + 1;
      }
    }

    cout << "Count of " << findNums[j] << " = " << count << endl;
  }
}

int main() {
  int arr[] = {1, 2, 1, 3, 2};
  int n = sizeof(arr) / sizeof(arr[0]);

  int findNums[] = {1, 3, 4, 2, 10, 12}; // multiple values
  int m = sizeof(findNums) / sizeof(findNums[0]);
  
  findOccurrences(arr, n, findNums, m);
}


