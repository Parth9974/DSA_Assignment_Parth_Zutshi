#include <iostream>
// parentheses can be like ( { [] })
// only parentheses in this question no elements
using namespace std;
class stack
{
    int capacity;
    char *arr;
    int top;

public:
    stack(int c)
    {
        capacity = c;
        arr = new char[c];
        top = -1;
    }
    void push(char ele)
    {
        if (top == capacity - 1)
        {
            cout << "Overflow";
        }
        else
        {
            top++;
            arr[top] = ele;
        }
    }
    char pop()
    {
        if (top == -1)
        {
            cout << "Underflow";
            return '\0';
        }
        else
        {
            return arr[top--];
        }
    }
    bool check(char a, char b)
    {
        if (a == '(' && b == ')')
        {
            return true;
        }
        else if (a == '{' && b == '}')
        {
            return true;
        }
        else if (a == '[' && b == ']')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void balanced()
    {
        for (int i = 0; i < capacity; i++)
        {
            char ch1;
            cin >> ch1;
            if (ch1 == '(' || ch1 == '{' || ch1 == '[')
            {
                push(ch1);
            }
            else
            {
                if (top == -1)
                {
                    cout << "Unbalanced parantheses";
                }
                else if (check(arr[top], ch1) == true)
                {
                    pop();
                }
                else
                {
                    cout << "Unbalanced parantheses";
                    exit(0);
                }
            }
        }
        if (top == -1)
        {
            cout << "balanced parentheses" << endl;
        }
        else
        {
            cout << "Unbalanced parantheses" << endl;
        }
    }
};
int main()
{
    int c;
    cout << "enter the capacity of the array";
    cin >> c;
    stack ob(c);
    cout << "enter the parentheses" << endl;
    ob.balanced();
}