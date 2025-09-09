#include <iostream>
using namespace std;
//infix to postfix
class stack{
    int capacity;
    int *arr;
    int top;
    stack(int c)
    {
        capacity=c;
        top=-1;
        arr=new int[capacity];
    }
};