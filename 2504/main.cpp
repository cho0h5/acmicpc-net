#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> s;
    char cs[31];
    cin >> cs;

    for (int i = 0; cs[i]; i++) {
        if (cs[i] == '(') {
            s.push_back(-1);
            continue ;
        }
        if (cs[i] == '[') {
            s.push_back(-2);
            continue ;
        }
        if (cs[i] == ')') {
            if (s.empty()) {
                s.push_back(-3);
                break ;
            }
            if (s.back() == -1) {
                s.pop_back();
                s.push_back(2);
            } else if (s.back() == -2) {
                s.push_back(-3);
                break ;
            } else {
                int tmp = s.back() * 2;
                s.pop_back();
                if (s.empty()) {
                    s.push_back(-3);
                    break ;
                }
                if (s.back() == -1) {
                    s.pop_back();
                } else {
                    tmp += s.back();
                    s.pop_back();
                    s.pop_back();
                }
                s.push_back(tmp);
            }
        }
        if (cs[i] == ']') {
            if (s.empty()) {
                s.push_back(-1);
                break ;
            }
            if (s.back() == -2) {
                s.pop_back();
                s.push_back(3);
            } else if (s.back() == -1) {
                s.push_back(-3);
                break ;
            } else {
                int tmp = s.back() * 3;
                s.pop_back();
                if (s.empty()) {
                    s.push_back(-3);
                    break ;
                }
                if (s.back() == -2) {
                    s.pop_back();
                } else {
                    tmp += s.back();
                    s.pop_back();
                    s.pop_back();
                }
                s.push_back(tmp);
            }
        }
        if (!s.empty() && s.back() != -1 && s.back() != -2) {
            int tmp = s.back();
            s.pop_back();
            if (!s.empty() && s.back() != -1 && s.back() != -2) {
                tmp += s.back();
                s.pop_back();
            }
            s.push_back(tmp);
        }
//        for (int i = 0; i < s.size(); i++) {
//            cout << s[i] << ' ';
//        }
//        cout << '\n';
    }
//    for (int i = 0; i < s.size(); i++) {
//        cout << s[i] << ' ';
//    }
//    cout << '\n';
    if (s.back() < 0 || s.size() != 1) {
        cout << 0 << '\n';
    } else {
        cout << s.back() << '\n';
    }
}
