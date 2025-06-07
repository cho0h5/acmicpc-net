#include <iostream>
#include <map>

using namespace std;

map<int, int> m;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        m[s] += 1;
        m[e] -= 1;
    }

    // for (auto &it: m) {
        // cout << it.first << ' ' << it.second << '\n';
    // }

    int max_state = -1;
    int max_start = -1;
    int max_end = -1;

    int state = 0;
    int start = 0;
    int end = -1;
    for (auto &it: m) {
        if (it.second == 0) {
            continue;
        }
        const int prev_state = state;
        state += it.second;

        // cout << state << '\n';

        if (it.second > 0) {
            start = it.first;
        } else {
            end = it.first;

            // cout << prev_state << ' ' << max_start << '\n';
            if (prev_state > max_state) {
                max_state = prev_state;
                max_start = start;
                max_end = end;
            }

            end = -1;
        }
    }

    cout << max_state << '\n';
    cout << max_start << ' ';
    cout << max_end << '\n';
}
