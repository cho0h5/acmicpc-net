#include <iostream>
#include <stack>

using namespace std;

int main() {
    int count = 0;
    int n;
    cin >> n;
    char cs[100001];
    while(n--) {
        cin >> cs;
        int i = 0;
        stack<char> s;
        while (cs[i] != 0) {
            if (s.empty() || s.top() != cs[i]) {
                s.push(cs[i]);
                i++;
                continue ;
            }
            s.pop();
            i++;
        }
        if (s.empty()) {
            count++;
        }
    }
    cout << count << '\n';
}
