#include <iostream>
#include <stack>

using namespace std;

int main() {
    char cs[100001];
    cin >> cs;
    int i = 0;
    stack<char> s;
    int isLazer = 0;
    int count = 0;
    while (cs[i] != 0) {
        if (cs[i] == '(') {
            s.push('(');
            isLazer = 1;
        } else {
            if (isLazer) {
                s.pop();
                // cout << s.size() << ' ';
                count += s.size();
            } else {
                s.pop();
                // cout << 1 << ' ';
                count++;
            }
            isLazer = 0;
        }
        i++;
    }
    // cout << '\n';
    cout << count << '\n';
}
