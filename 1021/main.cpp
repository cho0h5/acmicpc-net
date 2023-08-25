#include <iostream>
#include <deque>

using namespace std;

int search(deque<int>& dq, int key) {
    for(int i = 0; i < dq.size(); i++) {
        if (dq[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, m;
    deque<int> dq;
    cin >> n >> m;
    int sum = 0;

    for(int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    for(int i = 0; i < m; i++) {
        int index;
        cin >> index;

        int which = search(dq, index);

        if (which <= dq.size() / 2) {
            sum += which;
            for(int j = 0; j < which; j++) {
                int temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
        } else {
            sum += dq.size() - which;
            for(int j = 0; j < dq.size() - which; j++) {
                int temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }
        }

        dq.pop_front();
    }
    cout << sum << '\n';
}
