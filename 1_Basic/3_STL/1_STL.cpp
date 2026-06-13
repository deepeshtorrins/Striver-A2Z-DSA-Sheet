/*
Algorithms
Containers
Functions
Iterators
*/

#include <bits/stdc++.h>
using namespace std;

// ! Pair
void explainPair() {
  pair<int, int> p = {1, 3};
  cout << p.first << " " << p.second <<  endl;;

  pair<int, pair<int, int>> p2 = {1, {3, 4}};
  cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

  pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
  cout << arr[1].second << endl; // 5
}

// ! Container 1 - Vectors
void explainVector() {
  // ! Vector:
  // A vector is a dynamic array provided by C++ STL.
  // It stores elements in continuous memory.
  // Size can grow or shrink automatically.
  // It allows fast random access using index.

  // ! Creation & Insertion:
  // 0. Direct Initialization
  vector<int> v = {1, 2, 3, 4, 5};

  // 1. Empty vector
  vector<int> v1;
  v1.push_back(1);  // insert element at end
  v1.emplace_back(2);  // faster insertion (constructs in-place)

  for(int x : v1){
    cout << x << " ";
  }
  // Output:
  // 1 2

  // 2. Vector of pairs
  vector<pair<int, int>> v2;
  v2.push_back({1, 2});
  v2.emplace_back(3, 4);

  // 3. Vector with size and value
  vector<int> v3(5, 100); // {100, 100, 100, 100, 100}
  
  // 4. Vector with size only
  vector<int> v4(3); // {garbage value, garbage value, garbage value}
  
  // 5. Copy vector
  vector<int> v5(5, 20); // {20, 20, 20, 20, 20}
  vector<int> v6(v5);  // copy of v5

  // ! Accessing Elements
  vector<int> v7 = {1, 2, 3, 4, 5};
  cout << v7[0] << " " << v7.at(0) << endl;
  // [] → no bound checking
  // at() → bound checking
  
  cout << v7.front() << endl; // first element
  cout << v7.back() << endl;  // last element

  // ! Iterator
  // Iterator is like a pointer used to access container elements.
  
  vector<int>::iterator it = v7.begin(); // address of 0th index
  it++;

  cout << *(it) << endl; // 2

  it = it + 2;
  cout << *(it) << endl; // 4
  
  vector<int>::iterator it2 = v7.end(); // address of nth index
  
  // reverse iterators
  // vector<int>::iterator it = v7.rbegin(); // address of nth index
  // vector<int>::iterator it = v7.rend(); // address of nth index
  
  // ! Printing Vector

  // ? 1. Using Iterator
  for(vector<int>::iterator it = v7.begin(); it != v7.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl;
  
  // ? 2. Using Auto Iterator
  for(auto it = v7.begin(); it != v7.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl;
  
  // ? 3. Using ForEach Loop
  for(auto it : v7) {
    cout << it << " ";
  }
  cout << endl;
  
  // ! Deletion

  // ? 1. Pop 
  // removes last element
  vector<int> v11pop = {10, 40};
  v11pop.pop_back(); // {10}
  
  // ? 2. Delete one element
  vector<int> v8 = {10, 20, 30, 40, 50};
  v8.erase(v8.begin() + 1); // {10, 30, 40, 50}
  
  // ? 3. Delete multiple element
  vector<int> v9 = {10, 20, 30, 40, 50};
  v9.erase(v9.begin() + 2, v9.begin() + 4); // {10, 20, 50}

  // ! Insertion

  vector<int> v10(2, 100); // {100, 100}

  // insert at beginning
  v10.insert(v10.begin(), 300); // {300, 100, 100}
  
  // insert multiple values
  v10.insert(v10.begin()+1, 2, 10); // {300, 10, 10, 100, 100}

  // # =========== Vector Methods =============

  // ! Copy elements from another vector
  vector<int> copy(2, 50); // {50, 50}
  
  v10.insert(v10.begin(), copy.begin(), copy.end()); 
  // {50, 50, 300, 10, 10, 100, 100}
  
  // ! Size
  // {50, 50, 300, 10, 10, 100, 100}
  cout << v10.size(); // 7 // number of elements

  // ! Swap
  // swaps contents of two vectors

  vector<int> v12 = {20, 40};
  vector<int> v13 = {30, 50};

  v12.swap(v13);
  // v12 -> {30, 50}
  // v13 -> {20, 40}

  // ! Clear
  // removes all elements

  vector<int> v14 = {20, 40};
  v14.clear(); // erased the entire vector
  
  // ! Empty
  // checks if vector is empty

  cout << v14.empty(); // 1 (true)
}

// ! Container 2 - List
void explainList() {
  list<int> ls;

  ls.push_back(2); // {2}
  ls.emplace_back(4); // {2, 4}

  ls.push_front(5); // {5, 2, 4}

  ls.emplace_front(1); // {1, 5, 2, 4}

  for(int i : ls) {
    cout << i << " ";
  }

  // rest functions same as vector
  // begin, end, rbegin, rend, clear, insert, size, swap
}

// ! Container 3 - Deque
void explainDeque() {
  deque<int> dq;
  dq.push_back(1); // {1}
  dq.emplace_back(2); // {1, 2}
  dq.push_front(4); // {4, 1, 2}
  dq.emplace_front(3); // {3, 4, 1, 2}

  dq.pop_back(); // {3, 4, 1}
  dq.pop_front(); // {4, 1}

  dq.back();
  dq.front();

  // rest functions same as vector
  // begin, end, rbegin, rend, clear, insert, size, swap
}

// ! Container 4 - Stack
void explainStack() {
  // LIFO -> Last In First Out 
  stack<int> st;
  st.push(1); // {1}
  st.push(2); // {2, 1}
  st.push(3); // {3, 2, 1}
  st.push(4); // {4, 3, 2, 1}
  st.emplace(5); // {5, 4, 3, 2, 1}

  cout << st.top(); // print 5 
  // accessing through indexing is not allowed

  st.pop(); // st looks like {4, 3, 2, 1}

  cout << st.top(); // 4
  cout << st.size(); // 4
  cout << st.empty(); // False

  stack<int>st1, st2;
  st1.swap(st2);
}

// ! Container 5 - Queue
void explainQueue() {
  // FIFO -> First In First Out
  queue<int> q;
  q.push(1); // {1}
  q.push(2); // {1, 2}
  q.emplace(4); // {1, 2, 4}

  q.back() += 5;

  cout << q.back(); // prints 9

  // Q is {1, 2, 9}
  cout << q.front(); // prints 1

  q.pop(); // {2, 9}

  cout << q.front(); // prints 2

  // size swap empty same as stack
}

// ! Container 6 - Priority Queue
void explainPriorityQueue() {
  priority_queue<int> pq;

  pq.push(5); // {5}
  pq.push(2); // {5, 2}
  pq.push(8); // {8, 5, 2}
  pq.push(3); // {8, 3, 5, 2}
  pq.push(10); // {10, 8, 5, 2}

  cout << pq.top(); // prints 10

  pq.pop(); // {8, 5, 2}

  cout << pq.top(); // prints 8

  // size, swap, empty function same as others

  // Minimum Heap
  priority_queue<int, vector<int>, greater<int> > pq;
  pq.push(5); // {5}
  pq.push(2); // {2, 5}
  pq.push(8); // {2, 5, 8}
  pq.emplace(10); // {2, 5, 8, 10}

  cout << pq.top(); // prints 2

  // ! prints the priority queue
  // while (!pq.empty()) {
  //   cout << pq.top() << " ";
  //   pq.pop();
  // }

  /* 
  push -> logN
  top -> O(1)
  pop -> logN
  */
}

// ! Container 7 - Set
void printSet(set<int> st) {
  for (auto it = st.begin(); it != st.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

void explainSet() {
  // Sets store unique, sorted elements, ignoring duplicates

  //! Insert and Emplace
  set<int> st;
  st.insert(10);  // {10}
  st.emplace(20); // {10, 20}
  st.insert(20);  // {10, 20}
  st.insert(40);  // {10, 20, 40}
  st.insert(30);  // {10, 20, 30, 40}
  
  printSet(st); // 10 20 30 40

  /*
    Functionality of insert in vector can be used also,
    that only increases efficiency

    begin(), end(), rbegin(), rend(), size(),
    empty() and swap() are same as those of above
  */
 
  //! Find
  set<int> st2 = {30, 10, 20, 10, 40};  // {10, 20, 30, 40}
  auto it1 = st2.find(30); // return the iterator
  cout << *(it1) << endl; // 30

  // {10, 20, 30, 40}
  auto it2 = st.find(60);  // if value is not in set then it return st.end()

  //! Erase
  set<int> st3 = {30, 10, 20, 10, 40};  // {10, 20, 30, 40}
  st3.erase(30); // erases 30 // takes logarithmic time
  printSet(st3); // 10 20 40

  // 1 <- if exist; 0 <- if not exist
  // {10, 20, 40}
  int cnt = st3.count(20);
  cout << cnt << endl; // 1

  // {10, 20, 40}
  auto it3 = st3.find(20);
  st3.erase(it3);
  printSet(st3); // 10 40

  //! Find and erase element
  set<int> st4 = {30, 10, 20, 10, 40};  // {10, 20, 30, 40}
  auto it4 = st4.find(20);
  auto it5 = st4.find(40);

  // [first, last)
  st4.erase(it4, it5);
  // after erase
  printSet(st4); // 10 40

  /*
    lower_bound() and upper_bound() function works in the same way
    as in vector it does.
  */

  //! Lower bound & Upper bound
  set<int> st6 = {30, 10, 20, 10, 40};  // {10, 20, 30, 40}
  // Find the lower bound of 10 (present)
  auto it6 = st6.lower_bound(10);
  cout << *(it6) << endl; // 10
  
  auto it7 = st6.upper_bound(20);
  cout << *(it7) << endl; // 30

  //  Find the lower bound of 15 (not present, returns iterator to next greater element)
  auto it8 = st6.lower_bound(15);
  cout << *(it8) << endl; // 20
  
  auto it9 = st6.upper_bound(25);
  cout << *(it9) << endl; // 30

  //! Time Complexity of any operation is (logN).
}

// ! Container 8 - Multiset
void explainMultiSet() {
  // ! Multiset:
  // A multiset is a container in C++ STL that stores elements in sorted order.
  // It allows duplicate values.
  // Internally it is implemented using a balanced tree.

  // Everything is same as set
  // only stores duplicates elements also.

  // ? 1. insert()
  // It inserts an element into the multiset.
  multiset<int> ms;
  ms.insert(10); // {10}
  ms.insert(10); // {10, 10}
  ms.insert(10); // {10, 10, 10}
  
  // ? 2. count()
  // It returns the number of occurrences of an element.
  int cnt = ms.count(10);
  cout << "count: "<< cnt << endl; // count: 3

  // ? 3. erase()
  // It removes elements from the multiset.
  ms.erase(10); // removes all 10

  // ? 4. find()
  // only a single one erased
  ms.erase(ms.find(10));

  // ms.erase(ms.find(10), ms.find(10)+2);

  // reset all function same as set
}

// ! Container 9 - Unordered set
void explainUnorderedSet() {
  unordered_set<int> st;
  /*
  lower_bound and upper_bound function
  does not works, rest all functions are same
  as above, it does not stores in any
  particular order it has a better complexity
  than set in most cases, except some when collision happens
  */
}

// ! Container 10 - Map
void explainMap() {
  // It stores the value in sorted manner.

  // ? TYPE: 1
  // key, value
  map<int, int> mpp; // It is similiar
  mpp[1] = 2;
  mpp.emplace(3, 1);
  mpp.insert({2, 4});
  
  for(auto it : mpp) {
    cout << it.first << " " << it.second << endl;
  }
  /*
  ? OUTPUT
  1 2
  2 4
  3 1
  */

  cout << mpp[1] << endl; // 2
  cout << mpp[5] << endl; // this key is not present

  // ? TYPE: 2
  map<int, pair<int, int>> mpp2;
  mpp2[3] = {5, 7};
  auto it = mpp2.find(3);
  cout << it->second.first << " " << it->second.second;

  auto it2 = mpp2.find(5); // mpp2.end()
  
  // ? TYPE: 3
  map<pair<int, int>, int> mpp3;
  mpp3[{2, 3}] = 10;

  // ?
  // auto it3 = mpp2.lower_bound(2);
  // auto it4 = mpp2.upper_bound(3);

  // erase, swap, size, empty, are same as above
}

// ! Container 11 - Multi
void explainMultiMap() {
  // everything same as map, only it can store multiple keys
  // only mpp[key] cannot be used here

  // store duplicated keys, sorted ordered 
}

// ! Container 12 - Unordered Map
void explainUnorderedMap() {
  // same as set and unordered_Set difference.
  // not sorted, unique keys
}


bool comp(pair<int, int>p1, pair<int, int>p2) {
  if(p1.second < p2.second) {
    return true;
  } else if(p1.second == p2.second) {
    if(p1.first > p2.second) return true;
  }
  return false;
}

// ALGORITHMS
void explainExtra() {
  
}

int main() {
  // explainPair();
  // explainVector();
  // explainList();
  // explainPriorityQueue();
  // explainSet();
  // explainMultiSet();
  // unorderedSet();
  // explainMap();


  return 0;
}