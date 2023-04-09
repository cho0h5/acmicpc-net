#include <iostream>
#define INF 2000000000

using namespace std;

int graph[501][501];
int cost[501];
void solution() {
    int N, M, W;
    cin >> N >> M >> W;
    // initialize
    for(int i = 1; i <= N; i++) {
	for(int j = 1; j <= N; j++)
	    graph[i][j] = INF;
	cost[i] = INF;
    }
    // input
    for(int i = 0; i < M; i++) {
	int s, e, t;
	cin >> s >> e >> t;
	if(graph[s][e] > t) {
	    graph[s][e] = t;
	    graph[e][s] = t;
	}
    }
    for(int i = 0; i < W; i++) {
	int s, e, t;
	cin >> s >> e >> t;
	if(graph[s][e] > -t)
	    graph[s][e] = -t;
    }

//    for(int i = 1; i <= N; i++) {
//	for(int j = 1; j <= N; j++) {
//	    cout << graph[i][j] << ' ';
//	}
//	cout << '\n';
//    }

    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}
