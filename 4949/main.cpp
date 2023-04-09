#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
	string s;
	getline(cin, s);
	if(s.length() == 1) return 0;

	stack<char> st;
	int flag = 1;
	for(auto c : s) {
	    if(c == '(') st.push(c);
	    if(c == '[') st.push(c);
	    if(c == ')') {
		if(st.empty()) {
		    flag = 0;
		    break;
		}
		else if(st.top() == '(') st.pop();
		else {
		    flag = 0;
		    break;
		}
	    }
	    if(c == ']') {
		if(st.empty()) {
		    flag = 0;
		    break;
		}
		else if(st.top() == '[') st.pop();
		else {
		    flag = 0;
		    break;
		}
	    }
	}

	if(flag && st.empty()) cout << "yes\n";
	else cout << "no\n";
    }
}
