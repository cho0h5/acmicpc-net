#include <iostream>
#include <queue>

using namespace std;

int s, g, f;
int vis[1000001];
int dx[2];
queue<int> q;

void printv() {
    for(int i = 1; i <= f; i++) {
        cout << vis[i] << ' ';
    }
    cout << '\n';
}

int main() {
    cin >> f >> s >> g >> dx[0] >> dx[1];
    fill_n(vis, 1000000, -1);
    dx[1] *= -1;

    vis[s] = 0;
    q.push(s);
    // printv();
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == g) {
            cout << vis[cur];
            exit(0);
        }

        for(int i = 0; i < 2; i++) {
            int nx = cur + dx[i];

            if (nx < 1 || nx > f) continue;
            if (vis[nx] != -1) continue;

            vis[nx] = vis[cur] + 1;
            q.push(nx);
        }
        // printv();
    }
    cout << "use the stairs";
    exit(0);
}
