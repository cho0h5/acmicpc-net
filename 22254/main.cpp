#include <iostream>
#include <queue>

using namespace std;

int n, x;
int ns[100000];

int sol(const int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push(0);
    }

    for (int i = 0; i < n; i++) {
        const int t = pq.top();
        pq.pop();
        const int t2 = t + ns[i];
        pq.push(t2);
        // printf("%d -> %d\n", t, t2);
        if (t2 > x) {
            return false;
        }
    }

    return true;
}

int minimum = 2147483647;

void binary_search(const int s, const int e) {
    if (s > e) return;
    const int mid = (s + e) >> 1;

    if (!sol(mid)) {   // If failed, increase k
        // printf("%d: fail\n", mid);
        binary_search(mid + 1, e);
    } else {    // If successed, decrease k
        // printf("%d: success\n", mid);
        minimum = min(minimum, mid);
        binary_search(s, mid - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> ns[i];
    }

    binary_search(1, 100000);
    printf("%d\n", minimum);
    return 0;
}
