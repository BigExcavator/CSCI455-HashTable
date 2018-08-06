/// Name: Ruohan Sun
// USC NetID: 6539994087
// CSCI 455 PA5
// Spring 2018

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {
  cout << " This is a test case for list functions" << endl;


  Node *list;
  initList(list);
  cout << " Initialization success" << endl;
  insertEntry(list, "A", 10);
  insertEntry(list, "B", 20);
  insertEntry(list, "C", 30);
  cout << " Insert success!" << endl;
  cout << " Print all the entries in the list" << endl;
  printAllEntry(list);
  cout<<"The value of A: "<<*searchList(list, "A")<<endl;
  cout<<"The value of B: "<<*searchList(list, "B")<<endl;
  cout<<"The value of C: "<<*searchList(list, "C")<<endl;

  cout << "There are currently " << entryNum(list)<<" inside the list" <<endl;



  cout << "remove A " << bool(removeEntry(list, "A") )<< endl;
  cout << "remove B " << bool(removeEntry(list, "B") )<< endl;
  cout << "remove C " << bool(removeEntry(list, "C") )<< endl;

  cout << "There are currently " << entryNum(list)<<" inside the list" <<endl;

  return 0;
}
