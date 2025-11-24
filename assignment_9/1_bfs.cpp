#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int g[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> g[i][j];
    }

    int start;
    cin >> start;

    int q[50], f = 0, r = 0;
    int vis[20] = {0};

    q[r++] = start;
    vis[start] = 1;

    while (f < r) {
        int x = q[f++];
        cout << x << " ";
        for (int i = 0; i < n; i++) {
            if (g[x][i] == 1 && vis[i] == 0) {
                vis[i] = 1;
                q[r++] = i;
            }
        }
    }
}
