#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    stack<pair<int, int> > s;
    int n;
    int h;
    s.push(make_pair(100000000, 0));

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> h;

        while (s.top().first < h) {
            s.pop();
        }
        cout << s.top().second << ' ';
        s.push(make_pair(h, i));
    }
}
