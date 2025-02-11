#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
    public:
        UnionFind(const int n) {
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
            return true;
        }

    private:
        vector<int> parents;
};

int main() {
    UnionFind uf(10);

    cout << uf.merge(5, 6) << '\n';
    cout << uf.merge(4, 5) << '\n';
    cout << uf.merge(6, 7) << '\n';
    cout << uf.merge(4, 7) << '\n';

    return 0;
}
