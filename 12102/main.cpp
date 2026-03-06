#include <iostream>
#include <vector>

using namespace std;

void print_paper(const vector<vector<int>> &paper) {
    const int n = paper.size();
    const int m = paper[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", paper[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

vector<vector<int>> fold_horizotally(const vector<vector<int>> &paper, const int k) {
    const int n = paper.size();
    const int m = paper[0].size();

    const int nn = max(k, n - k);
    const int nm = m;
    vector<vector<int>> new_paper(nn, vector<int>(nm, 0));

    // upper
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            new_paper[i + (nn - k)][j] = paper[i][j];
        }
    }

    // lower
    for (int i = k; i < n; i++) {
        for (int j = 0; j < m; j++) {
            new_paper[nn - (i - k) - 1][j] += paper[i][j];
        }
    }

    return new_paper;
}

vector<vector<int>> fold_vertically(const vector<vector<int>> &paper, const int k) {
    const int n = paper.size();
    const int m = paper[0].size();

    const int nn = n;
    const int nm = max(k, m - k);
    vector<vector<int>> new_paper(nn, vector<int>(nm, 0));

    // left
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            new_paper[i][j + (nm - k)] = paper[i][j];
        }
    }

    // right
    for (int i = 0; i < n; i++) {
        for (int j = k; j < m; j++) {
            new_paper[i][nm - (j - k) - 1] += paper[i][j];
        }
    }

    return new_paper;
}

int find_max(const vector<vector<int>> &paper) {
    int maximum = paper[0][0];

    const int n = paper.size();
    const int m = paper[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maximum = max(maximum, paper[i][j]);
        }
    }

    return maximum;
}

int search(const vector<vector<int>> &paper) {
    int maximum = find_max(paper);

    const int n = paper.size();
    const int m = paper[0].size();

    for (int i = 1; i <= n - 1; i++) {
        vector<vector<int>> new_paper = fold_horizotally(paper, i);

        // print_paper(new_paper);

        maximum = max(maximum, search(new_paper));
    }

    for (int i = 1; i <= m - 1; i++) {
        vector<vector<int>> new_paper = fold_vertically(paper, i);

        // print_paper(new_paper);

        maximum = max(maximum, search(new_paper));
    }

    return maximum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> paper(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    printf("%d\n", search(paper));

    return 0;
}
