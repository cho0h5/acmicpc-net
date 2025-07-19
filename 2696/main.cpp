#include <iostream>
#include <queue>

using namespace std;

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while (t--) {
        priority_queue<int> max_q;
        priority_queue<int, vector<int>, greater<int>> min_q;
        int n;
        cin >> n;
        printf("%d\n", n / 2 + 1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (max_q.empty() || x < max_q.top()) {
                max_q.push(x);
                if (max_q.size() > min_q.size()) {
                    min_q.push(max_q.top());
                    max_q.pop();
                }
            } else if (min_q.empty() || x < min_q.top()) {
                if (max_q.size() <= min_q.size()) {
                    max_q.push(x);
                } else {
                    min_q.push(x);
                }
            } else {
                min_q.push(x);
                if (max_q.size() < min_q.size()) {
                    max_q.push(min_q.top());
                    min_q.pop();
                }
            }

            if (i % 2 == 0) {
                // printf("(%d, %d)", max_q.top(), min_q.top());
                // printf("(%ld, %ld)", max_q.size(), min_q.size());
                if (min_q.size() < max_q.size()) {
                    printf("%d ", max_q.top());
                } else {
                    printf("%d ", min_q.top());
                }
            }
            if (i % 20 == 18 && i != 0) {
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
