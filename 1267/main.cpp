#include <iostream>

using namespace std;

int main() {
    int n;
    int time;
    int Y = 0;
    int M = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> time;

        Y += ((int)(time / 30) + 1) * 10;
        M += ((int)(time / 60) + 1) * 15;
    }
    if (Y == M) {
        cout << "Y M " << Y << '\n';
    } else if (Y < M) {
        cout << "Y " << Y << '\n';
    } else {
        cout << "M " << M << '\n';
    }
}
