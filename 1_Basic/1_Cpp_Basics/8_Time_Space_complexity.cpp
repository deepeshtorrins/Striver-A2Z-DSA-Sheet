/*

!1. What is Time complexity?
- Time complexity is not time taken.
- Rate at which the time taken increase with
  respect to the input size.

We calculate time complexity with Big-Oh Notation.

for(int i=1; i<= N; i++) {
  cout << "Raj";
}
TC: O(N x 3)

assigning
comparison
printing
increament

! 3 Rules:- Keep these 3 point in your mind while computing Big-Oh Notation.
1. always compute time complexity in terms of worst case scenrio.
2. avoid constants
3. avoid lower value

Best Case
Average Case
Worst Case

if(marks < 25) cout << "grade D"
else if(marks < 45) cout << "grade C"
else if(marks < 65) cout << "grade B"
else                cout << "grade A"

T.C.
Marks = 10 --> O(2) Best Case
Marks = 70 --> O(4) Worst Case

--------------------------------------------
# Example
O(4N^3 + 3N^2 + 8)

let N = 10^5
O(4N^15) Ans.

--------------------------------------------

Big-Oh (O)        Theta(0)         Omega()
Worst Case     Avg Complexity    Lowest Bond
[Upper Bond]

- Time complexity compute in terms of Big-Oh.
--------------------------------------------

!Question 1.
for(int i = 0; i < N; i++) {
  for(int j = 0; j < N; j++) {
    cout << j << endl;
  }
}

# Calculating time complexity
--
| i = 0 {j = 0, 1, 2, 3, ..., N-1}
| i = 1 {j = 0, 1, 2, 3, ..., N-1}
| i = 2 {j = 0, 1, 2, 3, ..., N-1}
| .
| .
| .
| i = N-1 {j = 0, 1, 2, 3, ..., N-1}
---

= N+N+N+N+N+N
= NxN
= O(N^2)

T.C.
O(N*N)

--------------------------------------------

!Question 2.
for(int i = 0; i < N; i++) {
  for(int j = 0; j <= i; j++) {
    cout << j << endl;
  }
}

# Calculating time complexity
---
| i = 0 {j = 0}
| i = 1 {j = 0, j = 1}
| i = 2 {j = 0, j = 1, j = 2}
| i = 3 {j = 0, j = 1, j = 2, j = 3}
| .
| .
| .
| i = n-1 {j = 0, j = 1, j = 2, j = 3, ...., j = n-1}
---

= (1 + 2 + 3 + 4 + .... + n)
  N x (N x 1)
= -----------
      2
= N^2/2 + N/2
= O(N^2/2)
=~ O(N^2)




*/

/*
! What is space complexity?
- It is the space that your program takes in.
- compute with Big-O Notation.

* Space complexity = Auxiliary Space + Input Space.

- Auxiliart Space -> space that you take to solve the problem.
- Input Space -> space that you take to store the input.

# Example
int main() {
  int a, b;
  cin >> a;
  cin >> b; // a and b are Input space.

  int c = a + b; // c is Auxiliary space.

  * Here the space complexity is O(3).
  beacause we are three different variable.
}


int arr[N]; // Space complexity is O(N).


int a, b;
cin >> a;
cin >> b;

// sum of two number
b = a + b //! never ever do anything on the input.


*/
