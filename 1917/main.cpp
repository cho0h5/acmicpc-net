#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<vector<int>> board(6, vector<int>(6, 0));
vector<vector<int>> vst(6, vector<int>(6, 0));
int dice[6];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void turn(int dir) {
	if (dir == 0) {
		int tmp = dice[0];
		dice[0] = dice[5];
		dice[5] = dice[2];
		dice[2] = dice[4];
		dice[4] = tmp;
	} else if (dir == 1) {
		int tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = tmp;
	} else if (dir == 2) {
		int tmp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[5];
		dice[5] = tmp;
	} else if (dir == 3) {
		int tmp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = tmp;
	}
}


int bfs(int x, int y) {
	if (x < 0 || x >= 6 || y < 0 || y >= 6)
		return 0;
	if (board[x][y] == 0 || vst[x][y] == 1)
		return 0;
	vst[x][y] = 1;
	if (dice[0] != 0)
        return -1;
	dice[0] = board[x][y];
	for (int i = 0; i < 4; i++) {
		turn(i);
		bfs(x + dx[i], y + dy[i]);
		turn((i + 2) % 4);
	}
    return 0;
}

void solve() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (board[i][j] == 1)
				if (bfs(i, j)) {
                    cout << "no\n";
                    return;
                }
		}
	}
	for (int i = 0; i < 6; i++) {
		if (dice[i] == 0) {
            cout << "no\n";
            return;
        }
	}
	cout << "yes\n";
}
int main() {
	fastio();

    solve();
    for (int i = 0; i < 6; i++)
        dice[i] = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            vst[i][j] = 0;
        }
    }
    solve();
    for (int i = 0; i < 6; i++)
        dice[i] = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            vst[i][j] = 0;
        }
    }
    solve();
}