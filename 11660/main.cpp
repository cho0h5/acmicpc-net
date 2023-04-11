#include <iostream>

using namespace std;

int N, M;
int table[1025][1025];
int acc[1025][1025];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
	for (int j = 1; j <= N; j++) {
	    int n;
	    cin >> n;
	    table[i][j] = n;
	    acc[i][j] = table[i][j] + acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1];
	}
    }

//    for(int i = 1; i <= N; i++) {
//	for (int j = 1; j <= N; j++) {
//	    cout << acc[i][j] << ' ';
//	}
//	cout << '\n';
//    }

    for(int i = 0; i < M; i++) {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << (acc[x2][y2] - acc[x2][y1-1] - acc[x1-1][y2] + acc[x1-1][y1-1]) << '\n';
    }
}
