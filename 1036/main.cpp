#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>

using namespace std;

int n, k;
vector<vector<int>> table(36, vector<int>(50, 0));

inline int char2int(const char c) {
    if ('0' <= c && c <= '9') return c - '0';
    return c + 10 - 'A';
}

inline char int2char(const int c) {
    if (0 <= c && c <= 9) return c + '0';
    return c - 10 + 'A';
}

bool cmp(const pair<vector<int>, int> &a, const pair<vector<int>, int> &b) {
    const int a_gap = 35 - a.second;
    const int b_gap = 35 - b.second;

    int as[51];
    int bs[51];
    as[0] = 0;
    bs[0] = 0;
    for (int i = 0; i < 50; i++) {
	as[i] += a.first[i] * a_gap;
	as[i + 1] = as[i] / 36;
	as[i] %= 36;

	bs[i] += b.first[i] * b_gap;
	bs[i + 1] = bs[i] / 36;
	bs[i] %= 36;
    }

    for (int i = 50; i >= 0; i--) {
	if (as[i] == bs[i]) continue;
	else if (as[i] > bs[i]) return true;
	else return false;
    }
    return false;
}

void debug_print() {
    printf("  ");
    for (int j = 49; j >= 0; j--) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < 36; i++) {
        printf("%c ", int2char(i));
        for (int j = 49; j >= 0; j--) {
            if (table[i][j])
                printf("%2d ", table[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < input.size(); j++) {
            table[char2int(input[j])][input.size() - j - 1] += 1;
        }
    }
    cin >> k;

    // debug_print();

    vector<pair<vector<int>, int>> v;
    for (int i = 0; i < 36; i++) {
        v.push_back({table[i], i});
    }
    sort(v.begin(), v.end(), cmp);

//    for (int i = 0; i < 36; i++) {
//        printf("%c ", int2char(v[i].second));
//    }
//    printf("\n");

    for (int i = 0; i < k; i++) {
	const int i_src = v[i].second;
	if (i_src == 35) continue;

	for(int j = 0; j < 50; j++) {
	    table[35][j] += table[i_src][j];
	    table[i_src][j] = 0;
	}
    }

    stack<char> result;
    // sum
    int sumation = 0;
    for (int i = 0; i < 50; i++) {
	for (int j = 0; j < 36; j++) {
	    sumation += j * table[j][i];
	}

	result.push(int2char(sumation % 36));
	sumation /= 36;
    }
    result.push(int2char(sumation % 36));
    sumation /= 36;
    result.push(int2char(sumation % 36));

    bool flag = true;
    while (result.size()) {
	const int c = result.top();
	result.pop();

	if (flag && c == '0' && !result.empty()) {
	    continue;
	}
	flag = false;

	printf("%c", c);
    }
    printf("\n");
}
