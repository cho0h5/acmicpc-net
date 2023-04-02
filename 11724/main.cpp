#include <iostream>
#include <vector>
#include <queue>

using namespace std;

short isVisit[1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<short> graph[1001];
    for(int i = 1; i < 1001; i++) graph[i].reserve(1000);
    queue<short> q;
    while(M--) {
	int n1, n2;
	cin >> n1 >> n2;
	graph[n1].push_back(n2);
	graph[n2].push_back(n1);
    }


    int count = 0;
    while(true) {
	int flag = 0;
	for(int i = 1; i <= N; i++) {
	    if(isVisit[i] == 0) {
		flag = i;
		break;
	    }
	}
	if(flag == 0) break;
	else q.push(flag);
	count++;

	while(!q.empty()) {
	    int node = q.front();
	    q.pop();
	    if(isVisit[node] == 1) continue;
	    isVisit[node] = 1;
	    for(auto next : graph[node])
		if(isVisit[next] != 1)
		    q.push(next);
	}
    }

    cout << count << '\n';
}
