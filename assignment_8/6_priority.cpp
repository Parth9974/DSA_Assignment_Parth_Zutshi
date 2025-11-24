#include <iostream>
using namespace std;

class pq {
public:
    int arr[100];
    int sz;

    pq() {
        sz = 0;
    }

    void push(int x) {
        arr[sz] = x;
        int i = sz;
        sz++;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (arr[p] >= arr[i]) break;
            int t = arr[p];
            arr[p] = arr[i];
            arr[i] = t;
            i = p;
        }
    }

    void pop() {
        if (sz == 0) return;
        arr[0] = arr[sz - 1];
        sz--;
        int i = 0;
        while (true) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            int big = i;

            if (l < sz && arr[l] > arr[big]) big = l;
            if (r < sz && arr[r] > arr[big]) big = r;

            if (big == i) break;

            int t = arr[i];
            arr[i] = arr[big];
            arr[big] = t;

            i = big;
        }
    }

    int top() {
        if (sz == 0) return -1;
        return arr[0];
    }
};

int main() {
    pq q;
    q.push(30);
    q.push(10);
    q.push(50);
    q.push(20);
    q.push(40);

    while (q.sz > 0) {
        cout << q.top() << " ";
        q.pop();
    }
}
