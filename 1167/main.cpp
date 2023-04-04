#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int isVisit[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<tuple<int, int> > table[100001];
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
	int n1, n2, cost;
	cin >> n1;
	while(true) {
	    cin >> n2;
	    if(n2 == -1) break;
	    cin >> cost;
	    table[n1].push_back(make_pair(n2, cost));
	}
    }

//    cout << "[check table]\n";
//    for(int i = 1; i <= N; i++) {
//	for(int j = 1; j <= N; j++) {
//	    cout << table[i][j] << ' ';
//	}
//	cout << '\n';
//    }

    // first bfs
    for(int i = 1; i <= N; i++) isVisit[i] = -1;
    queue<pair<int, int> > q;
    q.push(make_pair(1, 0));
    while(!q.empty()) {
	int node, cost;
	tie(node, cost) = q.front();
	q.pop();
	if(isVisit[node] != -1) continue;

	isVisit[node] = cost;
	for(int i = 0; i < table[node].size(); i++) {
	    int n2, n2cost;
	    tie(n2, n2cost) = table[node][i];
	    q.push(make_pair(n2, cost + n2cost));
	}
    }

//    cout << "[check isvisit]\n";
//    for(int i = 1; i <= N; i++) cout << isVisit[i] << ' ';
//    cout << '\n';

    int max_idx = 1;
    int max = 0;
    for(int i = 1; i <= N; i++) {
	if(isVisit[i] > max) {
	    max = isVisit[i];
	    max_idx = i;
	}
    }

    // cout << "[check max_idx and max] " << max_idx << ' ' << max << '\n';

    // second bfs
    for(int i = 1; i <= N; i++) isVisit[i] = -1;
    q.push(make_pair(max_idx, 0));
    while(!q.empty()) {
	int node, cost;
	tie(node, cost) = q.front();
	q.pop();
	if(isVisit[node] != -1) continue;

	isVisit[node] = cost;
	for(int i = 0; i < table[node].size(); i++) {
	    int n2, n2cost;
	    tie(n2, n2cost) = table[node][i];
	    q.push(make_pair(n2, cost + n2cost));
	}
    }

//    cout << "[check isvisit]\n";
//    for(int i = 1; i <= N; i++) cout << isVisit[i] << ' ';
//    cout << '\n';

    max = 0;
    for(int i = 1; i <= N; i++) {
	if(isVisit[i] > max) {
	    max = isVisit[i];
	    max_idx = i;
	}
    }
    // cout << "[check max_idx and max] " << max_idx << ' ' << max << '\n';
    cout << max;
}
