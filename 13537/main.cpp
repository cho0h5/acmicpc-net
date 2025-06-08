#include <iostream>

#define MAXIMUM 1000000000

using namespace std;

// stuructures

struct Node {
    int state;
    Node *children[4];
};

// global variables

Node nodes[12000000];
int nodes_len;

int n, m;
Node *root;

// helper functions

Node *nodes_new() {
    const int i = nodes_len++;
    return &nodes[i];
}

void set(Node *node, int x_s, int x_e, int y_s, int y_e, int i, int j) {
    if (i < x_s || x_e < i || j < y_s || y_e < j) {
        return;
    }

    node->state += 1;

    if (y_s == y_e) {
        return;
    }

    if (node->children[0] == NULL) {
        for (int i = 0; i < 4; i++) {
            node->children[i] = nodes_new();
        }
    }

    const int x_mid = (x_s + x_e) >> 1;
    const int y_mid = (y_s + y_e) >> 1;
    set(node->children[0], x_s, x_mid,      y_s, y_mid,     i, j);
    set(node->children[1], x_mid + 1, x_e,  y_s, y_mid,     i, j);
    set(node->children[2], x_s, x_mid,      y_mid + 1, y_e, i, j);
    set(node->children[3], x_mid + 1, x_e,  y_mid + 1, y_e, i, j);
}

int get(Node *node, int x_s, int x_e, int y_s, int y_e, int x_i, int x_j, int y_i, int y_j) {
    if (x_j < x_s || x_e < x_i || y_j < y_s || y_e < y_i) {
        return 0;
    }

    if (x_i <= x_s && x_e <= x_j && y_i <= y_s && y_e <= y_j) {
        return node->state;
    }

    if (node->children[0] == NULL) {
        return 0;
    }

    const int x_mid = (x_s + x_e) >> 1;
    const int y_mid = (y_s + y_e) >> 1;
    int sumation = 0;
    sumation += get(node->children[0], x_s, x_mid,      y_s, y_mid,     x_i, x_j, y_i, y_j);
    sumation += get(node->children[1], x_mid + 1, x_e,  y_s, y_mid,     x_i, x_j, y_i, y_j);
    sumation += get(node->children[2], x_s, x_mid,      y_mid + 1, y_e, x_i, x_j, y_i, y_j);
    sumation += get(node->children[3], x_mid + 1, x_e,  y_mid + 1, y_e, x_i, x_j, y_i, y_j);
    return sumation;
}

void print(Node *node, int x_s, int x_e, int y_s, int y_e, int step) {
    for (int i = 0; i < step; i++) {
        cout << "  ";
    }
    cout << node->state << " (" << x_s << ", " << x_e << ", " << y_s << ", " << y_e << ")\n";

    if (node->children[0] == NULL) {
        return;
    }

    const int x_mid = (x_s + x_e) >> 1;
    const int y_mid = (y_s + y_e) >> 1;
    print(node->children[0], x_s, x_mid,      y_s, y_mid,     step + 1);
    print(node->children[1], x_mid + 1, x_e,  y_s, y_mid,     step + 1);
    print(node->children[2], x_s, x_mid,      y_mid + 1, y_e, step + 1);
    print(node->children[3], x_mid + 1, x_e,  y_mid + 1, y_e, step + 1);
}

// main

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    root = nodes_new();
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        set(root, 1, n, 1, MAXIMUM, i, a);
    }

    // print(root, 1, n, 1, MAXIMUM, 0);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << get(root, 1, n, 1, MAXIMUM, a, b, c + 1, MAXIMUM) << '\n';
    }
}
