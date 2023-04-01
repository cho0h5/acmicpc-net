#include <queue>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    int table[150001];
    for(int i = 0; i < 150000; i++) table[i] = 200000;
    int n, k;
    cin >> n >> k;
    table[n] = 0;
    q.push(n);

    while(!q.empty()) {
	int node = q.front();
	q.pop();

	if(node > 0) {
	    if(table[node-1] > table[node] + 1) {
		table[node-1] = table[node] + 1;
		q.push(node-1);
	    }
	}
	if(node < 150000) {
	    if(table[node+1] > table[node] + 1) {
		table[node+1] = table[node] + 1;
		q.push(node+1);
	    }
	}
	if(node * 2 < 150000) {
	    if(table[node*2] > table[node] + 1) {
		table[node*2] = table[node] + 1;
		q.push(node * 2);
	    }
	}

    }



    cout << table[k];
}
