#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int g[20][20];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int start;
    cin >> start;

    int dist[20], vis[20];
    for (int i = 0; i < n; i++) {
        dist[i] = 99999;
        vis[i] = 0;
    }

    dist[start] = 0;

    for (int k = 0; k < n; k++) {
        int mn = 99999, pos = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && dist[i] < mn) {
                mn = dist[i];
                pos = i;
            }
        }

        vis[pos] = 1;

        for (int i = 0; i < n; i++) {
            if (g[pos][i] > 0 && dist[pos] + g[pos][i] < dist[i]) {
                dist[i] = dist[pos] + g[pos][i];
            }
        }
    }

    for (int i = 0; i < n; i++) cout << dist[i] << " ";
}
