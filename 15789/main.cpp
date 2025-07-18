#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int c, h, k;

int parents[100001];
int population[100001];

int find(const int n) {
    if (parents[n] == n) {
        return n;
    }
    return parents[n] = find(parents[n]);
}

void merge(const int a, const int b) {
    const int pa = find(a);
    const int pb = find(b);

    parents[pb] = pa;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    cin >> c >> h >> k;
    for (int i = 1; i <= n; i++) {
        const int p = find(i);
        population[p] += 1;
    }

    vector<int> candidates;
    int sumation = 0;
    for (int i = 1; i <= n; i++) {
        if (population[i] == 0) {
            continue;
        }
        if (find(c) == i) {
            sumation += population[i];
            continue;
        }
        if (find(h) == i) {
            continue;
        }

        candidates.push_back(population[i]);
    }
    sort(candidates.rbegin(), candidates.rend());

//    for (int i = 1; i <= n; i++) {
//        printf("%d ", parents[i]);
//    }
//    printf("\n");
//    for (int i = 1; i <= n; i++) {
//        printf("%d ", population[i]);
//    }
//    printf("\n");
//    for (int i = 0; i < candidates.size(); i++) {
//        printf("%d ", candidates[i]);
//    }
//    printf("\n");

    for (int i = 0; i < k && i < candidates.size(); i++) {
        sumation += candidates[i];
    }
    printf("%d\n", sumation);

    return 0;
}
