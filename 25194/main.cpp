#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> as;

bool sol() {
    bool s[7];
    for (int i = 0; i < 7; i++) {
        s[i] = false;
    }
    s[0] = true;

    for (int i = 0; i < n; i++) {
        vector<int> t;
        for (int j = 0; j < 7; j++) {
            if (!s[j]) {
                continue;
            }
            const int a = (j + as[i]) % 7;
            if (a == 4) {
                return true;
            }
            t.push_back(a);
        }

        for (auto &it: t) {
            s[it] = true;
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
