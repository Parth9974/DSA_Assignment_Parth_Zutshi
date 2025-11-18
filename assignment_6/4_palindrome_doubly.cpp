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
    void insert(int num)//general insertion at end
    {
        if(head==NULL)
        {
            head=new node;
            head->data=num;
            head->prev=head->next=NULL;
            tail=head;
        }
        else{
            tail->next=new node;
            tail->next->prev=tail;
            tail=tail->next;
            tail->next=NULL;
            tail->data=num;
        }
    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"Empty linked list"<<endl;
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
    void checkPalindrome()
    {
        node* first=head;
        node* last=tail;
        bool d=true;
        while(first!=tail)
        {
            if(first->data==last->data)
            {
                first=first->next;
                last=last->prev;
            }
            else{
                d=false;
                break;
            }
        }
        if(d==true)
        {
            if(first->data==tail->data)
            {
                cout<<"Palindrome"<<endl;
            }
            else{
                cout<<"Not palindrome"<<endl;
            }
        }
        else{
            cout<<"Not palindrome"<<endl;
        }
    }
};
int main()
{
    linkedList ob;
    for(;;)
    {
        int choice;
        cout<<"Enter 1 for insertion"<<endl<<"2 for checking palindrome"<<endl<<"3 for display"<<endl<<"4 for exit "<<endl;
        cin>>choice;

        if(choice==1)
        {
            int value;
            cout<<"Enter the value to be inserted"<<endl;
            cin>>value;
            ob.insert(value);
            ob.display();
        }
        else if(choice==2)
        {
            ob.checkPalindrome();
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