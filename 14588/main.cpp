#include <iostream>
#include <vector>

#define MAXIMUM 500

using namespace std;

int n;
int friends[300][2];
int graph[300][300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> friends[i][0] >> friends[i][1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = MAXIMUM;

            if (i == j) {
                continue;
            }

            if (friends[i][1] < friends[j][0] || friends[j][1] < friends[i][0]) {
                continue;
            }

            graph[i][j] = 1;
        }
    }


//    for (int i = 0; i < n; i++) {
//        printf("%d: ", i);
//        for (int j = 0; j < n; j++) {
//            printf("%2d ", graph[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        const int cost = graph[x - 1][y - 1];
        if (cost == MAXIMUM) {
            printf("-1\n");
        } else {
            printf("%d\n", cost);
        }
    }
}
