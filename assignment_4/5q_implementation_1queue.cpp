#include <iostream>
using namespace std;

class Queue {
public:
    int *arr;
    int front, rear, capacity;
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }
    void enqueue(int x) {
        if (rear == capacity - 1) {
            cout << "Queue overflow" << endl;
            return;
        }
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
    }
    
    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        int temp = arr[front];
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return temp;
    }
    
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    
    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

class StackUsingOneQueue {
public:
    Queue q;
    
    StackUsingOneQueue(int cap) : q(cap) {}
    
    void push(int x) {
        int s = q.size();
        q.enqueue(x);
        for (int i = 0; i < s; i++) {
            q.enqueue(q.dequeue());
        }
    }
    
    int pop() {
        if (q.isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return q.dequeue();
    }
    
    int top() {
        if (q.isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.peek();
    }
    
    bool isEmpty() {
        return q.isEmpty();
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity: ";
    cin >> capacity;
    
    StackUsingOneQueue stack(capacity);
    
    for (;;) {
        char ch;
        cout << "\n1 for push\n2 for pop\n3 for top\n4 for isEmpty\ne for exit\n";
        cin >> ch;
        switch (ch) {
        case '1':
            int num;
            cout << "Enter number to push: ";
            cin >> num;
            stack.push(num);
            break;
        case '2':
            cout << "Popped: " << stack.pop() << endl;
            break;
        case '3':
            cout << "Top: " << stack.top() << endl;
            break;
        case '4':
            if (stack.isEmpty()) {
                cout << "Stack is empty" << endl;
            } else {
                cout << "Stack is not empty" << endl;
            }
            break;
        case 'e':
            exit(0);
        default:
            cout << "Wrong input" << endl;
        }
    }
    
    return 0;
}