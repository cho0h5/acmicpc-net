#include <iostream>
#include <list>

using namespace std;

int main() {
    // initialize
    list<char> chars;
    string str;
    list<char>::iterator cursor;
    int t;

    // solution
    cin >> str;
    for(auto c : str) chars.push_back(c);
    cursor = chars.end();
    cin >> t;
    while(t--) {
	char command;
	cin >> command;

	switch(command) {
	    case 'L':
		if(cursor != chars.begin()) cursor--;
		break;
	    case 'D':
		if(cursor != chars.end()) cursor++;
		break;
	    case 'B':
		if(cursor != chars.begin()) cursor = chars.erase(--cursor);
		break;
	    case 'P':
		char arg;
		cin >> arg;
		chars.insert(cursor, arg);
		break;
	}
    }

    // output
    for(auto c : chars) cout << c;
}
