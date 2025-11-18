#include <iostream>
using namespace std;

class node{
    public:
    node* prev;
    int data;
    node* next;
};
class linkedList{
    node* head;
    node* tail;
    public:
    linkedList()
    {
        head=NULL;
        tail=NULL;
    }
    void insertion(int value)
    {
        if(head==NULL)
        {
            head=new node;
            head->data=value;
            head->next=head->prev=NULL;
            tail=head;
        }   
        else{
            tail->next=new node;
            tail->next->prev=tail;
            tail=tail->next;
            tail->data=value;
            tail->next=NULL;
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
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
        }
        cout<<endl;
    }
    int findSize()
    {
        int flag=0;
        node* temp=head;
        while(temp!=NULL)
        {
            flag++;
            temp=temp->next;
        }
        return flag;
    }
};
int main()
{
    linkedList ob;
    for(;;)
    {
        int choice;
        cout<<"Enter 1 for insertion"<<endl<<"2 for finding size"<<endl<<"3 for display"<<endl<<"4 for exit";
        cin>>choice;
        if(choice==1)
        {
            int val;
            cout<<"enter the value to be inserted";
            cin>>val;
            ob.insertion(val);
            ob.display();
        }
        else if(choice==2)
        {
            cout<<"Size : "<<ob.findSize()<<endl;
        }
        else if(choice==3)
        {
            ob.display();
        }
        else if(choice==4)
        {
            break;
        }
    }
}