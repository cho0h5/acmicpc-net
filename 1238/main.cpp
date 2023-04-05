#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <queue>

using namespace std;

int N, M, X;
int isVisit[1001];
vector<pair<int, int> > graph[1001];

int search(int S, int D) {
    for(int i = 1; i <= N; i++) isVisit[i] = 1000;
    queue<pair<int, int> > q;
    q.push(make_pair(S, 0));

    while(!q.empty()) {
	int node, cost;
	tie(node, cost) = q.front();
	q.pop();
	if(isVisit[node] <= cost) continue;
	isVisit[node] = cost;
	for(int i = 0; i < graph[node].size(); i++) {
	    int n2, n2cost;
	    tie(n2, n2cost) = graph[node][i];
	    q.push(make_pair(n2, cost + n2cost));
	}
    }

    return isVisit[D];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> X;

    for(int i = 0; i < M;i++) {
	int n1, n2, cost;
	cin >> n1 >> n2 >> cost;
	graph[n1].push_back(make_pair(n2, cost));
    }

    int max = 0;
    for(int i = 1; i <= N; i++) {
	if(i == X) continue;
	int cost = search(i, X) + search(X, i);
	if(cost > max) max = cost;
    }
    cout << max;
}
