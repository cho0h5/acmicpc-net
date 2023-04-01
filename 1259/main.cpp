#include <iostream>

using namespace std;

int main() {
    string s;
    while(1) {
	cin >> s;
	if(s.size() == 1 and s[0] == '0') return 0;

	int flag = true;
	for(int i = 0; i <= s.size() / 2; i++) {
	    if(s[i] != s[s.size() - i - 1]) {
		flag = false;
		break;
	    }
	}
	cout << (flag ? "yes" : "no") << '\n';
    }
}
