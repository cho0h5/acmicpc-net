#include <iostream>

using namespace std;

int N, M;
int series[8];

void print(int start, int end, int cursor, int m) {
    // escape
    if(end < start) return;
    if(m == 1) {
	for(int i = start; i <= end; i++) {
	    series[cursor] = i;
	    for(int i = 0; i <= cursor; i++)
		cout << series[i] << ' ';
	    cout << '\n';
	}
	return;
    }

    // include start
    series[cursor] = start;
    print(start+1, end, cursor+1, m-1);

    // include no start
    print(start+1, end, cursor, m);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    print(1, N, 0, M);
}
