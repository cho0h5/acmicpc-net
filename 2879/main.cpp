#include <iostream>

using namespace std;

int n;
int arr[1001];
int total_count = 0;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		arr[i] = x - arr[i];
	}

//	for (int i = 0; i <= n; i++) {
//		cout << arr[i] << ' ';
//	}
//	cout << '\n';

	for (int i = 1; i <= n; i++) {
		if (arr[i - 1] * arr[i] <= 0) {
			total_count += abs(arr[i]);
		} else {
			if (abs(arr[i - 1]) < abs(arr[i])) {
				total_count += abs(arr[i]) - abs(arr[i - 1]);
			}
		}
	}
	cout << total_count << '\n';
}
