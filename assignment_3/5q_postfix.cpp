#include <iostream>
using namespace std;
class stack{
    int capacity;
    int *st;
    char *arr;
    int top;
    public:
    stack(int c)
    {
        capacity=c;
        arr=new char[c];
        st=new int[c];
        top=-1;
    }
    void input()
    {
        for(int i=0;i<capacity;i++)
        {
            cin>>arr[i];
        }
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
            st[top]=data;
        }
    }
    int pop()
    {
        if(top==-1)
        {
            cout<<"Underflow";
            return -1;
        }
        else{
            return st[top--];
        }
    }
    bool isDigit(char dig)
    {
        if((int)dig>=48 && (int)dig<=57)
        {
            return true;
        }
        else{
            return false;
        }
    }
    void evaluate()
    {
        for(int i=0;i<capacity;i++)
        {
            if(isDigit(arr[i]))
            {
                int val=(int)arr[i]-48;
                push(val);
            }
            else
            {
                int a=pop();
                int b=pop();
                int res=0;
                if(arr[i]=='+')
                {
                    res=b+a;
                }
                else if(arr[i]=='-')
                {
                    res=b-a;
                }
                else if(arr[i]=='/')
                {
                    res=b/a;
                }
                else if(arr[i]=='*')
                {
                    res=b*a;
                }
                push(res);
            }
        }
    }
    void display()
    {
        cout<<"The result of the expression is:"<<st[top]<<endl;
    }
};
int main()
{
    int c;
    cout<<"enter the capacity of the array";
    cin>>c;
    stack ob(c);
    ob.input();
    ob.evaluate();
    ob.display();
}