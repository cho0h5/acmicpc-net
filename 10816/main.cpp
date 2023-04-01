#include <iostream>

using namespace std;

int m[20000010];
int n;
int card;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while(n--) {
	cin >> card;
	m[card+10000005]++;
    }
    cin >> n;
    while(n--) {
	cin >> card;
	cout << m[card+10000005] << ' ';
    }
}
