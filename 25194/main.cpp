#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n;
vector<int> as;

bool sol() {
    unordered_set<int> s;
    s.insert(0);

    for (int i = 0; i < n; i++) {
        vector<int> t;
        for (auto &it: s) {
            const int a = it + as[i];
            if (a % 7 == 4) {
                return true;
            }
            t.push_back(a);
        }

        for (auto &it: t) {
            s.insert(it);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    as.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    bool result = sol();
    if (result) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
