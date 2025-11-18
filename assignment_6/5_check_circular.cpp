#include <iostream>
#include <random>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node()
    {};
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
class linkedList:public node{
    node* head;
    node* tail;
    public:
    linkedList()
    {
        head=NULL;
        tail=NULL;
    }
    void insert_singly(int val)
    {
        if(head==NULL)
        {
            head=new node(val);
            tail=head;
        }
        else{
            tail->next=new node(val);
            tail=tail->next;
            tail->next=NULL;
        }
    }
    void insert_circular(int val)
    {
        if(head==NULL)
        {
            head=new node(val);
            head->next=head;
            tail=head;
        }
        else{
            tail->next=new node(val);
            tail=tail->next;
            tail->next=head;
        }
    }
    void check(node* &headptr)
    {
        node* fast=headptr;
        node* slow=headptr;
        while(fast!=NULL || fast->next!=slow)//condition was wrong the first time
        {
            if(fast==slow)
            {
                cout<<"It is a circular linked list"<<endl;
                return;
            }
            else{
                fast=fast->next->next;
                slow=slow->next;
            }
        }
        cout<<"Not a Circular Linked list"<<endl;
    }
    void display_singly()
    {
        if(head==NULL)
        {
            cout<<"Empty Linked list"<<endl;
        }
        else{
            node* temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    void display_circular()
    {
        if(head==NULL)
        {
            cout<<"Empty linked list"<<endl;
        }
        else{
            cout<<head->data<<"->";
            node* temp=head->next;
            while(temp!=head)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
        }
    }
    friend class store_head;
};
    class store_head{
        public:
        node* headpointer;
        node* show(linkedList &obj)
        {
            headpointer=obj.head;
            return headpointer;
        }
    };
int main()
{
    linkedList ob;
    random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution dis(0.5);
    for(;;)
    {
        int ch;
        cout<<"Enter your choice"<<endl<<"1 for insertion of the linked list"<<endl<<"2 for check if its is circular"<<endl<<"3 for exit";
        cin>>ch;
        if(ch==1)
        {
            int value;
            cout<<"Enter value to be inserted "<<endl;
            cin>>value;
            bool res=dis(gen);
            if(res==true)
            {
                ob.insert_circular(value);
                ob.display_circular();
            }
            else{
                ob.insert_singly(value);
                ob.display_singly();
            }
        }
        else if(ch==2)
        {
            store_head ob1;
            ob1.headpointer=ob1.show(ob);
            ob.check(ob1.headpointer);
        }
        else if(ch==3)
        {
            exit(0);
        }
        else{
            cout<<"Wrong choice"<<endl;
        }
    }
}