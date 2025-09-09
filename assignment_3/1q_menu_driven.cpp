#include <iostream>
using namespace std;
class stack
{
    int capacity;
    int *arr;
    int top;
    public:
    stack(int c)
    {
        this->capacity=c;
        arr=new int[c];
        top=-1;
    }
    void push(int data)
    {
        if(top==capacity-1)
        {
            cout<<"Overflow";
            return;
        }
        else{
            top++;
            arr[top]=data;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Underflow";
            return;
        }
        else{
            top--;
        }
    }
    int peek()
    {
        if(top==-1)
        {
            cout<<"Underflow";
            return -1;
        }
        else{
        return arr[top];
        }
    }
    int size()
    {
        return top+1;
    }
    bool isFull()
    {
        return (top==capacity-1);
    }
    bool isEmpty()
    {
        return (top==-1);
    }
    void display()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<<",";
        }
    }
};
int main()
{
    stack ob(5);
    ob.push(2);
    ob.push(6);
    ob.push(1);
    cout<<ob.peek()<<endl;
    ob.display();
    ob.push(4);
    ob.push(8);
    ob.pop();
    cout<<boolalpha<<ob.isEmpty()<<endl;
    cout<<ob.peek()<<endl;
    ob.display();
}