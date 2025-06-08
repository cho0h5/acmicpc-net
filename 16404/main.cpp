#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[100001];
vector<int> children[100001];
int state[100001];
int lazy[100001];

void set(const int node, const int x) {
    state[node] += x;

    for (auto &c: children[node]) {
        lazy[c] += x;
    }
}

int get(const int node) {
    // Find path
    vector<int> path;
    int n = node;
    while (n != -1) {
        path.push_back(n);
        n = parent[n];
    }

    // Update lazy
    for (int i = path.size() - 1; i >= 0; i--) {
        const int node = path[i];

        state[node] += lazy[node];

        for (auto &c: children[node]) {
            lazy[c] += lazy[node];
        }

        lazy[node] = 0;
    }

    // Return
    return state[node];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> parent[i];

        if (i != 1) {
            children[parent[i]].push_back(i);
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a;

        if (a == 1) {
            cin >> b >> c;
            set(b, c);
        } else {
            cin >> b;
            cout << get(b) << '\n';
        }
    }
}
