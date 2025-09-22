#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct LinkedList
{
    node *head;
    node *tail;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(int value)
    {
        if (head == NULL)
        {
            head = new node;
            head->data = value;
            head->next = NULL;
            tail = head;
        }
        else
        {
            tail->next = new node;
            tail = tail->next;
            tail->data = value;
            tail->next = NULL;
        }
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void reverse()
    {
        node *prev = NULL;
        node *curr = head;
        node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main()
{
    LinkedList ob;
    int capacity;
    cout << "Enter the capacity of the linked list: ";
    cin >> capacity;

    cout << "Enter the elements of the linked list:" << endl;
    for (int i = 0; i < capacity; i++)
    {
        int val;
        cin >> val;
        ob.insert(val);
    }
    cout << "Original List: ";
    ob.display();
    ob.reverse();
    cout << "Reversed List: ";
    ob.display();
    return 0;
}
