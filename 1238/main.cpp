#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <queue>

#define INF 100000000

using namespace std;

int N, M, X;
int isVisit[1001];
int isVisit2[1001];
vector<pair<int, int> > graph[1001];
vector<pair<int, int> > graph2[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> X;

    for(int i = 0; i < M; i++) {
	int n1, n2, cost;
	cin >> n1 >> n2 >> cost;
	graph[n1].push_back(make_pair(n2, cost));
	graph2[n2].push_back(make_pair(n1, cost));
    }
    
    // dik1
    for(int i = 1; i <= N; i++) isVisit[i] = INF;
    priority_queue<pair<int, int > > pq;

    pq.push(make_pair(0, X));
    while(!pq.empty()) {
	int cost, node;
	tie(cost, node) = pq.top();
	pq.pop();
	isVisit[node] = cost;

	for(int i = 0; i < graph[node].size(); i++) {
	    int cost2, node2;
	    tie(node2, cost2) = graph[node][i];

	    if(cost + cost2 < isVisit[node2])
		pq.push(make_pair(cost + cost2, node2));
	}
    }


    // for(int i = 1; i <= N; i++) cout << isVisit[i] << ' ';
    // cout << '\n';

    // dik2
    for(int i = 1; i <= N; i++) isVisit2[i] = INF;

    pq.push(make_pair(0, X));
    while(!pq.empty()) {
	int cost, node;
	tie(cost, node) = pq.top();
	pq.pop();
	isVisit2[node] = cost;

	for(int i = 0; i < graph2[node].size(); i++) {
	    int cost2, node2;
	    tie(node2, cost2) = graph2[node][i];

	    if(cost + cost2 < isVisit2[node2])
		pq.push(make_pair(cost + cost2, node2));
	}
    }


    // for(int i = 1; i <= N; i++) cout << isVisit[i] << ' ';
    // cout << '\n';
    
    int max = 0;
    for(int i = 1; i <= N; i++)
	if(isVisit[i] + isVisit2[i] > max) max = isVisit[i] + isVisit2[i];

    cout << max;
}
