#include <iostream>
using namespace std;

int findSet(int p[], int x) {
    while (p[x] != x) x = p[x];
    return x;
}

int main() {
    int n, e;
    cin >> n >> e;

    int u[50], v[50], w[50];
    for (int i = 0; i < e; i++) cin >> u[i] >> v[i] >> w[i];

    for (int i = 0; i < e - 1; i++) {
        for (int j = i + 1; j < e; j++) {
            if (w[j] < w[i]) {
                int t = w[i]; w[i] = w[j]; w[j] = t;
                t = u[i]; u[i] = u[j]; u[j] = t;
                t = v[i]; v[i] = v[j]; v[j] = t;
            }
        }
    }

    int p[20];
    for (int i = 0; i < n; i++) p[i] = i;

    for (int i = 0; i < e; i++) {
        int a = findSet(p, u[i]);
        int b = findSet(p, v[i]);
        if (a != b) {
            cout << u[i] << " " << v[i] << " " << w[i] << endl;
            p[b] = a;
        }
    }
}
