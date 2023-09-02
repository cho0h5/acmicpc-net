#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int> > q;
int vis[500001][2];

int n, k;

void printv() {
    for (int i = 0; i < 21; i++) {
        printf("%2d ", i);
    }
    cout << '\n';
    for (int i = 0; i < 21; i++) {
        printf("%2d ", vis[i][0]);
    }
    cout << '\n';
    for (int i = 0; i < 21; i++) {
        printf("%2d ", vis[i][1]);
    }
    cout << '\n';
    cout << '\n';
}

int main() {
    cin >> n >> k;
    if (n == k) {
        cout << "0\n";
        return 0;
    }
    q.push(make_pair(n, 0));
    vis[n][0] = 1;


    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int nx[3] = {cur.first - 1, cur.first + 1, cur.first * 2};
        int ns = !cur.second;

        for (int j = 0; j < 3; j++) {
            if (nx[j] < 0 || nx[j] > 500000) continue;
            if (vis[nx[j]][ns] != 0) continue;

            vis[nx[j]][ns] = vis[cur.first][cur.second] + 1;
            q.push(make_pair(nx[j], ns));
        }
    }
    // printv();

    for (int z = 0; k <= 500000; z++) {
        k += z;

        if (vis[k][z % 2] != 0 && vis[k][z % 2] <= z + 1) {
            cout << z << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}
