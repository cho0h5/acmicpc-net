#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    stack<pair<long long, int> > s;
    int n;

    int result[500000];

    cin >> n;
    for(int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        result[i] = 0;
        long long se = 1;

        while (!s.empty() && s.top().first <= num) {
            result[i] += s.top().second;
            if (s.top().first == num) {
                se += s.top().second;
            }
            s.pop();
        }

        if (s.empty()) {
            s.push(make_pair(num, se));
            continue;
        }

        result[i]++;
        s.push(make_pair(num, se));
    }

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        // cout << result[i] << ' ';
        sum += result[i];
    }
    // cout << '\n';
    cout << sum;
    cout << '\n';
}
