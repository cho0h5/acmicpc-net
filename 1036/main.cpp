#include <iostream>
#include <vector>
#include <utility>

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

void debug_print() {
    printf("  ");
    for (int j = 0; j < 50; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < 36; i++) {
        printf("%c ", int2char(i));
        for (int j = 0; j < 50; j++) {
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
            table[49 - char2int(input[j])][j] += 1;
        }
    }
    cin >> k;

    debug_print();

    vector<pair<vector<int>, int>> v;
    for (int i = 0; i < 36; i++) {
        v.push_back({table[i], i});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < 36; i++) {
        printf("%c ", int2char(v[i].second));
    }
    printf("\n");
}
