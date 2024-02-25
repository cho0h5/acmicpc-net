#include <deque>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void process(vector<string> instruction, deque<long long> parameter, stack<long long> s) {
	for (auto it = instruction.begin(); it != instruction.end(); it++) {
		if (*it == "NUM") {
			s.push(parameter.front());	parameter.pop_front();
		} else if (*it == "POP") {
			if (s.size() < 1)
			{
				cout << "ERROR\n";
				return;
			}
			s.pop();
		} else if (*it == "INV") {
			if (s.size() < 1)
			{
				cout << "ERROR\n";
				return;
			}
			long long x = s.top(); s.pop();
			s.push(-x);
		} else if (*it == "DUP") {
			if (s.size() < 1)
			{
				cout << "ERROR\n";
				return;
			}
			s.push(s.top());
		} else if (*it == "SWP") {
			if (s.size() < 2)
			{
				cout << "ERROR\n";
				return;
			}
			long long x1 = s.top(); s.pop();
			long long x2 = s.top(); s.pop();
			s.push(x1);
			s.push(x2);
		} else if (*it == "ADD") {
			if (s.size() < 2)
			{
				cout << "ERROR\n";
				return;
			}
			long long x1 = s.top(); s.pop();
			long long x2 = s.top(); s.pop();
			if (llabs(x2 + x1) > 1000000000)
			{
				cout << "ERROR\n";
				return;
			}
			s.push(x2 + x1);
		} else if (*it == "SUB") {
			if (s.size() < 2)
			{
				cout << "ERROR\n";
				return;
			}
			long long x1 = s.top(); s.pop();
			long long x2 = s.top(); s.pop();
			if (llabs(x2 - x1) > 1000000000)
			{
				cout << "ERROR\n";
				return;
			}
			s.push(x2 - x1);
		} else if (*it == "MUL") {
			if (s.size() < 2)
			{
				cout << "ERROR\n";
				return;
			}
			long long x1 = s.top(); s.pop();
			long long x2 = s.top(); s.pop();
			if (llabs(x2 * x1) > 1000000000)
			{
				cout << "ERROR\n";
				return;
			}
			s.push(x2 * x1);
		} else if (*it == "DIV") {
			if (s.size() < 2)
			{
				cout << "ERROR\n";
				return;
			}
			long long x1 = s.top(); s.pop();
			long long x2 = s.top(); s.pop();
			if (x1 == 0)
			{
				cout << "ERROR\n";
				return;
			}
			long long res = llabs(x2) / llabs(x1);
			if (res > 1000000000)
			{
				cout << "ERROR\n";
				return;
			}
			if (x2 * x1 < 0)
				s.push(-res);
			else
				s.push(res);
		} else if (*it == "MOD") {
			if (s.size() < 2)
			{
				cout << "ERROR\n";
				return;
			}
			long long x1 = s.top(); s.pop();
			long long x2 = s.top(); s.pop();
			if (x1 == 0)
			{
				cout << "ERROR\n";
				return;
			}
			long long res = llabs(x2) % llabs(x1);
			if (res > 1000000000)
			{
				cout << "ERROR\n";
				return;
			}
			if (x2 < 0)
				s.push(-res);
			else
				s.push(res);
		}
	}
	if (s.size() != 1) {
		cout << "ERROR\n";
	} else {
		cout << s.top() << '\n';
	}
}

int main() {
	fastio();

	while (1) {
		vector<string> instruction;
		deque<long long> parameter;

		string line;
		cin >> line;
		if (line == "QUIT")
			return 0;
		while (1) {
			if (line == "END")
				break;
			else if (line == "NUM") {
				long long param;
				cin >> param;
				parameter.push_back(param);
			}
			instruction.push_back(line);
			cin >> line;
		}
		int n;
		cin >> n;
		while (n--) {
			stack<long long> s;
			int x;
			cin >> x;
			s.push(x);
			process(instruction, parameter, s);
		}
		cout << '\n';
	}
}
