#ifndef INCLUDED_INPUT
#define INCLUDED_INPUT
#include "RBTree.h"
#include "constants.h"

//PRE: fileName is a pointer to a character array containing
//the name of a file.
//     tree is an empty.
//POST: tree contains nodes with int data that was read in
//from a file named the string that fileName points tothe
//was opened for reading.  
//     tree is defined and has a satisfied CI. 
void makeTree(RBTree<int> & tree, char * fileName);

#endif
