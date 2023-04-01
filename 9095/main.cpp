#include <iostream>

using namespace std;

int tmp[20];
int solution(int n) {
    if(tmp[n] == 0) tmp[n] = solution(n-1) + solution(n-2) + solution(n-3);
    return tmp[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    tmp[1] = 1;
    tmp[2] = 2;
    tmp[3] = 4;

    int t;
    cin >> t;

    while(t--) {
	int n;
	cin >> n;
	cout << solution(n) << '\n';
    }
}
