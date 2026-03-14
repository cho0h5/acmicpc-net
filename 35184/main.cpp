#include <iostream>
#include <queue>

using namespace std;
using ii = pair<int, int>;

struct Crab {
    int x;
    int y;
    int dir;

    bool operator<(const Crab &other) const {
        return 0;
    }
};

int n, m, t;

char board[500][500];
Crab crab_init;
bool vst[500][500][4];

void print_debug() {

    printf("Crab: (%d, %d), %d\n", crab_init.x, crab_init.y, crab_init.dir);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

bool is_not_valid_position(const int x, const int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int bfs() {
    priority_queue<pair<int, Crab>, vector<pair<int, Crab>>, greater<pair<int, Crab>>> q;

    q.push({0, crab_init});

    while (q.size()) {
        const auto [ct, cc] = q.top();
        q.pop();

        if (vst[cc.x][cc.y][cc.dir]) continue;
        vst[cc.x][cc.y][cc.dir] = true;

        if (board[cc.x][cc.y] == 'S') {
            return ct;
        } else if (board[cc.x][cc.y] == 'T') {
            int nt = ct;
            Crab nc;
            nc.dir = (cc.dir + 1) % 4;
            nc.x = cc.x + dx[nc.dir];
            nc.y = cc.y + dy[nc.dir];
            if (!is_not_valid_position(nc.x, nc.y)) q.push({nt, nc});
        } else {
            // Rotation
            const int nt = ct + t;
            Crab nc;
            nc.x = cc.x;
            nc.y = cc.y;
            nc.dir = (cc.dir + 1) % 4;
            q.push({nt, nc});

            // Move horizontally
            for (int i = 1; i <=3; i += 2) {
                const int nt = ct + 1;
                nc.x = cc.x + dx[(cc.dir + i) % 4];
                nc.y = cc.y + dy[(cc.dir + i) % 4];
                nc.dir = cc.dir;
                if (!is_not_valid_position(nc.x, nc.y)) q.push({nt, nc});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;

            if ('0' <= x && x <= '3') {
                crab_init.x = i;
                crab_init.y = j;
                crab_init.dir = x - '0';

                board[i][j] = '.';
            } else {
                board[i][j] = x;
            }
        }
    }

    // print_debug();

    const int result = bfs();
    printf("%d\n", result);
}
