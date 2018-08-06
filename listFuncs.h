// Name: Ruohan Sun
// USC NetID: 6539994087
// CSCI 455 PA5
// Spring 2018


//*************************************************************************
// Node class definition
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.


//initialize the ListType
void initList(ListType &list);

//print the entries in the list
void printAllEntry(ListType list);

//search for an entry with the target key, and return the pointer of it's value data
int* searchList(ListType list, string key);

//insert an entry into the list with the target key and target value
void insertEntry(ListType &list, string key, int value);

//remove the entry with the target key in the list
bool removeEntry(ListType &list, string key);

//count how many entries currently in the list, and return the number
int entryNum(ListType list);


#endif



