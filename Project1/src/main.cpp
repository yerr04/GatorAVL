#include <iostream>
#include <sstream>
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
	while (commandNum > 0) {
		cin >> command;  // Moved inside the loop to read a new command each iteration
		if (command == "insert") {
			cin.ignore();  // Ignore any whitespace following the command
			string input;
			getline(cin, input);  // Read the rest of the line
			stringstream ss(input);
			string name, id;
			getline(ss, name, '"');  // Discard the first quote
			getline(ss, name, '"');  // Get the name
			ss >> id;  // Get the id
			if (id.length() != 8) {  // Check if id is exactly 8 digits
				cout << "unsuccessful" << endl;
			}
			else {
				tree.insertNameID(name, id);
			}
		}
		else if (command == "remove") {
			string id;
			cin >> id;
			if (id.length() != 8) {  // Check if id is exactly 8 digits
				cout << "unsuccessful" << endl;
			}
			else {
				tree.removeID(id);
			}
		}
		else if (command == "search") {
			cin.ignore();  // Ignore any whitespace following the command
			string input;
			getline(cin, input);  // Read the rest of the line
			if (input[0] == '"') {
				// It's a name search
				string name = input.substr(1, input.find_last_of('"') - 1);  // Extract name
				tree.searchName(name);
			}
			else {
				// It's an ID search
				string id = input;
				tree.searchID(id);
			}
		}
		else if (command == "printInorder") {
			tree.printInOrder();
		}
		else if (command == "printPreorder") {
			tree.printPreOrder();
		}
		else if (command == "printPostorder") {
			tree.printPostOrder();
		}
		else if (command == "printLevelCount") {
			tree.printLevelCount();
		}
		else if (command == "removeInorder") {
			int n;
			cin >> n;
			tree.removeInOrder(n);
		}
		else {
			cout << "unsuccessful" << endl;
		}
		commandNum--;
	}
	return 0;
}

// TODO:
// input parsing
// unit tests