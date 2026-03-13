#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <queue>

using namespace std;
using ii = pair<int, int>;

int n, m, k;
vector<pair<int, int>> graph_origin;
vector<int> order;

vector<int> graph[100001];
int vst[100001];

int optim_ck = 2147483647;
int optim_a;
int optim_b;
int suboptim_a;
int suboptim_b;

bool bfs(const int ck) {
    // printf("\n");
    // printf("bfs(%d)\n", ck);

    // init
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        vst[i] = 0;
    }

    unordered_set<int> ban(order.begin(), order.begin() + ck);

    for (int i = 0; i < m; i++) {
        if (ban.find(i + 1) != ban.end()) continue;

        const int a = graph_origin[i].first;
        const int b = graph_origin[i].second;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // debug
//    printf("ban: ");
//    for (auto e: ban) {
//        printf("%d ", e);
//    }
//    printf("\n");
//
//    for (int i = 1; i <= n; i++) {
//        printf("%d: ", i);
//        for (int j = 0; j < graph[i].size(); j++) {
//            printf("%d ", graph[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");

    // bfs
    int class_population[3] = { 0, };

    queue<ii> q;
    vst[1] = 1;
    class_population[vst[1]] += 1;
    for (int i = 0; i < graph[1].size(); i++) {
        q.push({graph[1][i], 2});
    }

    while (q.size()) {
        auto [cn, cc] = q.front();
        q.pop();

        if (vst[cn] == cc) continue;
        if (vst[cn] == 3 - cc) {
//            printf("org: %d, new: %d (cn: %d)\n", vst[cn], cc, cn);
//            printf("vst: ");
//            for (int i = 1; i <= n; i++) {
//                printf("%d ", vst[i]);
//            }
//            printf("\n");
            return false;
        }

        vst[cn] = cc;
        class_population[vst[cn]] += 1;
        for (int i = 0; i < graph[cn].size(); i++) {
            q.push({graph[cn][i], 3 - cc});
        }
    }

    if (class_population[1] + class_population[2] != n) return false;

    suboptim_a = class_population[1];
    suboptim_b = class_population[2];
    return true;
}

void binary_search(const int s, const int e) {
    if (e < s) return;

    const int mid = (s + e) >> 1;

    if (bfs(mid)) {
        if (optim_ck > mid) {
            optim_ck = mid;
            optim_a = suboptim_a;
            optim_b = suboptim_b;
        }
        binary_search(s, mid - 1);
    } else {
        binary_search(mid + 1, e);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph_origin.push_back({a, b});
    }
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        order.push_back(a);
    }

//    for (int i = 0; i <= k; i++) {
//        printf("Manual bfs(%d): %d\n", i, bfs(i));
//    }

    binary_search(0, k);

    if (optim_ck == 2147483647) {
        printf("-1\n");
        exit(0);
    }

    printf("%d\n", optim_ck);
    if (optim_a < optim_b) {
        printf("%d ", optim_a);
        printf("%d\n", optim_b);
    } else {
        printf("%d ", optim_b);
        printf("%d\n", optim_a);
    }
}
