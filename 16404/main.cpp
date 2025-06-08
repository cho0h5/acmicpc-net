#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> children[100001];
int s_id[100001];
int e_id[100001];
int next_id = 1;

void dfs(const int node) {
    s_id[node] = next_id++;

    for (auto &c: children[node]) {
        dfs(c);
    }

    e_id[node] = next_id - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;

    int parent;
    cin >> parent;
    for (int i = 2; i <= n; i++) {
        cin >> parent;
        children[parent].push_back(i);
    }

    // Re-assign id
    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << s_id[i] << ' ' << e_id[i] << ", ";
    }
    cout << '\n';

//     for (int i = 0; i < m; i++) {
//         int a, b, c;
//         cin >> a;
// 
//         if (a == 1) {
//             cin >> b >> c;
//             set(b, c);
//         } else {
//             cin >> b;
//             cout << get(b) << '\n';
//         }
//     }
}
