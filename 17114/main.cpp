#include <iostream>
#include <queue>

using namespace std;

int board[1000000];
int vis[1000000];
int mw[11];
int d[22];
int sssize = 1;
queue<int> q;

int check_range(int cur, int i) {
    int cor[11];
    for(int k = 10; k >= i % 11; k--) {
        cor[k] = cur / d[k];
        cur %= d[k];
    }

    if (i < 11) {
        if (cor[i] + 1 >= mw[i]) return 1;
    } else {
        if (cor[i - 11] - 1 < 0) return 1;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 11; i++) {
        cin >> mw[i];
        sssize *= mw[i];
    }
    d[0] = 1;
    d[11] = -1;
    for(int i = 1; i < 11; i++) {
        d[i] = d[i - 1] * mw[i - 1];
        d[i + 11] = -d[i];
    }
    for(int i = 0; i < sssize; i++) {
        cin >> board[i];
        vis[i] = -1;
        if (board[i] == 1) {
            q.push(i);
            vis[i] = 0;
        }
    }

    int mmax = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < 22; i++) {
            int nx = cur + d[i];

            if (check_range(cur, i) != 0) continue;
            if (vis[nx] != -1 || board[nx] != 0) continue;

            vis[nx] = vis[cur] + 1;
            if(mmax < vis[nx]) mmax = vis[nx];
            q.push(nx);
        }
    }

    for(int i = 0; i < sssize; i++) {
        if(board[i] == 0 && vis[i] == -1) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << mmax << '\n';
}
