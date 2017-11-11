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

  // ================================================
  //                 HELPER FUNCTIONS
  // ================================================

  //PRE: checkNode points to a RBNode object that is
  //dynamically allocated on the heap.
  //POST: the RBNodes in this tree are either red or
  //black.
  //      the RBNode that root points to is black
  //      if a RBNode is red, then its children are
  //black.
  //      all paths from a RBNode to all subNodes contain
  //the same number of black RBNodes.
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
	  //ASSERT: checkNode's parent, grandParent, and uncle
	  //were recoloured.  
	}
	
	else if (checkNode == parent->getRight()) {
	  //ASSERT: checkNode is the right child of its parent
	  checkNode = parent;
	  leftRotate(checkNode);
	  //ASSERT: checkNode is now the original checkNodes
	  //parent
	  //        original checkNodes parent was rotated
	  //to the left 
	}

	else {
	  parent->changeColour();
	  grandParent->changeColour();
	  rightRotate(grandParent);
	  //ASSERT: checkNode's parent and grandParent were
	  //recoloured and checkNode's grandparent was rotated
	  //to the right
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
	  //ASSERT: checkNode's parent, grandParent, and uncle
	  //were recoloured.  
	}
	else if (checkNode == parent->getLeft()) {
	  //ASSERT: checkNode is the right child of its parent
	  checkNode = parent;
	  rightRotate(checkNode);
	  //ASSERT: checkNode is now the original checkNodes
	  //parent
	  //        original checkNodes parent was rotated
	  //to the right 
	}
	else {
	  parent->changeColour();
	  grandParent->changeColour();
	  leftRotate(grandParent);
	  //ASSERT: checkNode's parent and grandParent were
	  //recoloured and checkNode's grandparent was rotated
	  //to the left
	}
      }	
    }
  };

  //PRE: rotationNode points to a RBNode object that is
  //dynamically allocated on the heap.
  //POST: rotateNode becomes the left child of its original
  //right child.
  //      rotationNodes right child points to the left child
  //of its original right child.
  void leftRotate(RBNode<T> * rotationNode) {
    RBNode<T> * rightChild = rotationNode->getRight();
    //ASSERT: rightChild points to rotationNodes right
    //child. 
    rotationNode->setRightChild(rightChild->getLeft());
    //ASSERT: rightChild's leftChild is now rotationNodes
    //rightChild. 
    if (rightChild->getLeft() != NULL)
      //ASSERT: rightChild does not have NULL node as a left
      //child. 
      rightChild->getLeft()->setParent(rotationNode);
    rightChild->setParent(rotationNode->getParent());
    //ASSERT: rightChild's parent is now rotationNodes
    //original Parent.
    if (rotationNode->getParent() == NULL)
      //ASSERT: rotationNode was not the root of the tree
      root = rightChild;
    else if (rotationNode == rotationNode->getParent()->getLeft())
      //ASSERT: rotationNode is the left child of its parent.
      rotationNode->getParent()->setLeftChild(rightChild);
    else
      //ASSERT: rotationNode was the right child of its parent.
      rotationNode->getParent()->setRightChild(rightChild);
    rightChild->setLeftChild(rotationNode);
    //ASSERT: rotationNode is now the left child of its
    //original right child
    rotationNode->setParent(rightChild);
    //ASSERT: rightChild is now the parent of rotationNode
  };

  
  //PRE: rotationNode points to a RBNode object that is
  //dynamically allocated on the heap.
  //POST: rotateNode becomes the right child of its original
  //left child.
  //      rotationNodes left child points to the right child
  //of its original left child.
  void rightRotate(RBNode<T> * rotationNode) {
    RBNode<T> * leftChild = rotationNode->getLeft();
    //ASSERT: leftChild points to rotationNodes left
    //child. 
    rotationNode->setLeftChild(leftChild->getRight());
    //ASSERT: leftChild's rightChild is now rotationNodes
    //leftChild. 
    if (leftChild->getRight() != NULL)
      leftChild->getRight()->setParent(rotationNode);
    leftChild->setParent(rotationNode->getParent());
    //ASSERT: leftChild's parent is now rotationNodes
    //original Parent.
    if (rotationNode->getParent() == NULL)
      //ASSERT: rotationNode was not the root of the tree
      root = leftChild;
    else if (rotationNode == rotationNode->getParent()->getRight())
      //ASSERT: rotationNode is the right child of its parent.
      rotationNode->getParent()->setRightChild(leftChild);
    else
      //ASSERT: rotationNode was the left child of its parent.
      rotationNode->getParent()->setLeftChild(leftChild);
    leftChild->setRightChild(rotationNode);
    //ASSERT: rotationNode is now the right child of its
    //original left child
    rotationNode->setParent(leftChild);
    //ASSERT: leftChild is now the parent of rotationNode
  };

  //PRE: currNode points either to an existing RBNode or to
  //a NULL Node.
  //POST: currNodes data is printed out then traverse to the
  //left most Node followed by its right most Node iff
  //currNode is not a NULL Node
  void traversePre(RBNode<T> * currNode) const{
    if (currNode != NULL) {
      cout << currNode->getData();
      if (currNode->getLeft() != NULL) {
	traversePre(currNode->getLeft());
	//ASSERT: currNodes left childs data is printed out
	//then traverse to the left most Node followed by its
	//right most Node iff currNode is not a NULL Node
      }
      if (currNode->getRight() != NULL) {
	traversePre(currNode->getRight());
	//ASSERT: currNodes right childs data is printed out
	//then traverse to the left most Node followed by its
	//right most Node iff currNode is not a NULL Node
      }
      
    }
  };

  
  //PRE: currNode points either to an existing RBNode or to
  //a NULL Node.
  //POST: traverses to left most Node, returns and prints
  //CurrNodes data and then traverses to the right mostNode
  //iff currNode is not a NULL Node;
  void traverseIn(RBNode<T> * currNode) const{
    if (currNode != NULL) {
      if (currNode->getLeft() != NULL) {
	traversePre(currNode->getLeft());
	//ASSERT: the left most Node of currNodes left child
	//is traversed, returns and prints out the left
	//childs data. It then traverse to the left childs
	//right most Node. 
      }
      cout << currNode->getData();
      if (currNode->getRight() != NULL) {
	traversePre(currNode->getRight());
	//ASSERT: the left most Node of currNodes right child
	//is traversed, returns and prints out the right
	//childs data. It then traverse to the right childs
	//right most Node. 
      }
    }
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
    RBNode<T> * currNode = root;
    if (currNode != NULL)
      traversePre(currNode);
    else
            cout << "This Red Black Tree is empty.\n";
  };

  // PRE: This object satisfies the CI.
  // POST: OS contains information for each node using in-order
  //         traversal. 
  void printInOrder () const {
    RBNode<T> * currNode = root;
    if (currNode != NULL)
      traverseIn(currNode);
    else
      cout << "This Red Black Tree is empty.\n";
  };

  // PRE: This object satisfies the CI.
  // POST: All dynamic memory allocated for this object (except any
  //         data allocated for T objects) is deallocated.
  ~RBTree<T>() {
    delete root;
  };
};

#endif
