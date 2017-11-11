#include "inputFunctions.h"
#include <fstream>
#include <iostream>
using namespace std;

//PRE: fileName is a pointer to a character array containing
//the name of a file.
//     tree is an empty.
//POST: tree contains nodes with int data that was read in
//from a file named the string that fileName points tothe
//was opened for reading.  
//     tree is defined and has a satisfied CI. 
void makeTree(RBTree<int> & tree, char * fileName) {
  ifstream inFile(fileName);
  if (inFile != NULL) {
    int readInt; //will hold int that was read in
    while (!inFile.eof()) {
      inFile >> readInt;
      cout << readInt;
    }
  }
  else cout << "File does not exist" << endl;
  //ASSERT: all integers were read in from the stream iff
  //fileName is an existing file name.
}
