#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

int n;
int s, e;
map<pair<int, int>, int> posters;

void print_state() {
    for (auto &poster: posters) {
        printf("[%d, %d] -> %d\n", poster.first.first, poster.first.second, poster.second);
    }
    printf("\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;


        for (auto it = posters.begin(); it != posters.end(); ) {
            const int s_existing = it->first.first;
            const int e_existing = it->first.second;
            if (s <= e_existing && s_existing <= e) {   // overlaped
                const int e_new = s - 1;
                const int s_new = e + 1;

                if (s_existing <= e_new) posters.insert({{s_existing, e_new}, it->second});
                if (s_new <= e_existing) posters.insert({{s_new, e_existing}, it->second});

                it = posters.erase(it);

                if (e < s_existing) break;
            } else {    // not overlaped
                it++;
            }
        }

        posters.insert({{s, e}, i});

        // print_state();
    }

    unordered_set<int> s;
    for (auto it = posters.begin(); it != posters.end(); it++) {
        s.insert(it->second);
    }
    printf("%ld\n", s.size());
}
