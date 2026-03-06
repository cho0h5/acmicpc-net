#include <iostream>

using namespace std;

void print_paper(int paper[][6], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", paper[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void fold_horizotally(int paper[][6], int n, int m, int k, int new_paper[][6], int &nn, int &nm) {
    nn = max(k, n - k);
    nm = m;

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
}

void fold_vertically(int paper[][6], int n, int m, int k, int new_paper[][6], int &nn, int &nm) {
    nn = n;
    nm = max(k, m - k);

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
}

int find_max(int paper[][6], int n, int m) {
    int maximum = paper[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maximum = max(maximum, paper[i][j]);
        }
    }

    return maximum;
}

int search(int paper[][6], int n, int m) {
    int maximum = find_max(paper, n, m);

    for (int i = 1; i <= n - 1; i++) {
        int new_paper[6][6] = {};
        int nn, nm;
        fold_horizotally(paper, n, m, i, new_paper, nn, nm);

        // print_paper(new_paper, nn, nm);

        maximum = max(maximum, search(new_paper, nn, nm));
    }

    for (int i = 1; i <= m - 1; i++) {
        int new_paper[6][6] = {};
        int nn, nm;
        fold_vertically(paper, n, m, i, new_paper, nn, nm);

        // print_paper(new_paper, nn, nm);

        maximum = max(maximum, search(new_paper, nn, nm));
    }

    return maximum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int paper[6][6] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    printf("%d\n", search(paper, n, m));

    return 0;
}
