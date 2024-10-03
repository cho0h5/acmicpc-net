#include <iostream>

using namespace std;

int table[11][10];
int count_table[11][10];

void init_table() {
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		table[1][i] = 1;
		sum += table[1][i];
		count_table[1][i] = sum;
	}

	for (int j = 2; j <= 10; j++) {
		for (int i = 1; i < 10; i++) {
			table[j][i] = table[j][i - 1] + table[j - 1][i - 1];
			if (table[j][i] != 0) {
				sum += table[j][i];
				count_table[j][i] = sum;
			}
		}
	}
}

void print_table() {
	for (int j = 1; j <= 10; j++) {
		for (int i = 0; i < 10; i++) {
			cout << table[j][i] << '\t';
		}
		cout << '\n';
	}
}


void print_count() {
	for (int j = 1; j <= 10; j++) {
		for (int i = 0; i < 10; i++) {
			cout << count_table[j][i] << '\t';
		}
		cout << '\n';
	}
}

long long subsol(long long digit, long long &n) {
	long long prev = 0;
	long long second_digit = -1;
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += table[digit][i];
		if (n > sum) {
			prev = sum;
			continue;
		} else {
			// cout << "prev: " << prev << '\n';
			n -= prev;
			second_digit = i;
			break;
		}
	}
	return second_digit;
}

long long sol(long long n) {
	long long prev = 0;
	long long flag = false;
	long long digit = -1;
	long long first_digit = -1;

	for (int j = 1; j <= 10; j++) {
		if (flag) break;
		for (int i = 0; i < 10; i++) {
			if (n > count_table[j][i]) {
				prev = count_table[j][i];
				continue;
			} else {
				flag = true;
				digit = j;
				first_digit = i;
				break;
			}
		}
	}
	if (digit == -1) return -1;

	long long answer = first_digit;
	// cout << "first_digit: " << first_digit << '\n';
	if (prev != 0)
		n -= prev;
	else
		n = 1;
	while (--digit) {
		// cout << "n: " << n << '\n';
		long long a = subsol(digit, n);
	// cout << "second_digit: " << a << '\n';
		answer *= 10;
		answer += a;
	}
	// cout << n << '\n';
	return answer;
}

int main() {
	long long n;
	cin >> n;
	init_table();
//	print_table();
//	cout << '\n';
//	print_count();
	
//	for (int i = 1; i <= 1024; i++) {
//		cout << i << ": " << sol(i) << '\n';
//	}

	cout << sol(n) << '\n';
}
