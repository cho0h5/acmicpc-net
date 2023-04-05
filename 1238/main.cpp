#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <queue>

using namespace std;

int N, M, X;
int isVisit[1001];
vector<pair<int, int> > graph[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> X;

    for(int i = 0; i < M;i++) {
	int n1, n2, cost;
	cin >> n1 >> n2 >> cost;
	graph[n1].push_back(make_pair(n2, cost));
    }

    for(int i = 1; i <= N; i++) {
	for(int j = 0; j < graph[i].size(); j++) {
	    cout << i << ' ' << graph[i][j].first << ' ' << graph[i][j].second << '\n';
	}
    }

}
