#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    long long main_sum = 0;

    int n;
    int temp[80000];
    stack<pair<int, long long> > s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    for(int i = n - 1; i >= 0; i--) {
        if (s.empty()) {
            s.push(make_pair(temp[i], 0));
            continue ;
        }

        long long sum = 0;
        while (!s.empty() && s.top().first < temp[i]) {
            main_sum += s.top().second;
            sum += s.top().second + 1;
            s.pop();
        }
        s.push(make_pair(temp[i], sum));
    }
    while (!s.empty()) {
            main_sum += s.top().second;
            s.pop();
    }
    cout << main_sum << '\n';
}
