#include <iostream>
using namespace std;

class stack
{
    int top1;
    int top2;
    int capacity;
    char *st1;
    char *st2;
    public:
    stack(int c)
    {
        top1=-1;
        top2=-1;
        capacity=c;
        st1=new char[c];
        st2=new char[c];
    }
    void input()
    {
        for (int i = 0; i < capacity; i++)
        {
            char ch;
            cin>>ch;
            push1(ch);
        }
    }
    void reverse()
    {
        while(top1>-1)
        {
            push2(st1[top1]);
            pop1();
        }
    }
    void push1(char data)
    {
        if(top1==capacity-1)
        {
            cout<<"Overflow";
            return;
        }
        else{
            top1++;
            st1[top1]=data;
        }
    }
    void push2(char data)
    {
        if(top2==capacity-1)
        {
            cout<<"Overflow";
            return;
        }
        else{
            top2++;
            st2[top2]=data;
        }
    }
    char pop1()
    {
        if(top1==-1)
        {
            cout<<"Underflow";
            return '\0';
        }
        else{
            return st1[top1--];
        }
    }
    char pop2()
    {
        if(top2==-1)
        {
            cout<<"Underflow";
            return '\0';
        }
        else{
            return st2[top2--];
        }
    }
    void display()
    {
        cout << "Reversed string: ";
        for(int i = 0; i <= top2; i++)
        {
            cout << st2[i];
        }
    }
};
int main()
{
    int c;
    cout<<"enter the capacity for the stack";
    cin>>c;
    stack ob(c);
    ob.input();
    ob.reverse();
    ob.display();
}