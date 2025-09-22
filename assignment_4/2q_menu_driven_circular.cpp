#include <iostream>
using namespace std;

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
            if (front == (rear + 1) % capacity)
            {
                cout << "Overflow" << endl;
            }
            else
            {
                rear = (rear + 1) % capacity;
                queue[rear] = num;
                if (front == -1)
                {
                    front = 0;
                }
            }
            break;
        case '2':
            if (front == -1)
            {
                cout << "Underflow" << endl;
            }
            else
            {
                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                {
                    front = (front + 1) % capacity;
                }
            }
            break;
        case '3':
            if ((front == -1))
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {
                cout << "Not empty" << endl;
            }
            break;
        case '4':
            if ((rear + 1) % capacity == front) // if we add one more element then we will land on the front element itself
            {
                cout << "Queue is Full" << endl;
            }
            else
            {
                cout << "Queue is not Full" << endl;
            }
            break;
        case '5':
            if (front == -1)
            {
                cout << "Queue is Empty";
            }
            else
            {
                int i=front;
                while (true)
                {
                    cout << queue[i] << " ";
                    if (i == rear)
                        break;
                    i = (i + 1) % capacity;
                }
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