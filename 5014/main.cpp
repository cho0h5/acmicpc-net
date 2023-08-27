#include <iostream>
#include <queue>

using namespace std;

int s, g, f;
int vis[1000002];
int dx[2];
queue<int> q;

void printv() {
    for(int i = 0; i <= f + 1; i++) {
        printf("%2d ", vis[i]);
    }
    cout << '\n';
}

int main() {
    cin >> f >> s >> g >> dx[0] >> dx[1];
    fill_n(vis + 1, f + 1, -1);
    dx[1] *= -1;

    vis[s] = 0;
    q.push(s);
    // printv();
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < 2; i++) {
            int nx = cur + dx[i];

            if (nx < 1 || nx > f) continue;
            if (vis[nx] != -1) continue;

            vis[nx] = vis[cur] + 1;
            q.push(nx);
        }
        // printv();
    }
    if (vis[g] == -1) {
        cout << "use the stairs";
    } else {
        cout << vis[g];
    }
}
