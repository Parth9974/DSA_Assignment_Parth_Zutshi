#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;
node *tail = NULL;

int main()
{
    int capacity;
    cout << "Enter the no of elements in the linked list: ";
    cin >> capacity;

    cout << "Enter the elements: ";
    for (int i = 0; i < capacity; i++)
    {
        int value;
        cin >> value;
        if (head == NULL)
        {
            head = new node{value, NULL};
            tail = head;
        }
        else
        {
            tail->next = new node{value, NULL};
            tail = tail->next;
        }
    }
    for (;;)
    {
        int ch;
        cout << "Menu:\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert before/after a value\n";
        cout << "4. Delete from beginning\n5. Delete from end\n6. Delete a specific value\n";
        cout << "7. Search for a node\n8. Display all nodes\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int val;
            cout << "Enter value: ";
            cin >> val;
            node *n = new node{val, head};
            head = n;
            if (tail == NULL)
                tail = n;
            break;
        }
        case 2:
        {
            int val;
            cout << "Enter value: ";
            cin >> val;
            node *n = new node{val, NULL};
            if (head == NULL)
            {
                head = tail = n;
            }
            else
            {
                tail->next = n;
                tail = n;
            }
            break;
        }
        case 3:
        {
            int choice, val, key;
            cout << "Enter 1 for before and 2 for after, then key and value: ";
            cin >> choice >> key >> val;
            node *n = new node{val, NULL};

            if (head == NULL)
            {
                cout << "List empty.\n";
                break;
            }

            if (choice == 1)
            {
                if (head->data == key)
                {
                    n->next = head;
                    head = n;
                    break;
                }
                node *temp = head;
                while (temp->next != NULL)
                {
                    if (temp->next->data == key)
                    {
                        n->next = temp->next;
                        temp->next = n;
                        break;
                    }
                    temp = temp->next;
                }
            }
            else if (choice == 2)
            {
                node *temp = head;
                while (temp != NULL)
                {
                    if (temp->data == key)
                    {
                        n->next = temp->next;
                        temp->next = n;
                        if (temp == tail)
                            tail = n;
                        break;
                    }
                    temp = temp->next;
                }
            }
            break;
        }
        case 4:
        {
            if (head == NULL)
                cout << "List empty.\n";
            else
            {
                node *temp = head;
                head = head->next;
                delete temp;
                if (head == NULL)
                    tail = NULL;
            }
            break;
        }
        case 5:
        {
            if (head == NULL)
                cout << "List empty.\n";
            else if (head->next == NULL)
            {
                delete head;
                head = tail = NULL;
            }
            else
            {
                node *temp = head;
                while (temp->next != tail)
                    temp = temp->next;
                delete tail;
                tail = temp;
                tail->next = NULL;
            }
            break;
        }
        case 6:
        {
            int val;
            cout << "Enter value: ";
            cin >> val;
            if (head == NULL)
                cout << "List empty.\n";
            else if (head->data == val)
            {
                node *temp = head;
                head = head->next;
                delete temp;
                if (head == NULL)
                    tail = NULL;
            }
            else
            {
                node *temp = head;
                while (temp->next != NULL && temp->next->data != val)
                {
                    temp = temp->next;
                }
                if (temp->next != NULL)
                {
                    node *del = temp->next;
                    temp->next = del->next;
                    if (del == tail)
                        tail = temp;
                    delete del;
                }
            }
            break;
        }
        case 7:
        {
            int val, pos = 1;
            cout << "Enter value: ";
            cin >> val;
            node *temp = head;
            while (temp != NULL)
            {
                if (temp->data == val)
                {
                    cout << "Found at position " << pos << "\n";
                    break;
                }
                pos++;
                temp = temp->next;
            }
            if (temp == NULL)
                cout << "Not found.\n";
            break;
        }
        case 8:
        {
            node *temp = head;
            while (temp != NULL)
            {
                cout << "| " << temp->data << " | -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
            break;
        }
        case 9:
            exit(0);
        default:
            cout << "Invalid choice.\n";
        }
    }
}