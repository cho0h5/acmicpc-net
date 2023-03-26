#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int n;
    int total;
    for(int i = 0; i < 3; i++) {
        total = 0;
        for(int j = 0; j < 4; j++) {
            cin >> n;
            total += n;
        }
        if(total == 0) cout << 'D' << '\n';
        else if(total == 1) cout << 'C' << '\n';
        else if(total == 2) cout << 'B' << '\n';
        else if(total == 3) cout << 'A' << '\n';
        else cout << 'E' << '\n';
    }
}