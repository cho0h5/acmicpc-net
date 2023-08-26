#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    queue<int> dq;
    priority_queue<int> mq;
    priority_queue<int> sq;

    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push(x);
        mq.push(-x);
        if (dq.size() > l) {
            int target = dq.front();
            dq.pop();
            if (mq.top() == -target) {
                mq.pop();
                while (!sq.empty() && mq.top() == sq.top()) {
                    mq.pop();
                    sq.pop();
                }
            } else {
                sq.push(-target);
            }
        }
        cout << -mq.top() << ' ';
    }
    cout << '\n';
}
