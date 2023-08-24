#include <iostream>

using namespace std;

int ns[2][6];
int main() {
    int count = 0;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int gen, gra;
        cin >> gen >> gra;
        ns[gen][gra-1]++;
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 6; j++) {
            count += (ns[i][j] + k - 1) / k;
        }
    }
    cout << count << '\n';
}
