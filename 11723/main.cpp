#include <iostream>
#include <unordered_set>

using namespace std;

int s[21];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while(t--) {
	string st;
	int n;
	cin >> st;
	switch(st[1]) {
	    case 'd':
		cin >> n;
		s[n] = 1;
		break;
	    case 'e':
		cin >> n;
		s[n] = 0;
		break;
	    case 'h':
		cin >> n;
		cout << s[n] << '\n';
		break;
	    case 'o':
		cin >> n;
		s[n] = 1 - s[n];
		break;
	    case 'l':
		for(int i = 1; i <= 20; i++) s[i] = 1;
		break;
	    case 'm':
		for(int i = 1; i <= 20; i++) s[i] = 0;
		break;
	}
    }
}
