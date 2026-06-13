/*
PATTERNS
Why are they important in order to start off with DSA.
- beause it you want to master the loops then you want to
understand how loops work if you know how to play around it
then you can get very very good at data structure and algorithms
and for loops you have to do patterns this is the reason we will
be solving a bunch of patterns.

interviewer never ask patterns except service based company (TCS)

Steps
1. for the outer loop, count the no. of lines.
2. for the inner loop, focus on the columns, & connect them
somehow to the rows.
3. print them '*' inside the inner for loop.
4. observe symmetry [optional].

https://takeuforward.org/strivers-a2z-dsa-course/must-do-pattern-problems-before-starting-dsa

*/

#include <bits/stdc++.h>
using namespace std;

/*
Q1:
* * * * *
* * * * *
* * * * *
* * * * *
* * * * *
*/

void print1(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
}

/*
Q2:
*
* *
* * *
* * * *
* * * * *

index -> no. of '*'
0 -> 1
1 -> 2
2 -> 3
3 -> 4
4 -> 5
*/

void print2(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
}

/*
Q3:
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
*/

void print3(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}

/*
Q4:
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
*/

void print4(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << i << " ";
    }
    cout << endl;
  }
}

/*
Q5:
* * * * *
* * * *
* * *
* *
*

line no. -> no. of '*'
1 -> 5
2 -> 4
3 -> 3
4 -> 2
5 -> 1
formula = n - row + 1
*/

void print5(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n - i + 1; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
}

/*
Q6:
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
*/

void print6(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n - i + 1; j++)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}

/*
Q7:
@@@@*@@@@
@@@***@@@
@@*****@@
@*******@
*********

space | star | space
4 | 1 | 4
3 | 3 | 3
2 | 5 | 2
1 | 7 | 1
0 | 9 | 0
*/

void print7(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    for (int k = 0; k < (2 * i) + 1; k++)
    {
      cout << "*";
    }
    for (int l = 0; l < n - i - 1; l++)
    {
      cout << " ";
    }
    cout << endl;
  }
}

/*
Q8:
*********
@*******@
@@*****@@
@@@***@@@
@@@@*@@@@

space | star | space
0 | 9 | 0
1 | 7 | 1
2 | 5 | 2
3 | 3 | 3
4 | 1 | 4
*/

void print8(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }
    for (int k = 0; k < (2 * n) - (2 * i) - 1; k++)
    {
      cout << "*";
    }
    for (int l = 0; l < i; l++)
    {
      cout << " ";
    }
    cout << endl;
  }
}

/*
Q9:
@@@@*@@@@
@@@***@@@
@@*****@@
@*******@
*********
*********
@*******@
@@*****@@
@@@***@@@
@@@@*@@@@
*/

/*
! Q10:

*
**
***
****
*****
****
***
**
*

*/

void print10(int n)
{
  for (int i = 1; i <= 2 * n - 1; i++)
  {
    int space = i;
    if (i > n)
      space = 2 * n - i;

    for (int j = 1; j <= space; j++)
    {
      cout << "* ";
    }

    cout << endl;
  }
}

/*
Q11:

1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
*/

void print11(int n)
{

  for (int i = 1; i <= n; i++)
  {
    int startNum = i % 2;

    for (int j = 1; j <= i; j++)
    {
      startNum = startNum == 1 ? 0 : 1;
      cout << startNum;
    }

    cout << endl;
  }
}

/*
Q12:

1             1
1 2         2 1
1 2 3     3 2 1
1 2 3 4 4 3 2 1
*/

void print12(int n)
{
  int space = 2 * n - 1;

  for (int i = 1; i <= n; i++)
  {

    // Left
    for (int j = 1; j <= i; j++)
    {
      cout << j;
    }

    // Center
    for (int k = 1; k <= space; k++)
    {
      cout << " ";
    }

    // Right
    // int r = i;
    // for(int j = 1; j <= i; j++) {
    //   cout << r;
    //   r-=1;
    // }
    for (int j = i; j >= 1; j--)
    {
      cout << j;
    }

    cout << endl;
    space = space - 2;
  }
}

/*
Q13:

1
2  3
4  5  6
7  8  9  10
11 12 13 14 15
*/

