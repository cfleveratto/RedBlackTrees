#ifndef INCLUDED_RBTREE
#define INCLUDED_RBTREE
#include "RBNode.h"
#include "constants.h"
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

  void insertFixUp(RBNode<T> * checkNode) {
    while (!(checkNode->getParent()->getColour())) {
      //ASSERT: that checkNodes parent is not RED.
      RBNode<T> * parent = checkNode->getParent();
      RBNode<T> * grandParent = checkNode->getParent()->getParent();
      if (parent == grandParent->getLeft()) {
	//ASSERT: checkNodes parent is the left child of
	//checkNode's grandparent.
	RBNode<T> * uncle = grandParent->getRight();
	if (uncle->getColour() == RED) {
	  parent->changeColour();
	  uncle->changeColour();
	  grandParent->changeColour();
	  checkNode = grandParent;
	}
	//ASSERT: checkNode's parent, grandParent, and uncle
	//were recoloured.  
	else if (checkNode == parent->getRight()) {
	  //ASSERT: checkNode is the right child of its parent
	  checkNode = parent;
	  leftRotate(checkNode);
	  //ASSERT: checkNode is now the left child
	}
	else {
	  parent->changeColour();
	  grandParent->changeColour();
	  rightRotate(grandParent);
	}
      }
      else {
	//ASSERT: checkNodes parent is the right child of
	//checkNode's grandparent.
	RBNode<T> * uncle = grandParent->getLeft();
	if (uncle->getColour() == RED) {
	  parent->changeColour();
	  uncle->changeColour();
	  grandParent->changeColour();
	  checkNode = grandParent;
	}
	//ASSERT: checkNode's parent, grandParent, and uncle
	//were recoloured.  
	else if (checkNode == parent->getLeft()) {
	  //ASSERT: checkNode is the right child of its parent
	  checkNode = parent;
	  rightRotate(checkNode);
	  //ASSERT: checkNode is now the left child
	}
	else {
	  parent->changeColour();
	  grandParent->changeColour();
	  leftRotate(grandParent);
	}
      }	
    }
  };
	  
  void leftRotate(RBNode<T> * rotationNode) {
    RBNode<T> * rightChild = rotationNode->getRight();
    rotationNode->setRightChild(rightChild);
    if (rightChild->getLeft() != NULL)
      rightChild->getLeft()->setParent(rotationNode);
    rightChild->setParent(rotationNode->getParent());
    if (rotationNode->getParent() == NULL)
      root = rightChild;
    else if (rotationNode == rotationNode->getParent()->getLeft())
      rotationNode->getParent()->setLeftChild(rightChild);
    else
      rotationNode->getParent()->setRightChild(rightChild);
    rightChild->setLeftChild(rotationNode);
    rotationNode->setParent(rightChild);
  };

  	  
  void rightRotate(RBNode<T> * rotationNode) {
    RBNode<T> * leftChild = rotationNode->getLeft();
    rotationNode->setLeftChild(leftChild);
    if (leftChild->getRight() != NULL)
      leftChild->getRight()->setParent(rotationNode);
    leftChild->setParent(rotationNode->getParent());
    if (rotationNode->getParent() == NULL)
      root = leftChild;
    else if (rotationNode == rotationNode->getParent()->getRight())
      rotationNode->getParent()->setRightChild(leftChild);
    else
      rotationNode->getParent()->setLeftChild(leftChild);
    leftChild->setRightChild(rotationNode);
    rotationNode->setParent(leftChild);
  };
    
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
    RBNode<T> * prevNode; //will hold a pointer to the
                          //parent of currNode
    RBNode<T> * currNode = root; //this will hold a
				 //pointer to the current
				 //node being checked.
    RBNode<T> * newNode = new RBNode<T>(element);
    //ASSERT: the RBNode that newNode points to is
    //allocated on the heap.
    if (numElements == EMPTY)
      root = newNode;
    else {
      //ASSERT: root is not NULL 
      while (currNode != NULL) {
	prevNode = currNode;
	if (newNode->getData() < currNode->getData())
	  currNode = currNode->getLeft();
	else
	  currNode = currNode->getRight();
      }
      //ASSERT: CurrNode points to a NULL node in this
      //RBTree.
      newNode->setParent(prevNode);
      if (newNode->getData() < prevNode->getData())
	prevNode->setLeftChild(newNode);
      else
	prevNode->setRightChild(newNode);
      //ASSERT: newNode is a child of an existing RBNode in
      //this tree and that the same existing RBNode now has
      //newNode as a child.
      insertFixUp(newNode);
      //ASSERT: the RBNodes in this tree are either red or
      //black.
      //        the RBNode that root points to is black
      //        if a RBNode is red, then its children are
      //black.
      //        all path from a RBNode to all subNodes contain
      //the same number of black RBNodes.
    }
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
