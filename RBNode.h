#ifndef INCLUDED_RBNODE
#define INCLUDED_RBNODE
#include <iostream>
using namespace std;
template<class T>
class RBNode {
  //Class Invarient(CI): This object contains T data and is
  //coloured either black or red denoted where black = true
  //and red = false.

  //left and right point to another RBNode object with T
  //data where left < data and right >= data.

 private:
  T data; //contains data
  bool colour; //will hold whether this node is black or red.
  RBNode<T> * left; //Pointer to left child
  RBNode<T> * right; //Pointer to right child

 public:

  //PRE: element is of type T.
  //POST: This object is defined and has a satisfied CI.
  RBNode<T> (T element) {
    data = element;
    colour = false;
    left = NULL;
    right = NULL;
  };

};

#endif
  
    
