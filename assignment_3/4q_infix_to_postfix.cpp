#include <iostream>
#include <string>
using namespace std;

class Stack
{
    int capacity;
    char *arr;
    int top;
public:
    Stack(int c)
    {
        capacity = c;
        arr = new char[c];
        top = -1;
    }
    void push(char data)
    {
        if (top == capacity - 1)
            return;
        arr[++top] = data;
    }
    void pop()
    {
        if (top == -1)
            return;
        top--;
    }
    char peek()
    {
        if (top == -1)
            return -1;
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    Stack st(s.length());
    string result;
    for (int i = 0; i < (int)s.length(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.peek() != '(')
            {
                result += st.peek();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && precedence(st.peek()) >= precedence(c))
            {
                result += st.peek();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        result += st.peek();
        st.pop();
    }
    return result;
}

int main()
{
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;
    cout << "Postfix: " << infixToPostfix(exp) << endl;
    return 0;
}