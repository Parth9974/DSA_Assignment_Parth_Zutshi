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

class binarySearchTree {
public:
    node* root;

    binarySearchTree() {
        root = NULL;
    }

    node* insert(node* current, int value) {
        if (current == NULL) {
            return new node(value);
        }
        if (value < current->data) {
            current->left = insert(current->left, value);
        } else {
            current->right = insert(current->right, value);
        }
        return current;
    }

    node* searchRecursive(node* current, int key) {
        if (current == NULL) {
            return NULL;
        }
        if (current->data == key) {
            return current;
        }
        if (key < current->data) {
            return searchRecursive(current->left, key);
        } else {
            return searchRecursive(current->right, key);
        }
    }

    node* searchIterative(int key) {
        node* f = root;
        while (f != NULL) {
            if (f->data == key) {
                return f;
            }
            if (key < f->data) {
                f = f->left;
            } else {
                f = f->right;
            }
        }
        return NULL;
    }

    node* maximum(node* current) {
        if (current == NULL) {
            return NULL;
        }
        while (current->right != NULL) {
            current = current->right;
        }
        return current;
    }

    node* minimum(node* current) {
        if (current == NULL) {
            return NULL;
        }
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    node* inorderSuccessor(node* rootNode, node* target) {
        if (target->right != NULL) {
            return minimum(target->right);
        }

        node* successor = NULL;
        node* current = rootNode;

        while (current != NULL) {
            if (target->data < current->data) {
                successor = current;
                current = current->left;
            } else if (target->data > current->data) {
                current = current->right;
            } else {
                break;
            }
        }
        return successor;
    }

    node* inorderPredecessor(node* rootNode, node* target) {
        if (target->left != NULL) {
            return maximum(target->left);
        }

        node* predecessor = NULL;
        node* current = rootNode;

        while (current != NULL) {
            if (target->data > current->data) {
                predecessor = current;
                current = current->right;
            } else if (target->data < current->data) {
                current = current->left;
            } else {
                break;
            }
        }
        return predecessor;
    }
};

int main() {
    binarySearchTree bst;

    bst.root = bst.insert(bst.root, 20);
    bst.root = bst.insert(bst.root, 10);
    bst.root = bst.insert(bst.root, 30);
    bst.root = bst.insert(bst.root, 5);
    bst.root = bst.insert(bst.root, 15);
    bst.root = bst.insert(bst.root, 25);

    node* foundRec = bst.searchRecursive(bst.root, 15);
    if (foundRec != NULL) {
        cout << "Recursive: " << foundRec->data << endl;
    }

    node* foundItr = bst.searchIterative(25);
    if (foundItr != NULL) {
        cout << "Iterative: " << foundItr->data << endl;
    }

    cout << "Maximum: " << bst.maximum(bst.root)->data << endl;
    cout << "Minimum: " << bst.minimum(bst.root)->data << endl;

    node* successor = bst.inorderSuccessor(bst.root, foundRec);
    if (successor != NULL) {
        cout << "Successor of 15: " << successor->data << endl;
    }

    node* predecessor = bst.inorderPredecessor(bst.root, foundRec);
    if (predecessor != NULL) {
        cout << "Predecessor of 15: " << predecessor->data << endl;
    }
}
