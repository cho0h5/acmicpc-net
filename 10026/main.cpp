#include <iostream>
#include <queue>

using namespace std;

char board[100][100];
int jis[100][100];
int bis[100][100];
int n;
queue<pair<int, int> > q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void printm() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void printj() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << jis[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int jsearch() {
    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (jis[i][j] != 1) {
                jis[i][j] = 1;
                result++;
                q.push(make_pair(i, j));

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();

                    for (int i = 0; i < 4; i++) {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] != board[cur.first][cur.second]
                                || jis[nx][ny] == 1) continue;

                        jis[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
                // printj();
            }
        }
    }
    return result;
}

int bsearch() {
    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (bis[i][j] != 1) {
                bis[i][j] = 1;
                result++;
                q.push(make_pair(i, j));

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();

                    for (int i = 0; i < 4; i++) {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (bis[nx][ny] == 1) continue;

                        if (board[cur.first][cur.second] == 'B' && board[nx][ny] != 'B') continue;
                        if (board[cur.first][cur.second] == 'R' && board[nx][ny] == 'B') continue;
                        if (board[cur.first][cur.second] == 'G' && board[nx][ny] == 'B') continue;

                        bis[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
                // printj();
            }
        }
    }
    return result;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    // printm();
    cout << jsearch() << ' ';
    cout << bsearch() << '\n';
}
