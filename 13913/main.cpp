#include <iostream>
#include <queue>

using namespace std;

int board[100001];
int vis[100001];
int wis[100001];

queue<int> q;
int n, k;

int main() {
    cin >> n >> k;
    q.push(n);
    vis[n] = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int n[3] = {cur - 1, cur + 1, cur * 2};

        for(int i = 0; i < 3; i++) {
            if(n[i] < 0 || n[i] >= 100001) continue;
            if(vis[n[i]] != 0) continue;

            vis[n[i]] = vis[cur] + 1;
            wis[n[i]] = cur;
            q.push(n[i]);
        }
    }
    cout << vis[k] - 1 << '\n';
    int route[vis[k]];
    int s = vis[k];
    int i = vis[k] - 1;
    while (k != n) {
        route[i] = k;
        k = wis[k];
        i--;
    }
    route[0] = n;
    for(int i = 0; i < s; i++) {
        cout << route[i] << ' ';
    }
    cout << '\n';
}
