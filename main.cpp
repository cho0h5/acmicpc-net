#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int notebook[40][40];
int sticker[10][10];
int n, m, k;
int r, c;

void print_sticker1() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << sticker[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_sticker2() {
	for (int i = 0; i < c; i++) {
		for (int j = r - 1; j >= 0; j--) {
			cout << sticker[j][i] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_sticker3() {
	for (int i = r - 1; i >= 0; i--) {
		for (int j = c - 1; j >= 0; j--) {
			cout << sticker[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_sticker4() {
	for (int i = c - 1; i >= 0; i--) {
		for (int j = 0; j < r; j++) {
			cout << sticker[j][i] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	fastio();

	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
			}
		}
		print_sticker1();
		print_sticker2();
		print_sticker3();
		print_sticker4();
	}
}
