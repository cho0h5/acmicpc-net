#include <iostream>

using namespace std;

string paper[4];

int get(const int i_start, const int j_start,
        const int i_end, const int j_end) {
    const int i_size = i_end - i_start;
    const int j_size = j_end - j_start;

    if (i_size >= 2) {
        int temp_cost = 0;
        for (int i = i_start; i < i_end; i++) {
            temp_cost += paper[i][j_start] - '0';
            if (i != i_end - 1) {
                temp_cost *= 10;
            }
        }
        return temp_cost;
    } else {
        int temp_cost = 0;
        for (int j = j_start; j < j_end; j++) {
            temp_cost += paper[i_start][j] - '0';
            if (j != j_end - 1) {
                temp_cost *= 10;
            }
        }
        return temp_cost;
    }
}

int dfs(const int i_start, const int j_start,
        const int i_end, const int j_end) {
    const int i_size = i_end - i_start;
    const int j_size = j_end - j_start;
    if (i_size <= 0 || j_size <= 0) {
        return 0;
    }

    int max_cost = 0;
    for (int i = 0; i < i_size; i++) {
        int temp_cost = 0;
        temp_cost += dfs(i_start, j_start, i_start + i, j_end);
        temp_cost += get(i_start + i, j_start, i_start + i + 1, j_end);
        temp_cost += dfs(i_start + i + 1, j_start, i_end, j_end);
        max_cost = max(max_cost, temp_cost);
        // cout << "temp_cost: " << temp_cost << '\n';
    }
    for (int j = 0; j < j_size; j++) {
        int temp_cost = 0;
        temp_cost += dfs(i_start, j_start, i_end, j_start + j);
        temp_cost += get(i_start, j_start + j, i_end, j_start + j + 1);
        temp_cost += dfs(i_start, j_start + j + 1, i_end, j_end);
        max_cost = max(max_cost, temp_cost);
        // cout << "temp_cost: " << temp_cost << '\n';
    }
    return max_cost;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> paper[i];
    }

    cout << dfs(0, 0, n, m) << '\n';
}
