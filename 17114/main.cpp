#include <iostream>
#include <queue>

using namespace std;

int board[1000000];
int vis[1000000];
int mw[11];
int d[22];
int sssize = 1;
queue<int> q;

void printb() {
    for(int i = 0; i < sssize; i++) {
        cout << board[i] << ' ';
    }
    cout << '\n';
}

void printv() {
    for(int i = 0; i < sssize; i++) {
        cout << vis[i] << ' ';
    }
    cout << '\n';
}

int check_range(int cur, int i) {
    int cor[11];
    for(int i = 10; i >= 0; i--) {
        cor[i] = cur / d[i];
        cur %= d[i];
    }

    if (0 <= i && i < 11) {
        int n = cor[i] + 1;
        if (n >= mw[i]) return 1;
    } else {
        int n = cor[i - 11] - 1;
        if (n < 0) return 1;
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
    for(int i = 1; i < 11; i++) {
        d[i] = d[i - 1] * mw[i - 1];
    }
    for(int i = 11; i < 22; i++) {
        d[i] = -d[i - 11];
    }
    for(int i = 0; i < sssize; i++) {
        cin >> board[i];
        vis[i] = -1;
        if (board[i] == 1) {
            q.push(i);
            vis[i] = 0;
        }
    }
    // printb();

    // printv();
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < 22; i++) {
            int nx = cur + d[i];

            if (check_range(cur, i) != 0) continue;
            // cout << "pass? " << vis[nx] << ' ' << board[nx] << '\n';
            if (vis[nx] != -1 || board[nx] != 0) continue;
            // cout << "pass!\n";

            vis[nx] = vis[cur] + 1;
            q.push(nx);
        }
        // printv();
    }

    int mmax = 0;
    for(int i = 0; i < sssize; i++) {
        if(mmax < vis[i]) mmax = vis[i];
        if(board[i] == 0 && vis[i] == -1) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << mmax << '\n';
}
