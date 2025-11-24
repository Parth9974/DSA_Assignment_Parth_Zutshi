#include <iostream>
using namespace std;

void sel(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int p = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[p]) p = j;
        }
        int t = a[i];
        a[i] = a[p];
        a[p] = t;
    }
}

void ins(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i], j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void bub(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void mergeArr(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[50], R[50];

    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        mergeArr(a, l, m, r);
    }
}

int part(int a[], int l, int r) {
    int piv = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] < piv) {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[r];
    a[r] = t;
    return i + 1;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int p = part(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int a[100], b[100];
    for (int i = 0; i < n; i++) cin >> a[i];

    int ch;

    do {
        for (int i = 0; i < n; i++) b[i] = a[i];

        cout << "1 Selection Sort\n";
        cout << "2 Insertion Sort\n";
        cout << "3 Bubble Sort\n";
        cout << "4 Merge Sort\n";
        cout << "5 Quick Sort\n";
        cout << "6 Exit\n";
        cin >> ch;

        if (ch == 1) {
            sel(b, n);
            print(b, n);
        }
        if (ch == 2) {
            ins(b, n);
            print(b, n);
        }
        if (ch == 3) {
            bub(b, n);
            print(b, n);
        }
        if (ch == 4) {
            mergeSort(b, 0, n - 1);
            print(b, n);
        }
        if (ch == 5) {
            quickSort(b, 0, n - 1);
            print(b, n);
        }

    } while (ch != 6);
}
