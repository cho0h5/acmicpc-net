#include <iostream>

using namespace std;

int ns[10];

int main() {
    int n;
    int t;
    cin >> n;
    if (n == 0) {
        ns[0]++;
    }
    while(n > 0) {
        ns[n % 10]++;
        n /= 10;
    }

    t = ns[6] + ns[9] + 1;
    ns[6] = t / 2;
    ns[9] = t / 2;

    int max = ns[0];
    for(int e : ns) {
        if (max < e) {
            max = e;
        }
    }
    cout << max << '\n';
}
