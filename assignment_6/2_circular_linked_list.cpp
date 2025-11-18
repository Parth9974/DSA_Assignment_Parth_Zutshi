#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};
class linkedList{
    int capacity;
    node* head;
    node* tail;
    public:
    linkedList()
    {
        head=NULL;
        tail=NULL;
    }
    void insert(int num)
    {
        if(head==NULL)
        {
            head=new node;
            head->data=num;
            head->next=head;
            tail=head;
        }
        
        else{
            tail->next=new node;
            tail=tail->next;
            tail->data=num;
            tail->next=head;
        }
    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"Linked List is empty"<<endl;
        }
        else{
            node* temp=head;
            cout<<head->data<<"->";
            cout<<temp->next->data<<"->";
            temp=temp->next->next;
            while(temp!=head->next)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
        }
        cout<<endl;
    }
};
int main()
{
    linkedList ob;
    int capacity;
    cout<<"enter the capacity of the linked list";
    cin>>capacity;
    for(int i=0;i<capacity;i++)
    {
        int val;
        cin>>val;
        ob.insert(val);
    }
    ob.display();
}