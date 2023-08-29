#include <iostream>
#include <queue>

using namespace std;

int board[100000];
int t, n;
int vis[100000];
int wis[100000];
queue<int> q;
int c;

void printv() {
    for(int i = 0; i < n; i++) {
        cout << vis[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n; i++) {
        cout << wis[i] << ' ';
    }
    cout << '\n';
    cout << '\n';
}

int solution() {
    int result = 0;

    // printv();
    // cout << "result: " << result << "\n\n";
    for(int i = 0; i < n; i++) {
        if (vis[i] != 0) continue;
        q.push(i);
        vis[i] = ++c;
        wis[i] = 1;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int nx = board[cur];

            if (vis[nx] == 0) {
                vis[nx] = vis[cur];
                wis[nx] = wis[cur] + 1;
                q.push(nx);
            } else if (vis[nx] == vis[cur]) {
                result += wis[cur] - wis[nx] + 1;
            }
        }
        // printv();
        // cout << "result: " << result << '\n';
    }
    return n - result;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            c = 0;
            cin >> board[i];
            board[i]--;
            vis[i] = 0;
            wis[i] = 0;
        }
        int result = solution();
        cout << result << '\n';
    }
}
