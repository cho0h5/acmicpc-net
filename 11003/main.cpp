#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> dq;
    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
        if (dq.size() > l) {
            dq.pop_front();
        }
    }
}
