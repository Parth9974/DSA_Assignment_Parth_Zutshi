#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
node* head;
node* tail;
void display()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"|"<<temp->next<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
void middle(int capacity)
{
    int count=capacity/2+1;
    node* temp=head;
    int flag=1;
    while(flag<=count)
    {
        if(flag==count)
        {
            cout<<temp->data;
            flag++;
        }
        else{
            flag++;
            temp=temp->next;
        }
    }
}
int main()
{
    int capacity;
    cout<<"Enter the no of elements of the linked list"<<endl;
    cin>>capacity;
    cout<<"Enter the elements of the linked list"<<endl;
    for(int i=0;i<capacity;i++)
    {
        if(head==NULL)
        {
            head=new node;
            cin>>head->data;
            head->next=NULL;
            tail=head;
        }
        else{
            tail->next=new node;
            cin>>tail->next->data;
            tail->next->next=NULL;
            tail=tail->next;
        }
    }
    display();
    middle(capacity);
}