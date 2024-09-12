#include <iostream>

using namespace std;

string input;

int get(int i) {
	if (i >= input.size()) return -1;

	if (input[i] == '0') return 0;
	else return 1;
}

bool sol() {
	int i = 0;
	int state = 0;

	while (1) {
		switch (state) {
			case 0:
				if (get(i) == 1) {
					state = 1;
					i += 1;
				} else if (get(i) == 0) {
					state = 5;
					i += 1;
				} else if (i == input.size()) {
					return 1;
				} else {
					cout << "noway\n";
				}
				break;
			case 1:
				if (get(i) == 0) {
					state = 2;
					i += 1;
				} else {
					return 0;
				}
				break;
			case 2:
				if (get(i) == 0) {
					state = 3;
					i += 1;
				} else {
					return 0;
				}
				break;
			case 3:
				if (get(i) == 0) {
					i += 1;
				} else if (get(i) == 1) {
					state = 4;
					i += 1;
				} else {
					return 0;
				}
				break;
			case 4:
				if (get(i) == 0) {
					state = 5;
					i += 1;
				} else if (get(i) == 1) {
					if (get(i + 1) == 0 && get(i + 2) == 0) {
						state = 1;
						i += 1;
					} else {
						i += 1;
					}
				} else {
					return 1;
				}
				break;
			case 5:
				if (get(i) == 1) {
					state = 0;
					i += 1;
				} else {
					return 0;
				}
				break;
		}
	}

}

int main() {
	cin >> input;

	if (sol()) {
		cout << "SUBMARINE\n";
	} else {
		cout << "NOISE\n";
	}

}
