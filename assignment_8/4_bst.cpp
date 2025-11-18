#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class binaryTree {
public:
    node* root;
    node* prev;

    binaryTree() {
        root = NULL;
        prev = NULL;
    }

    bool isInorder(node* current) {
        if (current == NULL) {
            return true;
        }

        if (!isInorder(current->left)) {
            return false;
        }

        if (prev != NULL && current->data <= prev->data) {
            return false;
        }

        prev = current;

        if (!isInorder(current->right)) {
            return false;
        }

        return true;
    }

    bool isBST() {
        prev = NULL;
        return isInorder(root);
    }
};

int main() {
    binaryTree bt;

    bt.root = new node(20);
    bt.root->left = new node(10);
    bt.root->right = new node(30);
    bt.root->left->left = new node(5);
    bt.root->left->right = new node(15);

    if (bt.isBST()) {
        cout << "This is a BST" << endl;
    } else {
        cout << "This is NOT a BST" << endl;
    }

    return 0;
}
