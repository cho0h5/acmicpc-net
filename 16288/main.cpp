#include <iostream>
#include <unordered_map>

using namespace std;

int N, K;
unordered_map<int, int> NS;

bool solve() {
    for (int i = 0; i < K; i++) {
        int min_val = 99999;
        int min_pos;
        for (auto &kv: NS) {
            if (kv.first < min_val) {
                min_val = kv.first;
                min_pos = kv.second;
            }
        }

        // cout << "min_val: " << min_val << '\n';
        // cout << "min_pos: " << min_pos << '\n';

        for (int j = min_val; j <= N; j++) {
            if (NS[j] >= min_pos) {
                NS.erase(j);
            }
        }

        // cout << "size: " << NS.size() << '\n';
        if (NS.size() == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int val, pos;
        cin >> val;
        pos = i + 1;

        NS[val] = pos;
    }

    if (solve()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
