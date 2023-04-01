#include <iostream>
#include <list>

using namespace std;

int main() {
    // initialize
    list<char> chars;
    string str;
    list<char>::iterator cursor;
    int t;
    cin >> t;

    // solution
    while(t--) {
	chars.clear();
	cin >> str;
	cursor = chars.end();
	for(auto c : str) {
	    switch(c) {
		case '<':
		    if(cursor != chars.begin()) cursor--;
		    break;
		case '>':
		    if(cursor != chars.end()) cursor++;
		    break;
		case '-':
		    if(cursor != chars.begin()) cursor = chars.erase(--cursor);
		    break;
		default:
		    chars.insert(cursor, c);
		    break;
	    }
	}

	for(auto c: chars) cout << c;
	cout << '\n';
    }
}
