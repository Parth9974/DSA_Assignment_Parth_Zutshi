#include <iostream>
using namespace std;

class queue{
    int capacity;
    string str;
    int front;
    int rear;
    public:
    queue(string s)
    {
        str=s;
        capacity=str.length();
        front=rear=-1;
    }
    void evalve()
    {
        front=0;
        rear=capacity-1;
        for(int i=0;i<capacity;i++)
        {
             char flag=dequeue();
            char flag1=dequeue();
            if(flag!=flag1)
            {
                cout<<flag1<<" is the first non-repeating character";
                break;
            }
        }
    }
    char dequeue()
    {
        if(front==-1 || front>rear)
        {
            cout<<"Underflow"<<endl;
        }
        else{
            return(str[front++]);
        }
    }
};
int main()
{
    string s;
    cout<<"enter the string";
    cin>>s;
    queue ob(s);
    ob.evalve();
}