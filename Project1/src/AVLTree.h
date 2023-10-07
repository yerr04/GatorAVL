#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class AVLTree{
    private:
        struct Node{
            string name;
            string id;
            int height = 1;
            Node* left;
            Node* right;
            Node(string name, string id){
                this->name = name;
                this->id = id;
                left = nullptr;
                right = nullptr;
            }
        };
        Node* root;
        int height(Node* node);
        int updateHeight(Node* node);
        Node* rotateLeft(Node* node);
        Node* rotateRight(Node* node);
        Node* rotateLeftRight(Node* node);
        Node* rotateRightLeft(Node* node);
        Node* insertHelper(Node* node, string name, string id);
        Node* removeHelper(Node* node, string id);
        Node* searchIDHelper(Node* &node, string id);
        Node* searchNameHelper(Node* node, string name);
        string printInOrderHelper(Node* node);
        string printPreOrderHelper(Node* node);
        string printPostOrderHelper(Node* node);
        vector<Node*> inOrderTraversal(Node* node, vector<Node*> &nodes);
        void balanceTree(Node* node);

    public:
        AVLTree();
        ~AVLTree();
        void deleteTree(Node* node);
        void insertNameID(string name, string id);
        void removeID(string id);
        void searchID(string id);
        void searchName(string name);
        void printInOrder();
        void printPreOrder();
        void printPostOrder();
        void printLevelCount();
        void removeInOrder(int n);
};