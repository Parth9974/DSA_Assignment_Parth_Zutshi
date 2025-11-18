#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;
};
class LinkedList
{
    node *head;
    node *tail;
    int capacity;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(int num)
    {
        capacity = num;
        if (head == NULL)
        {
            head = new node;
            head->prev = NULL;
            head->next = NULL;
            head->data = num;
            tail = head;
        }
        else
        {
            tail->next = new node;
            tail->next->prev = tail;
            tail = tail->next;
            tail->data = num;
            tail->next = NULL;
        }
    }
    void insertion(int num, int val)
    {
        node *newNode = new node;
        newNode->data = val;
        if (head == NULL)
        {
            cout << "The linked list is empty" << endl;
            head = tail = newNode;
            newNode->next = newNode->prev = NULL;
            return;
        }
        if (num == 0)
    {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        cout << "Inserted " << val << " at the beginning." << endl;
        return;
    }
        node *temp = head;
        int i = 0;
        while (i < num-1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }
    void delete_node(int num)
    {
        node *temp = head;
        if (head == NULL) // checking if the linked list contains element or not
        {
            cout << "The linked list is empty" << endl;
        }
        else if (tail->data == num) // checking if the node to be deleted is the last node
        {
            node *temp = tail;
            tail = tail->prev;
            tail->next->prev = NULL;
            tail->next = NULL;
            delete temp;
        }
        else if (head->data == num)
        {
            if (head->next == NULL)
            {
                head = NULL;
            }
            else
            {
                node *temp = head;
                head = head->next;
                temp->next = NULL;
                head->prev = NULL;
                delete temp;
            }
        }
        else
        {
            while (temp->next->data != num && temp->next != NULL)
            {
                temp = temp->next;
            }
            if (temp->next == NULL)
            {
                cout << "Node not found" << endl;
            }
            else
            {
                temp->next->next->prev = temp;
                temp = temp->next;
                temp->prev->next = temp->next;
                delete temp;
            }
        }
    }
    void search(int num)
    {
        node *temp = head;
        int flag = 0;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == num)
            {
                cout << "Found value at index : " << idx << endl;
                flag = 1;
                break;
            }
            else
            {
                idx++;
                temp = temp->next;
            }
        }
        if (flag == 0)
        {
            cout << "Value not found in the linked list" << endl;
        }
    }
    void display()
    {
        node *temp = head;
        if (head == NULL)
        {
            cout << "Linked List is empty" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
        }
        cout << endl;
    }
};
int main()
{
    LinkedList ob;
    int capacity;
    cout << "enter the capacity of the linked list";
    cin >> capacity;
    for (int i = 0; i < capacity; i++)
    {
        int val;
        cin >> val;
        ob.insert(val);
    }
    for (;;)
    {
        int choice;
        cout << "Enter which operation is to be performed" << endl
             << "1 for insertion" << endl
             << "2 for deletion" << endl
             << "3 for Search for a node" << endl
             << "4 for Display" << endl
             << "5 for exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            int idx, value;
            cout << "enter at what index is the value to be inserted and the value" << endl;
            cin >> idx >> value;
            ob.insertion(idx, value);
            ob.display();
        }
        else if (choice == 2)
        {
            int value1;
            cout << "enter the value to be deleted" << endl;
            cin >> value1;
            ob.delete_node(value1);
            ob.display();
        }
        else if (choice == 3)
        {
            int s;
            cout << "enter the value to be searched" << endl;
            cin >> s;
            ob.search(s);
        }
        else if (choice == 4)
        {
            ob.display();
        }
        else
        {
            break;
        }
    }
}