#ifndef INCLUDED_RBNODE
#define INCLUDED_RBNODE
#include <iostream>
#include "constants.h"
using namespace std;
template<class T>
class RBNode {
  //Class Invarient(CI): This object contains T data and is
  //coloured either black or red denoted where black = true
  //and red = false.

  //parent points to the previous Node that this node is a
  //child to. 
  //left and right point to another RBNode object with T
  //data where left < data and right >= data.

 private:
  T data; //contains data
  bool colour; //will hold whether this node is black or red.
  RBNode<T> * parent; // will hold a pointer to its parent.
  RBNode<T> * left; //Pointer to left child
  RBNode<T> * right; //Pointer to right child

 public:

  //PRE: element is of type T.
  //POST: This object is defined and has a satisfied CI.
  RBNode<T> (T element) {
    data = element;
    colour = RED;
    parent = NULL;
    left = NULL;
    right = NULL;
  };

  // ===================================
  //               ACCESSORS
  // ===================================

  //PRE: This Node is defined and has a satisfied CI.
  //POST RV = true iff this node is black; Otherwise RV =
  //false if this node is red.
  bool getColour() const {
    return(colour);
  };
    
  //Returns the data this Node contains
  T getData() const{
    return(data);
  };

  //Returns what parent points to.
  RBNode<T> * getParent() const {
    return(parent);
  };
  
  //Returns what left points to.
  RBNode<T> * getLeft() const {
    return(left);
  };

  //Returns what right points to.
  RBNode<T> * getRight() const {
    return(right);
  };

  // ===================================
  //              MODIFIER
  // ===================================

  //PRE: points to a defined RBNode data object with a
  //satisfied CI.
  //POST: this node has is a child to a parent Node which
  //parent points to.
  void setParent(RBNode<T> * nodeParent) {
    parent = nodeParent;
  };

  void setLeftChild(RBNode<T> * leftChild) {
    left = leftChild;
  };

  void setRightChild(RBNode<T> * rightChild) {
    right = rightChild;
  };

  void changeColour(bool newColour) {
    colour = newColour;
  };
  
  // PRE: This object satisfies the CI.
  // POST: All dynamic memory allocated for this object (except any
  //         data allocated for T objects) is deallocated.
  ~RBNode<T>() {
    if (left != NULL) 
      delete left;
    if (right != NULL)
      delete right;
  };
  
};

#endif
  
    
