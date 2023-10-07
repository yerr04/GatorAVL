#include <iostream>
#include "AVLTree.h"


/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){
	AVLTree tree;

	// number of commands to be executed
	int commandNum = 0;
	cin >> commandNum;

	// execute commands
	string command;
	cin >> command;
	while (commandNum > 0) {
		if (command == "insert") {
			string name, id = "";
			// get rid of the the quotes
			getline(cin, name, '"'); 
			getline(cin, name, '"'); 
			getline(cin, id);
			// remove leading and trailing whitespace
			id.erase(0, id.find_first_not_of(" \n\r\t"));
			id.erase(id.find_last_not_of(" \n\r\t") + 1);
			tree.insertNameID(name, id);
		}
		else if (command == "remove") {
			string id;
			cin >> id;
			tree.removeID(id);
		}
		else if (command == "search") {
			string id;
			cin >> id;
			tree.searchID(id);
		}
		else if (command == "printInOrder") {
			tree.printInOrder();
		}
		else if (command == "printPreOrder") {
			tree.printPreOrder();
		}
		else if (command == "printPostOrder") {
			tree.printPostOrder();
		}
		else if (command == "printLevelCount") {
			tree.printLevelCount();
		}
		else if (command == "removeInOrder") {
			int n;
			cin >> n;
			tree.removeInOrder(n);
		}
		else {
			cout << "Invalid command" << endl;
		}
		commandNum--;
		cin >> command;
	}
	return 0;
}

// TODO:
// input parsing
// unit tests