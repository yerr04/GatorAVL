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
    Node* rightChild = node;
    node->right = rightChild->left;
    rightChild->left = node;
    return rightChild;
}

AVLTree::Node* AVLTree::rotateRight(Node* node){
    Node* leftChild = node;
    node->left = leftChild->right;
    leftChild->right = node;
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
    return 1 + max(height(node->left), height(node->right));
}

int AVLTree::updateHeight(Node* node) {
    if (node == nullptr) {
		return 0;
	}
	node->height = 1 + max(height(node->left), height(node->right));
	return node->height;
}

AVLTree::Node* AVLTree::insertHelper(Node* node, string name, int id) {
    if (node == nullptr) {
        return new Node(name, id);
    }
    else {
        if (id > node->id) {
            node->right = insertHelper(node->right, name, id);

            int balance = height(node->left) - height(node->right);
            int balanceNext = 0;
            if (node->right != nullptr) {
                balanceNext = height(node->right->left) - height(node->right->right);
            }
            if (balance == 2) {
                if (balanceNext == 1) {
                    return rotateLeft(node);
                }
                else {
                    return rotateRightLeft(node);
                }
            }
        }
        else {
            node->left = insertHelper(node->left, name, id);
            int balance = height(node->left) - height(node->right);
            int balanceNext = 0;
            if (node->left != nullptr) {
                balanceNext = height(node->left->left) - height(node->left->right);

            }
            if (balance == -2) {
                if (balanceNext == -1) {
                    return rotateRight(node);
                }
                else {
                    return rotateLeftRight(node);
                }
            }
        }
        
        return node;
    }
}

bool AVLTree::verifyAVL(Node* node){
    if (root == nullptr){
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1
    && verifyAVL(root->left) && verifyAVL(root->right)){
        return true;
    }
    return false;
}

bool AVLTree::insertNameID(string name, int id){
    if (searchIDHelper(root, id) != nullptr) {
		return false;
	}
	root = insertHelper(root, name, id);
	return true;
}

AVLTree::Node* AVLTree::searchIDHelper(Node* &node, int id) {
    if (node == nullptr) {
        return nullptr;
    }
    if (id < node->id) {
        return searchIDHelper(node->left, id);
    } else if (id > node->id) {
        return searchIDHelper(node->right, id);
    } else {
        return node;
    }
}

void AVLTree::searchID(int id) {
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
    // do not print out a comma after the last name in the tree

}
// print out a comma separated inorder traversal of the names in the tree
void AVLTree::printInOrder(){
    string list = printInOrderHelper(root);
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
bool AVLTree::removeInOrder(int n){
    vector<Node*> nodes;
    nodes = inOrderTraversal(root, nodes);
    if(n > nodes.size()){
        cout << "unsuccessful" << endl;
        return false;
    }
    else{
        removeID(nodes[n-1]->id);
        cout << "successful" << endl;
        return true;
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

AVLTree::Node* AVLTree::removeHelper(Node* node, int id) {
    if (node == nullptr) {
        return nullptr;
    }
    else {
        if (id == node->id) {
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
        else if (id < node->id) {
            node->left = removeHelper(node->left, id);
        }
        else {
            node->right = removeHelper(node->right, id);
        }
        int balance = height(node->left) - height(node->right);


    }

}

bool AVLTree::removeID(int id){
    root = removeHelper(root, id);
    if(verifyAVL(root)){
        return true;
    }
    else{
        return false;
    }
}

// print out the number of levels in the tree
int AVLTree::printLevelCount() {
    int count = 0;
    if (root == nullptr) {
		return count;
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
                cout << node->name << " ";
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
        return count;
    }
}