#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int K, N;
vector<int> neighbor[901];

bool solve() {
    for (int i = 1; i <= N; i++) {
        vector<int> intersection;
        vector<int> candidates;

        for (int j = i; j <= N; j++) {
            vector<int> temp;

            if (j == i) {
                temp = neighbor[j];
            } else {
                set_intersection(intersection.begin(), intersection.end(),
                        neighbor[j].begin(), neighbor[j].end(),
                        back_inserter(temp));
            }

//            cout << i << " " << j << ": ";
//            for (auto e: temp) {
//                cout << e << ' ';
//            }
//            cout << '\n';

            if (temp.size() < K) {
                continue;
            }

            intersection = move(temp);
            candidates.push_back(j);

            if (candidates.size() >= K) {
                for (int l = 0; l < K; l++) {
                    cout << candidates[l] << '\n';
                }
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int F;
    cin >> K >> N >> F;
    while (F--) {
        int a, b;
        cin >> a >> b;
        neighbor[a].push_back(b);
        neighbor[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        neighbor[i].push_back(i);
        sort(neighbor[i].begin(), neighbor[i].end());
    }

    if (!solve())
        cout << "-1\n";

    return 0;
}
