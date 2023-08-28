#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int board[30][30][30];
int vis[30][30][30];
int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, -1, 0, 1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int> > q;
int l, r, c;

void printb() {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cout << board[i][j][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    cout << '\n';
}

void printv() {
    cout << "-----\n";
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cout << vis[i][j][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    cout << "-----\n";
    cout << '\n';
}

int main() {
    while (1) {
        cin >> l >> r >> c;
        if (l == 0) break;

        while (!q.empty()) q.pop();

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    vis[i][j][k] = -1;
                    char c;
                    cin >> c;
                    if (c == 'S') {
                        q.push(make_tuple(i, j, k));
                        vis[i][j][k] = 0;
                        board[i][j][k] = 0;
                    } else if (c == '.') {
                        board[i][j][k] = 0;
                    } else if (c == '#') {
                        board[i][j][k] = 1;
                    } else if (c == 'E') {
                        board[i][j][k] = 2;
                    }
                }
            }
        }
        // printb();

        int result = 0;
        int flag = 0;
        // printv();
        while(!q.empty()) {
            tuple<int, int, int> cur = q.front(); q.pop();
            if(board[get<0>(cur)][get<1>(cur)][get<2>(cur)] == 2){
                result = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)];
                flag = 1;
                break;
            }
            for(int i = 0; i < 6; i++) {
                int nx = get<0>(cur) + dx[i];
                int ny = get<1>(cur) + dy[i];
                int nz = get<2>(cur) + dz[i];

                if(nx < 0 || nx >= l) continue;
                if(ny < 0 || ny >= r) continue;
                if(nz < 0 || nz >= c) continue;
                if(vis[nx][ny][nz] != -1) continue;
                if(board[nx][ny][nz] == 1) continue;

                vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                q.push(make_tuple(nx, ny, nz));
            }
            // printv();
        }
        if (flag) cout << "Escaped in " <<  result << " minute(s).\n";
        else cout << "Trapped!\n";
    }
}
