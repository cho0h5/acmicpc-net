#include <iostream>

using namespace std;

int graph[10001];
int visit[10001];

void traverse_x(int x) {
    while (1) {
        visit[x] = 1;
        if (graph[x] == x) {
            break;
        }
        x = graph[x];
    }
}

int traverse_y(int y) {
    while (1) {
        if (visit[y] == 1) {
            return y;
        }
        y = graph[y];
    }
}

int solution(int x, int y) {
    traverse_x(x);
    return traverse_y(y);
}

void init(int n) {
    for (int i = 0; i <= n; i++) {
        graph[i] = i;
        visit[i] = 0;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
	    int n;
        cin >> n;
        init(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            graph[b] = a;
        }
        int x, y;
        cin >> x >> y;
        cout << solution(x, y) << '\n';
	}
}
