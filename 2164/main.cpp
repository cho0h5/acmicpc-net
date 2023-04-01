#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) l.push_back(i);

    while(l.size() > 1) {
	l.pop_front();
	l.push_back(l.front());
	l.pop_front();
    }
    cout << l.front();
}
