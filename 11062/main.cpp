#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector<int> ns;
int i, j;

int ns_size() {
    return j - i + 1;
}

char which_is_better() {
    if (ns_size() <= 2) {
        const int l = ns[i];
        const int r = ns[j];

        if (l > r) {
            return 'l';
        } else {
            return 'r';
        }
    } else {
        int l = ns[i];
        if (ns[i + 1] >= ns[j]) {
            l += max(ns[i + 2], ns[j]);
        } else {
            l += max(ns[i + 1], ns[j - 1]);
        }

        int r = ns[j];
        if (ns[i] >= ns[j - 1]) {
            r += max(ns[i + 1], ns[j - 1]);
        } else {
            r += max(ns[i], ns[j - 2]);
        }

        // cout << l << ' ' << r << '\n';
        if (l == r) {
            // cout << ns[i] << ' ' << ns[j] << '\n';
            if (ns[i] >= ns[j]) {
                return 'l';
            } else {
                return 'r';
            }
        } else if (l > r) {
            return 'l';
        } else {
            return 'r';
        }
    }
}

int sol() {
    int sum_g = 0;
    char turn = 'g';
    while (ns_size()) {
        const char which = which_is_better();

        if (turn == 'g') {
            if (which == 'l') {
                // cout << "debug_g: " << ns[i] << '\n';
                sum_g += ns[i];
            } else {
                // cout << "debug_g: " << ns[j] << '\n';
                sum_g += ns[j];
            }
            turn = 'm';
        } else {
            // cout << "debug_m: " << ns[j] << '\n';
            turn = 'g';
        }

        if (which == 'l') {
            i += 1;
        } else {
            j -= 1;
        }
        // cout << ns_size() << '\n';
    }
    return sum_g;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> t;
    for (int I = 0; I < t; I++) {
        cin >> n;
        i = 0;
        j = n - 1;
        ns.assign(n, 0);
        for (int J = 0; J < n; J++) {
            cin >> ns[J];
        }
        cout << sol() << '\n';
    }
}
