#include <iostream>
#include "AVLTree.h"


/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){
	AVLTree tree;

	cout << "Inserting names and IDs into the AVL tree..." << endl;
	if (tree.insertNameID("Rohan", "1")) {
		cout << "successful" << endl;
	}
	else {
		cout << "unsuccessful" << endl;
	}
	tree.printInOrder();
	if (tree.insertNameID("Michael", "2")) {
		cout << "successful" << endl;
	}
	else {
		cout << "unsuccessful" << endl;
	}
	tree.printInOrder();
	if (tree.insertNameID("Kaylee", "3")) {
		cout << "successful" << endl;
		}
	else {
			cout << "unsuccessful" << endl;
		}

	// print in order test
	tree.printInOrder();

	// print level count test
	cout << tree.printLevelCount() << endl;

	return 0;
}

