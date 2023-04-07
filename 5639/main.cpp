#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> tree;

void insert(int index, int x) {
    if(tree[index] == 0) {
	tree[index] = x;
	return;
    }
    if(tree[index] > x) insert(index * 2 + 1, x);
    if(tree[index] < x) insert(index * 2 + 2, x);
}

void print(int index) {
    if(tree[index] == 0) return;
    print(index * 2 + 1);
    print(index * 2 + 2);
    cout << tree[index] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(!cin.eof()) {
	int input;
	cin >> input;
	insert(0, input);
    }

//    cout << "[debug tree]\n";
//    for(int i = 0; i < 15; i++) cout << tree[i] << ' ';
//    cout << '\n';

    print(0);
}
