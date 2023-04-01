#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l;
    int n, k;
    list<int>::iterator iter;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
	l.push_back(i);
    }
    iter = l.begin();

    cout << '<';
    while(l.size() != 0) {
	for(int i = 0; i < k - 1; i++) {
	    if(++iter == l.end()) iter = l.begin();
	}
	cout << *iter;
	iter = l.erase(iter);
	if(l.size() != 0) cout << ", ";
	if(iter == l.end()) iter = l.begin();
    }
    cout << '>';
}
