#include <iostream>
using namespace std;

int main()
{
    int capacity;
    cout << "enter the capacity of the queue";
    cin >> capacity;
    int *queue = new int[capacity];
    int front = -1, rear = -1;
    for (;;)
    {
        char ch;
        cout << "enter 1 for enqueue operation \n2 for dequeue operation \n3 for isEmpty \n4 for isFUll \n5 for display \n6 for peek \ne for exit";
        cin >> ch;
        switch (ch)
        {
        case '1':
            int num;
            cout << "enter the number to be inserted";
            cin >> num;
            if (rear == capacity - 1)
            {
                cout << "Overflow" << endl;
            }
            else
            {
                if (front == -1 && rear == -1)
                {
                    front = 0;
                    rear = 0;
                }
                else
                {
                    rear++;
                }
                queue[rear] = num;
            }
            break;
        case '2':
            if (front == -1 && front > rear)
            {
                cout << "Underflow" << endl;
            }
            else
            {
                front++;
            }
            break;
        case '3':
            if ((front == -1 && rear == -1) || (front > rear))
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {
                cout << "Not empty" << endl;
            }
            break;
        case '4':
            if ((front == -1 && rear == -1) || (front > rear))
            {
                cout << "Queue is not Full" << endl;
            }
            else
            {
                cout << "Queue is Full" << endl;
            }
            break;
        case '5':
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << endl;
            }
            break;
        case '6':
            cout << queue[front] << endl;
            break;
        case 'e':
        exit(0);
        default:
            cout << "Wrong input given";
        }
    }
}