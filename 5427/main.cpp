#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

void print();

int board[1001][1001];
int jis[1001][1001];
int fis[1001][1001];
queue<pair<int, int> > jq;
queue<pair<int, int> > fq;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int h, w;

int jsearch() {
    pair<int, int> cur = jq.front(); jq.pop();
    for(int i = 0; i < 4; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];

        if (board[cur.first][cur.second] != 0) continue ;
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
            return jis[cur.first][cur.second];
        }
        if (jis[nx][ny] != 0 || board[nx][ny] != 0) continue ;

        jis[nx][ny] = jis[cur.first][cur.second] + 1;
        jq.push(make_pair(nx, ny));
    }
    return 0;
}

void fsearch() {
    pair<int, int> cur = fq.front(); fq.pop();
    for(int i = 0; i < 4; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue ;
        if (fis[nx][ny] != 0 || board[nx][ny] != 0) continue;

        fis[nx][ny] = 1;
        board[nx][ny] = 2;
        fq.push(make_pair(nx, ny));
    }
}

void init() {
    while (!jq.empty()) jq.pop();
    while (!fq.empty()) fq.pop();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            board[i][j] = 0;
            jis[i][j] = 0;
            fis[i][j] = 0;
        }
    }
}

int solution() {
    init();
    cin >> w >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            char t;
            cin >> t;
            if (t == '#') {
                board[i][j] = 1;
            } else if (t == '.') {
                board[i][j] = 0;
            } else if (t == '@') {
                board[i][j] = 0;
                jis[i][j] = 1;
                jq.push(make_pair(i, j));
            } else if (t == '*') {
                board[i][j] = 2;
                fis[i][j] = 1;
                fq.push(make_pair(i, j));
            }
        }
    }
    // print();
    while (!jq.empty()) {
        int n = jq.size();
        for(int i = 0; i < n; i++) {
            int result = jsearch();
            if (result != 0) return result;
        }
        n = fq.size();
        for(int i = 0; i < n; i++) {
            fsearch();
        }
        // print();
    }
    return -1;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int result = solution();
        if (result == -1) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << result << '\n';
        }
    }
}

void print() {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << board[i][j] << ' ';
        }
        cout << "  ";
        for(int j = 0; j < w; j++) {
            cout << jis[i][j] << ' ';
        }
        cout << "  ";
        for(int j = 0; j < w; j++) {
            cout << fis[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
