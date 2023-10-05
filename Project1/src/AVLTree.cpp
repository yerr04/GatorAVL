#pragma once
#include "AVLTree.h"

AVLTree::AVLTree(){
    root = nullptr;
}

void AVLTree::deleteTree(Node* node){
    if(node == nullptr){
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

AVLTree::~AVLTree(){
    deleteTree(root);
}

AVLTree::Node* AVLTree::rotateLeft(Node* node){
    Node* rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;

    // update heights
    updateHeight(node);
    updateHeight(rightChild);
    return rightChild;
}

AVLTree::Node* AVLTree::rotateRight(Node* node){
    Node* leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;

    // update heights
    updateHeight(node);
    updateHeight(leftChild);
    return leftChild;
}

AVLTree::Node* AVLTree::rotateLeftRight(Node* node){
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

AVLTree::Node* AVLTree::rotateRightLeft(Node* node){
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

int AVLTree::height(Node* node){
    if(node == nullptr){
        return 0;
    }
    return 1 + max(node->left ? node->left->height : 0, node->right ? node->right->height : 0);
}

int AVLTree::updateHeight(Node* node) {
    if (node == nullptr) {
		return 0;
	}
	node->height = 1 + max(height(node->left), height(node->right));
	return node->height;
}

AVLTree::Node* AVLTree::insertHelper(Node* node, string name, string id) {
    if (node == nullptr) {
        return new Node(name, id);
    }
    else {
        if (stoi(id) > stoi(node->id)) {
            node->right = insertHelper(node->right, name, id);
        }
        else {
            node->left = insertHelper(node->left, name, id);
        }

        root->height = updateHeight(node);

        // check if tree is balanced
        int balance = height(node->left) - height(node->right);
		if (balance > 1) {
			if (height(node->left->left) >= height(node->left->right)) {
				node = rotateRight(node);
			}
			else {
				node = rotateLeftRight(node);
			}
		}
		else if (balance < -1) {
			if (height(node->right->right) >= height(node->right->left)) {
				node = rotateLeft(node);
			}
			else {
				node = rotateRightLeft(node);
			}
		}
        
        return node;
    }
}


void AVLTree::insertNameID(string name, string id){
    if (searchIDHelper(root, id) != nullptr) {
        cout << "unsuccessful" << endl;
	}
	root = insertHelper(root, name, id);
    cout << "successful" << endl;
}

AVLTree::Node* AVLTree::searchIDHelper(Node* &node, string id) {
    if (node == nullptr) {
        return nullptr;
    }
    if (stoi(id) < stoi(node->id)) {
        return searchIDHelper(node->left, id);
    } else if (stoi(id) > stoi(node->id)) {
        return searchIDHelper(node->right, id);
    } else {
        return node;
    }
}

void AVLTree::searchID(string id) {
    Node* node = searchIDHelper(root, id);
    if (node == nullptr) {
        cout << "unsuccessful" << endl;
    } else {
        cout << node->name << endl;
    }
}

AVLTree::Node* AVLTree::searchNameHelper(Node* node, string name){
    if(node == nullptr){
        return nullptr;
    }
    if(node->name == name){
        return node;
    }
    else{
        Node* left = searchNameHelper(node->left, name);
        Node* right = searchNameHelper(node->right, name);
        if(left != nullptr){
            return left;
        }
        else if(right != nullptr){
            return right;
        }
        else{
            return nullptr;
        }
    }
}

// search for the student with the specified name
void AVLTree::searchName(string name){
    Node* node = searchNameHelper(root, name);
    if(node == nullptr){
        cout << "unsuccessful" << endl;
    }
    else{
        cout << node->id << endl;
    }
}

string AVLTree::printInOrderHelper(Node* node){
    if(node == nullptr){
        return "";
    }
    string str = printInOrderHelper(node->left) + node->name + ", " + printInOrderHelper(node->right);
    return str;
}
// print out a comma separated inorder traversal of the names in the tree
void AVLTree::printInOrder(){
    string list = printInOrderHelper(root);
    // remove the last comma and space
	list = list.substr(0, list.length()-2);
    cout << list << endl;
}

string AVLTree::printPreOrderHelper(Node* node){
    if(node == nullptr){
        return "";
    }
    return node->name + ", " + printPreOrderHelper(node->left) + printPreOrderHelper(node->right);
}

// print out a comma separated preorder traversal of the names in the tree
void AVLTree::printPreOrder(){
    string list = printPreOrderHelper(root);
	list = list.substr(0, list.length()-2);
	cout << list << endl;
}

string AVLTree::printPostOrderHelper(Node* node){
    if(node == nullptr){
        return "";
    }
    return printPostOrderHelper(node->left) + printPostOrderHelper(node->right) + node->name + ", ";
}

// print out a comma separated postorder traversal of the names in the tree
void AVLTree::printPostOrder(){
    string list = printPostOrderHelper(root);
	list = list.substr(0, list.length()-2);
	cout << list << endl;
}

// remove the nth gatorid from the inorder traveral of the tree
// if successful, print successful
// if not successful, print unsuccessful
// balance the tree if necessary
void AVLTree::removeInOrder(int n){
    vector<Node*> nodes;
    nodes = inOrderTraversal(root, nodes);
    if(n > nodes.size()){
        cout << "unsuccessful" << endl;
    }
    else{
        removeID(nodes[n-1]->id);
        cout << "successful" << endl;
    }
}
vector<AVLTree::Node*> AVLTree::inOrderTraversal(Node* node, vector<Node*> &nodes){
    if(node == nullptr){
        return nodes;
    }
    inOrderTraversal(node->left, nodes);
    nodes.push_back(node);
    inOrderTraversal(node->right, nodes);
    return nodes;
}

AVLTree::Node* AVLTree::removeHelper(Node* node, string id) {
    if (node == nullptr) {
        return nullptr;
    }
    else {
        if (stoi(id) == stoi(node->id)) {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->name = temp->name;
                node->id = temp->id;
                node->right = removeHelper(node->right, temp->id);
                return node;
            }
        }
        else if (stoi(id) < stoi(node->id)) {
            node->left = removeHelper(node->left, id);
        }
        else {
            node->right = removeHelper(node->right, id);
        }
        int balance = height(node->left) - height(node->right);
        if (balance > 1) {
            if (height(node->left->left) >= height(node->left->right)) {
                node = rotateRight(node);
            }
            else {
                node = rotateLeftRight(node);
            }
        }
        else if (balance < -1) {
            if (height(node->right->right) >= height(node->right->left)) {
                node = rotateLeft(node);
            }
            else {
                node = rotateRightLeft(node);
            }
        }
        updateHeight(node);
        return node;
    }

}

void AVLTree::removeID(string id) {
    if (searchIDHelper(root, id) == nullptr) {
        cout << "unsuccessful" << endl;
    }
    root = removeHelper(root, id);
    cout << "successful" << endl;
}

// print out the number of levels in the tree
void AVLTree::printLevelCount() {
    int count = 0;
    if (root == nullptr) {
		cout << 0 << endl;
	}
    else {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                Node* node = q.front();
                q.pop();
                // print out all the names in the current level on a new line
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                size--;
            }
            count++;
        }
        cout << count << endl;
    }
}