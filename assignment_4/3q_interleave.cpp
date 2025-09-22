#include <iostream>
using namespace std;

class queue
{
    int *arr1;
    int *arr2;
    int *arr3;
    int front1, front2, front3, rear1, rear2, rear3, capacity;

public:
    queue(int c)
    {
        front1 = front2 = front3 = -1;
        rear1 = rear2 = rear3 = -1;
        capacity = c;
        arr1 = new int[capacity];
        arr2 = new int[capacity / 2];
        arr3 = new int[capacity-(capacity / 2)];
    }
    void input()
    {
        for (int i = 0; i < capacity; i++)
        {
            int ch;
            cin >> ch;
            enqueue(1, ch);
        }
    }
    void working()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (i < capacity / 2)
            {
                int flag = dequeue(1);
                enqueue(2, flag);
            }
            else
            {
                int flag1 = dequeue(1);
                enqueue(3, flag1);
            }
        }
    }
    void evalve()
    {
        front1=rear1=-1;
        for (int i = 0; i < capacity; i++)
        {
            if (i % 2 != 0)
            {
                int flag = dequeue(3);
                enqueue(1, flag);
            }
            else
            {
                int flag1 = dequeue(2);
                enqueue(1, flag1);
            }
        }
        while (true)
        {
            int flag = dequeue(1);
            if (flag == -999)
                break;
            cout << flag << endl;
        }
    }
    void enqueue(int queue_no, int value)
    {
        if (queue_no == 1)
        {
            if (rear1 == capacity - 1)
            {
                cout << "Overflow";
            }
            else
            {
                if (front1 == -1 && rear1 == -1)
                {
                    front1 = 0;
                    rear1 = 0;
                }
                else
                {
                    rear1++;
                }
                arr1[rear1] = value;
            }
        }
        else if (queue_no == 2)
        {
            if (rear2 == capacity / 2 - 1)
            {
                cout << "Overflow";
            }
            else
            {
                if (front2 == -1 && rear2 == -1)
                {
                    front2 = 0;
                    rear2 = 0;
                }
                else
                {
                    rear2++;
                }
                arr2[rear2] = value;
            }
        }
        else if(queue_no == 3)
        {
            if (rear3 == (capacity-(capacity / 2)) - 1)
            {
                cout << "Overflow";
            }
            else
            {
                if (front3 == -1 && rear3 == -1)
                {
                    front3 = 0;
                    rear3 = 0;
                }
                else
                {
                    rear3++;
                }
                arr3[rear3] = value;
            }
        }
    }
    int dequeue(int queue_no)
    {
        if (queue_no == 1)
        {
            if (front1 == -1 || front1 > rear1)
            {
                cout << "Underflow";
                return -999;
            }
            else
            {
                return arr1[front1++];
            }
        }
        else if(queue_no == 2)
        {
            if (front2 == -1 || front2 > rear2)
            {
                cout << "Underflow";
                return -999;
            }
            else
            {
                return arr2[front2++];
            }
        }
        else if(queue_no == 3)
        {
            if (front3 == -1 || front3 > rear3)
            {
                cout << "Underflow";
                return -999;
            }
            else
            {
                return arr3[front3++];
            }
        }
    }
};
int main()
{
    int c;
    cout << "enter the no of elements in the queue";
    cin >> c;
    queue ob(c);
    ob.input();
    ob.working();
    ob.evalve();
    return 0;
}