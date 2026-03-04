#include <iostream>

using namespace std;

int n, m;

inline void print(int i) {
    if ((m & 1) == 0 && ((i / m) % 2) == 1) i -= 1;

    cout << "? " << (i / m + 1) << " " << (i % m + 1) << '\n';
    cout << flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    const int total = n * m;


    for (int i = 1; i <= total; i += 2) {
        print(i);

        int answer;
        cin >> answer;
        if (answer) break;
    }
}
