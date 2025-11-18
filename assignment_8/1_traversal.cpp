#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class binaryTree
{
public:
    node *root;

    binaryTree()
    {
        root = NULL;
    }

    void preorder(node *temp)
    {
        if (temp == NULL)
            return;
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    void inorder(node *temp)
    {
        if (temp == NULL)
            return;
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    void postorder(node *temp)
    {
        if (temp == NULL)
            return;
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
};

int main()
{
    binaryTree ob;
    ob.root = new node(10);
    ob.root->left = new node(5);
    ob.root->right = new node(15);
    ob.root->left->left = new node(2);
    ob.root->left->right = new node(7);
    ob.root->right->left = new node(12);

    cout << "Preorder: ";
    ob.preorder(ob.root);
    cout << endl;
    cout << "Inorder: ";
    ob.inorder(ob.root);
    cout << endl;
    cout << "Postorder: ";
    ob.postorder(ob.root);
    cout << endl;
}
