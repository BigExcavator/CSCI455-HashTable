// Name: Ruohan Sun
// USC NetID: 6539994087
// CSCI 455 PA5
// Spring 2018

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


/*
 * create an empty table, i.e., one where numEntries() is 0, with default size: HASH_SIZE
 */
Table::Table() {
  hashSize=HASH_SIZE;
  myTable=new ListType[hashSize];
  for(int i=0; i<hashSize; i++){
    initList(myTable[i]);
  }
}

/*
 * create an empty table, i.e., one where numEntries() is 0, with the given size: hSize
 */
Table::Table(unsigned int hSize) {
  hashSize=hSize;
  myTable=new ListType[hashSize];
  for(int i=0; i<hashSize; i++){
    initList(myTable[i]);
  }
}

/*
 * get the value's address for the target key, or return NULL if didn't exist
 */
int * Table::lookup(const string &key) {
  ListType list=myTable[hashCode(key)];
  return searchList(list, key);
}

/*
 * remove an element, false iff element wasn't present
 */
bool Table::remove(const string &key) {
  ListType &list=myTable[hashCode(key)];
  return removeEntry(list, key);
}

/*
 * insert a new pair into the table, return false iff this key was already present
 */
bool Table::insert(const string &key, int value) {
  ListType &list=myTable[hashCode(key)];
  if(searchList(list, key)==NULL){
    insertEntry(list, key, value);
    return true;
  }
  else{
    cout<<"There is already an entry with key: "<<key<<" inside the table, please try again"<<endl;
    return false;
  }

}

/*
 * return the number of entries in the table
 */
int Table::numEntries() const {
  int sum=0;
  for(int i=0; i<hashSize; i++){
    sum+=entryNum(myTable[i]);
  }
  return sum;
}

/*
 * print out all the entries in the table, one per line.
 */
void Table::printAll() const {
  if(numEntries()==0){
    cout<<"There is no entries in the table now!"<<endl;
    return;
  }
  for(int i = 0; i < hashSize; i++) {
    printAllEntry(myTable[i]);
  }
}

/*
 * prints out info to let us know if we're getting a good distribution.
 */
void Table::hashStats(ostream &out) const {
  int nonEmpty=0;
  int longest=0;
  for(int i = 0; i < hashSize; i++) {
    if( entryNum(myTable[i])>0) {
      nonEmpty+=1;
      if(entryNum(myTable[i]) > longest) {
    	    longest = entryNum(myTable[i]);
      }
    }
  }
  cout << "number of buckets: " << hashSize << endl;
  cout << "number of entries: " << numEntries() << endl;
  cout << "number of non-empty buckets: " << nonEmpty << endl;
  cout << "longest chain: " << longest << endl;
}





