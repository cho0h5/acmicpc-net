#include <iostream>
#include <utility>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;
using ii = pair<long long, long long>;

long long n;
long long total_n;
long long d[400000];
long long graph[400000];
priority_queue<ii, vector<ii>, greater<ii>> q;

void dijkstra() {
    while(q.size()) {
        auto [cc, cn] = q.top();
        q.pop();
        // printf("pop: %d, %d\n", cc, cn);

        const long long prev = (cn - 1 + total_n) % total_n;
        const long long next = (cn + 1 + total_n) % total_n;

        if (graph[prev] == 0 || graph[prev] > d[prev] + cc) {
            // printf("prev: %d, %d, %d\n", graph[prev], d[prev], cc);
            graph[prev] = d[prev] + cc;

            q.push({graph[prev], prev});
        }

        if (graph[next] == 0 || graph[next] > d[cn] + cc) {
            // printf("next: %d, %d, %d\n", graph[next], d[cn], cc);
            graph[next] = d[cn] + cc;

            q.push({graph[next], next});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    total_n = n << 2;
    for (int i = 0; i < total_n; i++) {
        cin >> d[i];
    }

//    for (int i = 0; i < total_n; i++) {
//        printf("%d\n", d[i]);
//    }
//    printf("----\n");

    for (int i = 0; i < 4; i++) {
        array<int, 3> cost;

        cin >> cost[0];
        cin >> cost[1];
        cin >> cost[2];

        long long minimum = *min_element(cost.begin(), cost.end());

        const long long index = (i + 1) * n - 1;
        graph[index] = minimum;
        // printf("debug: %d %d\n", index, minimum);

        q.push({minimum, index});
    }

//    for (int i = 0; i < total_n; i++) {
//        printf("%d\n", graph[i]);
//    }
//    printf("----\n");

    dijkstra();

//    printf("----\n");
//    for (int i = 0; i < total_n; i++) {
//        printf("%d\n", graph[i]);
//    }

    long long query_n;
    cin >> query_n;
    for (int i = 0; i < query_n; i++) {
        long long query;
        cin >> query;

        printf("%lld\n", graph[query - 1]);
    }
}