void print13(int n)
{
  int num = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << num << " ";
      num++;
    }
    cout << endl;
  }
}

/*
! Q14:

A
A B
A B C
A B C D
A B C D E
*/

void print14(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (char j = 'A'; j <= 'A' + i; j++)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}

/*
! Q15:

A B C D E
A B C D
A B C
A B
A
*/

void print15(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (char j = 'A'; j <= 'A' + (n - i - 1); j++)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}

/*
! Q16:

A
B B
C C C
D D D D
E E E E E
*/

void print16(int n)
{
  for (int i = 0; i < n; i++)
  {
    char ch = 'A' + i;
    for (int j = 0; j <= i; j++)
    {
      cout << ch << " ";
    }
    cout << endl;
  }
}

/*
! Q17:

   A
  ABA
 ABCBA
ABCDCBA
*/

void print17(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    char ch = 'A';
    int chV = 2 * i + 1;
    for (int k = 1; k <= chV; k++)
    {
      cout << ch;

      if (k <= chV / 2)
      {
        ch++;
      }
      else
      {
        ch--;
      }
    }
    cout << endl;
  }
}

/*
! Q18:

E
D E
C D E
B C D E
A B C D E
*/

void print18(int n)
{
  for (int i = 1; i <= n; i++)
  {
    char startCh = 'A' + n - i;
    for (int j = 1; j <= i; j++)
    {
      cout << startCh++;
    }
    cout << endl;
  }
}

void print18Approach2(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (char ch = 'E' - i; ch <= 'E'; ch++)
    {
      cout << ch << " ";
    }
    cout << endl;
  }
}

/*
! Q19:

**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/

void print19(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = n - i; j > 0; j--)
    {
      cout << "*";
    }
    for (int j = 0; j < i * 2; j++)
    {
      cout << " ";
    }
    for (int j = n - i; j > 0; j--)
    {
      cout << "*";
    }
    cout << endl;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << "*";
    }
    for (int j = 0; j < (2 * n - 2 * (i + 1)); j++)
    {
      cout << " ";
    }
    for (int j = 0; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

/*
! Q20:

*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
*/

void print20(int n) {
  int mid = (2 * n / 2);
  // int space = 2*n - 2*i;
  int space = 2 * n;
  for (int i = 1; i <= 2 * n - 1; i++) {
    int star = i;
    if (i > mid) star = 2 * n - i;

    if (i > mid) {
      space = space + 2;
    }
    else {
      space = space - 2;
    }

    // star
    for (int j = 1; j <= star; j++) {
      cout << "*";
    }

    // space
    // 8, 6, 4, 2, 0
    for (int j = 1; j <= space; j++) {
      cout << " ";
    }

    // star
    for (int j = 1; j <= star; j++) {
      cout << "*";
    }

    cout << endl;
  }
}

/*
! Q21:

****
*  *
*  *
****
*/

void print21(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
        cout << "*";
      }
      else {
        cout << " ";
      }
    }
    cout << endl;
  }
}

/*
! Q22

  0 1 2 3 4 5 6 <- index
0 4 4 4 4 4 4 4
1 4 3 3 3 3 3 4
2 4 3 2 2 2 3 4
3 4 3 2 1 2 3 4
4 4 3 2 2 2 3 4
5 4 3 3 3 3 3 4
6 4 4 4 4 4 4 4
^
|
index


1. iterate 2*n-1.
2. pick a element in matric and find the top, bottom, left, right distance.
3. pick the shortest distance from (top, bottom, left, right) and print.
    0 0 0 0 0 0 0
    0 1 1 1 1 1 0
    0 1 2 2 2 1 0
    0 1 2 3 2 1 0
    0 1 2 2 2 1 0
    0 1 1 1 1 1 0
    0 0 0 0 0 0 0
4. subtract each value by n.
*/

void print22(int n) {
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      int top = i;
      int left = j;
      int bottom = (2 * n - 2) - i;
      int right = (2 * n - 2) - j;

      cout << (n - min(min(top, bottom), min(left, right))) << " ";
    }
    cout << endl;
  }
}

int main() {
  print22(4);
}
