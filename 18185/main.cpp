#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &ramen) {
    int cost = 0;

    for (int i = 0; i < ramen.size(); i++) {
        if (i <= (int)ramen.size() - 4
                && ramen[i + 3] != 0
                && ramen[i + 1] > ramen[i + 2]) {
            int gap = ramen[i + 1] - ramen[i + 2];
            int minimum = min(ramen[i], gap);


            cost += minimum * 5;
            ramen[i] -= minimum;
            ramen[i + 1] -= minimum;
        }

        if (i <= (int)ramen.size() - 3) {
            int minimum = min(min(ramen[i], ramen[i + 1]), ramen[i + 2]);

            cost += minimum * 7;
            ramen[i] -= minimum;
            ramen[i + 1] -= minimum;
            ramen[i + 2] -= minimum;
        }

        if (i <= (int)ramen.size() - 2) {
            int minimum = min(ramen[i], ramen[i + 1]);

            cost += minimum * 5;
            ramen[i] -= minimum;
            ramen[i + 1] -= minimum;
        }

        cost += ramen[i] * 3;
    }

    return cost;
}

int main() {
    int n;
    vector<int> ramen;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ramen.push_back(x);
    }

    cout << solution(ramen) << '\n';
}
