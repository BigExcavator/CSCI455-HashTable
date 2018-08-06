// Name: Ruohan Sun
// USC NetID: 6539994087
// CSCI 455 PA5
// Spring 2018

#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}


//*************************************************************************
// put the function definitions for your list functions below

/*
 * initialize the ListType
 */
void initList(ListType &list){
  list=NULL;
}

/*
 * print the entries in the list
 */
void printAllEntry(ListType list){
  Node *traver=list;

  while(traver!=NULL){
    cout<<traver->key<<" "<<traver->value<<"."<<endl;
    traver=traver->next;
  }
}

/*
 * search for an entry with the target key, and return the address of the value
 */

int* searchList(ListType list, string key){
  Node *traver=list;

  while(traver!=NULL){
    if(traver->key==key){
      return &(traver->value) ;
    }
    traver=traver->next;
  }

  return NULL;
}

/*
 * insert an entry into the list with the target key and target value
 */
void insertEntry(ListType &list, string key, int value){
  Node *firstEntry=new Node( key, value, list);
  list=firstEntry;
}

/*
 * remove the entry with the target key in the list
 */
bool removeEntry(ListType &list, string key){
  if(list==NULL){
    return false;
  }

  Node *traver=list;
  if(traver->key==key){
    list=list->next;
    delete traver;
    return true;
  }

  while(traver!=NULL){
    if(traver->next!=NULL && traver->next->key==key){
      Node *helper=traver->next;
      traver->next=traver->next->next;
      delete helper;
      return true;
    }
    else{
      traver=traver->next;
    }
  }

  return false;

}

/*
 * count how many entries currently in the list, and return the number
 */
int entryNum(ListType list){
  Node *traver=list;
  int num=0;
  while(traver!=NULL){
    num+=1;
    traver=traver->next;
  }
  return num;
}
