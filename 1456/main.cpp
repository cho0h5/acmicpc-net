#include <iostream>

#define SIZE_OF_SEIVE 10000000

using namespace std;

int seive[SIZE_OF_SEIVE];
long long a, b;

void make_seive() {
	seive[0] = 1;
	seive[1] = 1;

	for (long long i = 0; i < SIZE_OF_SEIVE; i++) {
		if (seive[i] == 0 && i * 2 < SIZE_OF_SEIVE) {
			for (long long j = i * 2; j < SIZE_OF_SEIVE; j += i) {
				seive[j] = 1;
			}
		}
	}
	
}

long long sol() {
	long long count = 0;

	for (long long i = 0; i < SIZE_OF_SEIVE; i++) {
		if (seive[i] == 0) {
			long long x = i;
			while (true) {
				if (100000000000000 / x < i) break;
				x *= i;
				if (x < a) continue;
				if (x > b) break;
				count += 1;
			}
		}
	}

	return count;
}

int main() {
	make_seive();

	cin >> a >> b;
	cout << sol() << '\n';
}
