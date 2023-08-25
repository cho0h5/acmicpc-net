#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    stack<int> s;
    int temp[1000000];
    int result[1000000];
    int n;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    for(int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= temp[i]) {
            s.pop();
        }

        if (s.empty()) {
            result[i] = -1;
            s.push(temp[i]);
            continue ;
        }

        result[i] = s.top();
        s.push(temp[i]);
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
}
