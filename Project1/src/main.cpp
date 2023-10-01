#include <iostream>
#include "AVLTree.h"


/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){
	AVLTree tree;

	cout << "Inserting names and IDs into the AVL tree..." << endl;
	if (tree.insertNameID("Rohan", 12345678)) {
		cout << "successful" << endl;
	}
	else {
		cout << "unsuccessful" << endl;
	}
	if (tree.insertNameID("Michael", 98596699)) {
		cout << "successful" << endl;
	}
	else {
		cout << "unsuccessful" << endl;
	}
	if (tree.insertNameID("Kaylee", 56586561)){
		cout << "successful" << endl;
		}
	else {
			cout << "unsuccessful" << endl;
		}

	// print in order test
	tree.printInOrder();
	// search name test
	tree.searchName("Kaylee");
	// search ID test
	tree.searchID(12345678);

	// remove ID test
	if (tree.removeID(12345678)) {
		cout << "successful" << endl;
	}
	else {
		cout << "unsuccessful" << endl;
	}
	// print in order test
	tree.printInOrder();

	return 0;
}

