#include <iostream>
#include <vector>
#include <queue>

#define RED 1
#define BLUE 2

using namespace std;

int n, m;
vector<int> graph[1000001];
int vst[1000001];

bool bfs(const int s) {
    queue<int> q;

    vst[s] = RED;
    q.push(s);

    while (q.size()) {
        const int curr = q.front();
        q.pop();

        for (const int next: graph[curr]) {
            if (vst[next] == 0) {
                vst[next] = 3 - vst[curr];

                q.push(next);
            } else {
                if (vst[curr] == vst[next]) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool check() {
    for (int i = 1; i <= n; i++) {
        if (vst[i] != 0) continue;


        if (!bfs(i)) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    printf("%s\n", check() ? "POSSIBLE" : "IMPOSSIBLE");

    return 0;
}
