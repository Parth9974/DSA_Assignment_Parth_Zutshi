#include <iostream>
using namespace std;

void heapUpMax(int arr[], int n, int i) {
    int big = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[big]) big = l;
    if (r < n && arr[r] > arr[big]) big = r;

    if (big != i) {
        int t = arr[i];
        arr[i] = arr[big];
        arr[big] = t;
        heapUpMax(arr, n, big);
    }
}

void heapSortInc(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapUpMax(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapUpMax(arr, i, 0);
    }
}

void heapUpMin(int arr[], int n, int i) {
    int small = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] < arr[small]) small = l;
    if (r < n && arr[r] < arr[small]) small = r;

    if (small != i) {
        int t = arr[i];
        arr[i] = arr[small];
        arr[small] = t;
        heapUpMin(arr, n, small);
    }
}

void heapSortDec(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapUpMin(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapUpMin(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    heapSortInc(a, n);
    heapSortDec(b, n);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
}
