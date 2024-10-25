#include <iostream>

using namespace std;

long long magic[1000][1000];
int n, k;

void init() {
    for (int j = 0; j < n - k * 2 + 1; j++) {
        magic[0][j] = 1;
    }
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < n - k * 2 + 1; j++) {
            if (j == 0) {
                magic[i][j] = 1;
            } else {
                magic[i][j] = (magic[i - 1][j] + magic[i][j - 1]) % 1000000003;
            }
        }
    }
}

void print_magic() {
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < n - k * 2 + 1; j++) {
            cout << magic[i][j] << ' ';
        }
        cout << '\n';
    }
}

int sol() {
    long long answer = 0;
    const int i = k - 1;
    int j = n - k * 2;
    answer += magic[i][j];
    answer %= 1000000003;
    for (;j >= 0; j--) {
        answer += magic[i][j];
        answer %= 1000000003;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	init();
	// print_magic();
	cout << sol() << '\n';
}
