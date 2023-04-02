#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int isVisit[51];
int graph[51][51];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> party[51];
    queue<int> q;
    int N, M;
    cin >> N >> M;
    int O, n;
    cin >> O;
    for(int i = 0; i < O; i++) {
	cin >> n;
	q.push(n);
    }
    for(int i = 0; i < M; i++) {
	int P;
	cin >> P;
	for(int j = 0; j < P; j++) {
	    int p;
	    cin >> p;
	    party[i].push_back(p);
	}
    }
    for(int i = 0; i < M; i++) {
	for(int j = 0; j < party[i].size(); j++) {
	    for(int k = j + 1; k < party[i].size(); k++) {
		cout << party[i][j] << ' ' << party[i][k] << '\n';
		graph[party[j][j]][party[i][k]] = 1;
		graph[party[i][k]][party[i][j]] = 1;
    cout << "[check graph]\n";
    for(int i = 1; i <= N; i++) {
	for(int j = 1; j <= N; j++) {
	    cout << graph[i][j] << ' ';
	}
	cout << '\n';
    }
	    }
	}
    }

    // check
    cout << "[check party]\n";
    for(int i = 0; i < M; i++) {
	for(auto n : party[i]) {
	    cout << n << ' ';
	}
	cout << '\n';
    }
    cout << "[check graph]\n";
    for(int i = 1; i <= N; i++) {
	for(int j = 1; j <= N; j++) {
	    cout << graph[i][j] << ' ';
	}
	cout << '\n';
    }

}
