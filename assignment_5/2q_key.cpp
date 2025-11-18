#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head;
node *tail;
void display()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "|" << temp->next << "->";
        temp = temp->next;
    }   
    cout<<endl;
}
void count()
{
    int count = 0;
    int key;
    cout << "Enter the value of the key"<<endl;
    cin >> key;
    node* temp1 = head->next;
    node* temp2=head;
    while (temp1 != NULL)
    {
        if(temp1->data == key)
        {
            temp2->next=temp1->next;
            count++;
        }
        else{
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    if(head->data==key)
    {
        count++;
        head=head->next;
    }
    cout << "COUNT:" << count<<endl;
}
int main()
{
    int capacity;
    cout << "enter the capacity of the linked list" << endl;
    cin >> capacity;
    cout << "enter the elements" << endl;
    for (int i = 0; i < capacity; i++)
    {
        if (head == NULL)
        {
            head = new node;
            cin >> head->data;
            head->next = NULL;
            tail = head;
        }
        else
        {
            tail->next = new node;   // new node created at the existiong node's  next
            cin >> tail->next->data; // data taken for the next node
            tail->next->next = NULL; // NULL appointed for the next node's next
            tail = tail->next;       // tail shifted to the last node
        }
    }
    display();
    count();
    display();
}