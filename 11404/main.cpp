#include <iostream>
#define INF 1000000000

using namespace std;

int N, M;
int cost[101][101];

void print_cost() {
    for(int i = 1; i <= N; i++) {
	for(int j = 1; j <= N; j++) {
	    cout << cost[i][j] << ' ';
	}
	cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
	for(int j = 1; j <= N; j++)
	    cost[i][j] = INF;
	cost[i][i] = 0;
    }

    for(int i = 0; i < M; i++) {
	int s, d, c;
	cin >> s >> d >> c;
	if(cost[s][d] > c) cost[s][d] = c;
    }

    for(int m = 1; m <= N; m++) {
	for(int s = 1; s <= N; s++) {
	    for(int d = 1; d <= N; d++) {
		if(cost[s][d] > cost[s][m] + cost[m][d]) {
		    cost[s][d] = cost[s][m] + cost[m][d];
		}
	    }
	}
    }

    for(int s = 1; s <= N; s++) {
	for(int d = 1; d <= N; d++) {
	    if(cost[s][d] == INF) {
		cost[s][d] = 0;
	    }
	}
    }

    print_cost();
}
