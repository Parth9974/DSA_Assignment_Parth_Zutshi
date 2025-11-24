#include <iostream>
using namespace std;

int g[20][20], vis[20], n;

void dfs(int x) {
    vis[x] = 1;
    cout << x << " ";
    for (int i = 0; i < n; i++) {
        if (g[x][i] == 1 && vis[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int start;
    cin >> start;

    for (int i = 0; i < n; i++) vis[i] = 0;

    dfs(start);
}
