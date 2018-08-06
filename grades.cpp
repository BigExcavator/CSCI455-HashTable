// Name:Ruohan Sun
// USC NetID:6539994087
// CSCI 455 PA5
// Spring 2018

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 *
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

//cstdlib needed for call to atoi
#include <cstdlib>

//the statements for all the functions that we will use
void dealCommends(Table * grades);
void insert(Table * grades);
void change(Table * grades);
void lookup(Table * grades);
void remove(Table * grades);
void print(Table * grades);
void help();

int main(int argc, char * argv[]) {

  // gets the hash table size from the command line

  int hashSize = Table::HASH_SIZE;

  Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

  if (argc > 1) {
    hashSize = atoi(argv[1]);  // atoi converts c-string to int

    if (hashSize < 1) {
      cout << "Command line argument (hashSize) must be a positive number"
	   << endl;
      return 1;
    }

    grades = new Table(hashSize);

  }
  else {   // no command line args given -- use default table size
    grades = new Table();
  }


  grades->hashStats(cout);

  // add more code here
  // Reminder: use -> when calling Table methods, since grades is type Table*
  dealCommends(grades);
  return 0;
}

/*
 * deal with the user's input commend
 */
void dealCommends(Table * grades){
  bool flag=true;
  string cmd;
  while(flag){
    cout<<"cmd>";
    cin>>cmd;
    if(cmd=="insert"){
    	  insert(grades); }
    else if(cmd=="change"){
      change(grades); }
    else if(cmd=="lookup"){
      lookup(grades); }
    else if(cmd=="remove"){
      remove(grades); }
    else if(cmd=="print"){
      print(grades); }
    else if(cmd=="size"){
    	  cout << "the number of students is "<<grades->numEntries()<<endl; }
    else if(cmd=="stats"){
    	  grades->hashStats(cout); }
    else if(cmd=="help"){
      help(); }
    else if(cmd=="quit"){
      flag=false; }
    else{
    	  cout << "ERROR: invalid command" << endl;
    	  help();
    }
  }
}

/*
 * Insert this name and score in the grade table. If this name was already present, print a message to that effect, and don't do the insert.
 */
void insert(Table * grades){
  string name;
  int score=0;
  cin>>name;
  cin>>score;
  grades->insert(name, score);
}

/*
 * Change the score for name. Print an appropriate message if this name isn't present.
 */
void change(Table * grades){
  string name;
  int score=0;
  cin>>name;
  cin>>score;
  if(grades->lookup(name)==NULL){
    cout<<"The name isn't in the table, please try again"<<endl;
  }
  else{
    grades->remove(name);
    grades->insert(name, score);
  }
}

/*
 * Lookup the name, and print out his or her score, or a message indicating that student is not in the table.
 */
void lookup(Table * grades){
  string name;
  cin>>name;
  if(grades->lookup(name)==NULL){
    cout<<"The student is not there, please try again."<<endl;
  }
  else{
    cout<<"Student's name: "<<name<<", score: "<<*grades->lookup(name)<<"."<<endl;
  }
}

/*
 * Remove this student. If this student wasn't in the grade table, print a message to that effect.
 */
void remove(Table * grades){
  string name;
  cin>>name;
  if(grades->lookup(name)==NULL){
    cout<<"The student isn't in the table, please try again."<<endl;
  }
  else{
    grades->remove(name);
  }
}

/*
 * Prints out all names and scores in the table.
 */
void print(Table * grades){
  if(grades->numEntries()==0){
    cout<<"The number of entries is 0."<<endl;
    cout<<"The longest chain is 0."<<endl;
  }
  else{
    grades->printAll();
  }
}


/*
 * Prints out a brief command summary.
 */
void help(){
  cout<<"You can only give the commends below:"<<endl;
  cout<< "insert name score : Insert the pair(name, score) into the table" << endl;
  cout<< "change name score : Change the score for a given name " << endl;
  cout<< "lookup name       : Lookup the name in the table, and print out the student's name and score" << endl;
  cout<< "remove name       : Remove the student with the given name from the table" << endl;
  cout<< "print             : Print out all student's name and score line by line" << endl;
  cout<< "size              : Get the total number of students in the table" << endl;
  cout<< "stats             : prints out info to let us know the distribution of the table" << endl;
  cout<< "quit              : Exit" << endl;
}


