#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int page;

    int depth;
    int sum;

    int parent;
    vector<int> children;
};

int n, m;
Node nodes[1001];

vector<int> roots;
vector<int> leaves;

void init_node(const int n) {
    for (auto child: nodes[n].children) {
        const int p = nodes[child].parent;
        nodes[child].depth = nodes[p].depth + 1;
        nodes[child].sum = nodes[p].sum + nodes[child].page;
        
        init_node(child);
    }
}

void init() {
    for (auto root: roots) {
        nodes[root].depth = 0;
        nodes[root].sum = nodes[root].page;

        init_node(root);
    }
}

void print_debug() {
    for (int i = 1; i <= n; i++) {
        // printf("i: %d, depth: %d, sum: %d\n",
                // i,
                // nodes[i].depth,
                // nodes[i].sum);
    }
}

int find_common_parent(int a, int b) {
    while (true) {
        if (a == b) return a;

        if (nodes[a].depth > nodes[b].depth) a = nodes[a].parent;
        else if (nodes[a].depth < nodes[b].depth) b = nodes[b].parent;
        else a = nodes[a].parent, b = nodes[b].parent;

        if (a == 0 || b == 0) return 0;
    }
}

int calculate(const int a, const int b) {
    const int common_parent = find_common_parent(a, b);

    if (!common_parent) {
        return nodes[a].sum + nodes[b].sum;
    } else {
        return nodes[a].sum + nodes[b].sum - nodes[common_parent].sum;
    }
}

int bf() {
    int minimal = 2147483647;
    for (int i = 0; i < leaves.size(); i++) {
        for (int j = i + 1; j < leaves.size(); j++) {
            const int cost = calculate(leaves[i], leaves[j]);
            minimal = min(minimal, cost);
        }
    }

    return minimal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].page;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nodes[b].parent = a;
        nodes[a].children.push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (nodes[i].parent == 0) {
            roots.push_back(i);
        }

        if (nodes[i].children.size() == 0) {
            leaves.push_back(i);
        }
    }

    init();

    // print_debug();

    printf("%d\n", bf());

    return 0;
}
