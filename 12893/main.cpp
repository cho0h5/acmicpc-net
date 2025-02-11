#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
    public:
        UnionFind(const int n) : n(n) {
            parents.resize(n + 1);
            for (int i = 0; i < n + 1; i++) {
                parents[i] = i;
            }
        }

        int find(const int a) {
            if (parents[a] == a) {
                return a;
            }

            return parents[a] = find(parents[a]);
        }

        bool merge(const int a, const int b) {
            const int pa = find(a);
            const int pb = find(b);

            if (pa == pb) {
                return false;
            }

            parents[pa] = pb;
            n -= 1;
            return true;
        }

    private:
        vector<int> parents;
        int n;
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
    }

    return 0;
}
