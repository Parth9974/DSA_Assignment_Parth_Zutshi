#include <iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;

    node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class bst {
public:
    node* root;

    bst() {
        root = NULL;
    }

    void insert(int x) {
        root = add(root, x);
    }

    void remove(int x) {
        root = del(root, x);
    }

    int maxDepth() {
        return depthMax(root);
    }

    int minDepth() {
        return depthMin(root);
    }

private:
    node* add(node* cur, int x) {
        if (cur == NULL) return new node(x);
        if (x < cur->val) cur->left = add(cur->left, x);
        else if (x > cur->val) cur->right = add(cur->right, x);
        return cur;
    }

    node* minNode(node* cur) {
        while (cur->left != NULL) cur = cur->left;
        return cur;
    }

    node* del(node* cur, int x) {
        if (cur == NULL) return NULL;
        if (x < cur->val) cur->left = del(cur->left, x);
        else if (x > cur->val) cur->right = del(cur->right, x);
        else {
            if (cur->left == NULL && cur->right == NULL) {
                delete cur;
                return NULL;
            }
            if (cur->left == NULL) {
                node* t = cur->right;
                delete cur;
                return t;
            }
            if (cur->right == NULL) {
                node* t = cur->left;
                delete cur;
                return t;
            }
            node* t = minNode(cur->right);
            cur->val = t->val;
            cur->right = del(cur->right, t->val);
        }
        return cur;
    }

    int depthMax(node* cur) {
        if (cur == NULL) return 0;
        int a = depthMax(cur->left);
        int b = depthMax(cur->right);
        return (a > b ? a : b) + 1;
    }

    int depthMin(node* cur) {
        if (cur == NULL) return 0;
        if (cur->left == NULL && cur->right == NULL) return 1;
        if (cur->left == NULL) return depthMin(cur->right) + 1;
        if (cur->right == NULL) return depthMin(cur->left) + 1;
        int a = depthMin(cur->left);
        int b = depthMin(cur->right);
        return (a < b ? a : b) + 1;
    }
};

int main() {
    bst t;
    t.insert(20);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(15);
    t.remove(10);

    cout << t.maxDepth() << endl;
    cout << t.minDepth() << endl;
}
