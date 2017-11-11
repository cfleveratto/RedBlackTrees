#ifndef INCLUDED_RBTREE
#define INCLUDED_RBTREE

#include "RBNode.h"
#include <iostream>
using namespace std;

template <class T>
class RBTree {

  // CI: This object is an ordered binary tree with nodes coloured red
  //       and black, and this object satisfies the properties of a 
  //       red-black tree. NULL nodes are assumed to be coloured black.

 private:
  RBNode<T> * root;   // Pointer to the node that is the root of the
		      // tree.
  
  int numElements;    // Number of elements in the tree.

 public:
  
  //PRE: None
  //POST: this object is empty
  RBTree<T>  () {
    root = NULL;
    numElements = 0;
  };

  // PRE: element is defined. There is no node in the tree that
  //        contains data equal to element. This object satisfies the CI.
  // POST: element is inserted into this object, and this object
  //        satisfies the CI.
  void insert (T element) {
    
  };

  // PRE: This object satisfies the CI.
  // POST: OS contains information for each node using pre-order
  //         traversal. 
  void printPreOrder () const {
    // FILL IN CODE HERE
  };

  // PRE: This object satisfies the CI.
  // POST: OS contains information for each node using in-order
  //         traversal. 
  void printInOrder () const {
    // FILL IN CODE HERE
  };

  // PRE: This object satisfies the CI.
  // POST: All dynamic memory allocated for this object (except any
  //         data allocated for T objects) is deallocated.
  ~RBTree<T>() {
    // FILL IN CODE HERE
  };
};

#endif
