#include <iostream>
using namespace std;

class node{
    public:
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
    void insertion(int num)
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
            temp=temp->next;
            while(temp!=head)
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
        if(head==NULL)
        {
            cout<<"Empty linked list"<<endl;
        }
        else{
            flag=1;
            temp=temp->next;
            while(temp!=head)
            {
                flag++;
                temp=temp->next;
            }
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
        cout<<"Enter 1 for insertion"<<endl<<"2 for finding size"<<endl<<"3 for display"<<endl<<"4 for exit"<<endl;

        cin>>choice;
        if(choice==1)
        {
            int val;
            cout<<"enter the value to be inserted"<<endl;
            cin>>val;
            ob.insertion(val);
            ob.display();
        }
        else if(choice==2)
        {
            cout<<ob.findSize();
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