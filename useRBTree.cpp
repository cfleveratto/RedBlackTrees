#include "RBTree.h"
#include "inputFunctions.h"
#include <fstream>
#include <iostream>

using namespace std;

//PRE:
//POST:
int main (int argc, char * argv[]) {
  if (argc != 2) {
    cout << "Usage: useRBTree <input file>" << endl;
  }
  else {
    // ASSERT: argument 1 is the name of an input file that contains
    //           k > 0 distinct integers. EOF indicates end of input. 
    RBTree<int> tree;
    makeTree (tree, argv[1]);
    // ASSERT: tree is a red-black tree containing the integers from
    // the input file.

    cout << "The tree using pre-order" << endl;
    tree.printPreOrder ();
    // ASSERT: OS contains information for the nodes of the tree
    // traversed using pre-order traversal. Information for each line
    // is printed on one line. The information contains:
    // the data in the node, the height of the node, the balance
    // factor of the node (i.e., height of the left sub-tree - height
    // of the right sub-tree, where the height of an empty tree is 0),
    // and the data in the parent of the node. If the node has no
    // parent, an underscore is printed instead of the data value.

    cout << endl << "The tree using in-order" << endl;
    tree.printInOrder ();
    // ASSERT: OS contains information for the nodes of the tree
    // traversed using in-order traversal. Information for each line
    // is printed on one line. The information contains:
    // the data in the node, the height of the node, the balance
    // factor of the node (i.e., height of the left sub-tree - height
    // of the right sub-tree, where the height of an empty tree is 0),
    // and the data in the parent of the node. If the node has no
    // parent, an underscore is printed instead of the data value.
  }
  return (0);
}

