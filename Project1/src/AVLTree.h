#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AVLTree{
    private:
        struct Node{
            string name;
            int id;
            int height = 1;
            Node* left;
            Node* right;
            Node(string name, int id){
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
        Node* insertHelper(Node* node, string name, int id);
        Node* removeHelper(Node* node, int id);
        Node* searchIDHelper(Node* &node, int id);
        Node* searchNameHelper(Node* node, string name);
        string printInOrderHelper(Node* node);
        string printPreOrderHelper(Node* node);
        string printPostOrderHelper(Node* node);
        bool verifyAVL(Node* node);
        vector<Node*> inOrderTraversal(Node* node, vector<Node*> &nodes);

    public:
        AVLTree();
        ~AVLTree();
        void deleteTree(Node* node);
        bool insertNameID(string name, int id);
        bool removeID(int id);
        void searchID(int id);
        void searchName(string name);
        void printInOrder();
        void printPreOrder();
        void printPostOrder();
        void printLevelCount();
        bool removeInOrder(int n);
};