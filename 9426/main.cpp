#include <iostream>
#include <vector>

#define SEGTREE_SIZE 65537
// #define SEGTREE_SIZE 16

using namespace std;

int n, k;
vector<int> temps;

int segtree[SEGTREE_SIZE << 2];

void update(const int node, const int s, const int e, const int i, const int x) {
    // 범위가 전혀 벗어나면 나가리
    if (i < s || e < i) {
        return;
    }

    // 그렇지 않으면 갱신
    segtree[node] += x;

    // s == e면 끝
    if (s == e) {
        return;
    }

    // 아니면 제귀
    else {
        const int mid = (s + e) / 2;
        update(node * 2, s, mid, i, x);
        update(node * 2 + 1, mid + 1, e, i, x);
    }
}

void print_segtree(const int node, const int s, const int e, const int step) {
    for (int i = 0; i < step; i++) {
        cout << "  ";
    }
    cout << segtree[node];
    cout << "\n";

    if (s == e) {
        return;
    } else {
        const int mid = (s + e) / 2;
        print_segtree(node * 2, s, mid, step + 1);
        print_segtree(node * 2 + 1, mid + 1, e, step + 1);
    }
}

int search_median(const int node, const int s, const int e, const int offset, const int target) {
    if (s == e) {
        return s - 1;
    }

    const int left = node * 2;
    const int right = left + 1;
    const int mid = (s + e) / 2;
    const int left_value = segtree[left];

    if (target <= offset + left_value) {
        return search_median(left, s, mid, offset, target);
    } else {
        return search_median(right, mid + 1, e, offset + left_value, target);
    }
}

long long sol() {
    for (int i = 0; i < k; i++) {
        update(1, 1, SEGTREE_SIZE, temps[i] + 1, 1);
    }

    long long sumation = 0;
    for (int i = 0; i < n - k; i++) {
        // print_segtree(1, 1, SEGTREE_SIZE, 0);
        // cout << "median: " << search_median(1, 1, SEGTREE_SIZE, 0, (k + 1) / 2) << '\n';
        sumation +=  search_median(1, 1, SEGTREE_SIZE, 0, (k + 1) / 2);
        // cout << "--------\n";

        update(1, 1, SEGTREE_SIZE, temps[i] + 1, -1);
        update(1, 1, SEGTREE_SIZE, temps[i + k] + 1, 1);
    }

    // print_segtree(1, 1, SEGTREE_SIZE, 0);
    // cout << "median: " << search_median(1, 1, SEGTREE_SIZE, 0, (k + 1) / 2) << '\n';
    sumation +=  search_median(1, 1, SEGTREE_SIZE, 0, (k + 1) / 2);
    // cout << "--------\n";

    return sumation;
}

int main() {
    cin >> n >> k;
    temps.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> temps[i];
    }
    cout << sol() << '\n';
    return 0;
}
