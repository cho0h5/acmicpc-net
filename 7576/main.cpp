#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int table[1000][1000];
int M, N;

int check(int x, int y, int s) {
    if(x < 0 || x >= N) return 0;
    if(y < 0 || y >= M) return 0;
    if(table[x][y] == -1) return 0;

    if(table[x][y] == 0) return 1;
    return table[x][y] > s;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<tuple<int, int, int> > q;

    // init
    cin >> M >> N;
    for(int i = 0; i < N; i++)
	for(int j = 0; j < M; j++) {
	    cin >> table[i][j];
	    if(table[i][j] == 1)
		q.push(make_tuple(i, j, 1));
	}

    // solution
    while(!q.empty()) {
	int x, y, s;
	tie(x, y, s) = q.front();
	q.pop();

	if(check(x-1, y, s+1)) {
	    table[x-1][y] = s+1;
	    q.push(make_tuple(x-1, y, s+1));
	}
	if(check(x+1, y, s+1)) {
	    table[x+1][y] = s+1;
	    q.push(make_tuple(x+1, y, s+1));
	}
	if(check(x, y-1, s+1)) {
	    table[x][y-1] = s+1;
	    q.push(make_tuple(x, y-1, s+1));
	}
	if(check(x, y+1, s+1)) {
	    table[x][y+1] = s+1;
	    q.push(make_tuple(x, y+1, s+1));
	}
    }

    int max = 0;
    for(int i = 0; i < N; i++) {
	for(int j = 0; j < M; j++) {
	    if(table[i][j] == 0) {
		cout << "-1\n";
		return 0;
	    }
	    if(table[i][j] > max) max = table[i][j];
	}
    }
    cout << --max;
}

