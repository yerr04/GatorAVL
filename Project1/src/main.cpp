#include <iostream>
#include "AVLTree.h"


/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){
	AVLTree tree;

	cout << "Inserting names and IDs into the AVL tree..." << endl;
	tree.insertNameID("Rohan", "1");
	tree.printInOrder();
	tree.insertNameID("Michael", "2");
	tree.printInOrder();
	tree.insertNameID("Kaylee", "3");
	tree.insertNameID("Dylan", "4");
	tree.insertNameID("Paul", "5");
	// print in order test
	tree.printInOrder();

	// print level count test
	tree.printLevelCount();

	// remove test
	tree.removeID("3");

	// print in order test
	tree.printInOrder();
	// print pre order test
	tree.printPreOrder();
	// print post order test
	tree.printPostOrder();

	// search test
	tree.searchID("1");
	tree.searchName("Michael");
	
	// remove in order test
	tree.removeInOrder(3);
	tree.printInOrder();
	return 0;
}

// TODO:
// input parsing
// unit tests