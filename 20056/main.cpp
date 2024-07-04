#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include <map>

using namespace std;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m, k;
map<pair<int, int>, vector<tuple<int, int, int>>> fireballs;

void move() {
    map<pair<int, int>, vector<tuple<int, int, int>>> new_fireballs;

    for (auto &fireball: fireballs) {
        int r, c;
        tie(r, c) = fireball.first;

        for (auto &fb: fireball.second) {
            int m, s, d;
            tie(m, s, d) = fb;

            int nr, nc;
            nr = (r + dx[d] * s + n * s) % n;
            nc = (c + dy[d] * s + n * s) % n;

            new_fireballs[make_pair(nr, nc)].push_back(make_tuple(m, s, d));
        }
    }

    map<pair<int, int>, vector<tuple<int, int, int>>> new_fireballs2;
    for (auto &fireball: new_fireballs) {
        int r, c;
        tie(r, c) = fireball.first;

        if (fireball.second.size() == 1) {
            new_fireballs2[make_pair(r, c)].push_back(fireball.second[0]);
        } else if (fireball.second.size() >= 2) {
            int total_mass = 0;
            int total_speed = 0;
            bool is_odd = true;
            bool is_even = true;

            for (auto &fb: fireball.second) {
                int m, s, d;
                tie(m, s, d) = fb;

                total_mass += m;
                total_speed += s;

                if (d % 2 == 0) is_even = false;
                if (d % 2 == 1) is_odd = false;
            }

            int new_mass = total_mass / 5;
            if (new_mass < 1) continue;
            int new_speed = total_speed / fireball.second.size();

            int start_direction = 1;
            if (is_even || is_odd) start_direction = 0;

            for (int i = 0; i < 4; i++) {
                new_fireballs2[make_pair(r, c)].push_back(make_tuple(new_mass, new_speed, start_direction));
                start_direction += 2;
            }
        }
    }
    fireballs = new_fireballs2;
}

int total_mass() {
    int total_mass = 0;

    for (auto &fireball: fireballs) {
        for (auto &fb: fireball.second) {
            int m, s, d;
            tie(m, s, d) = fb;

            total_mass += m;
        }
    }
    return total_mass;
}

void print_state() {
    for (auto &fireball: fireballs) {
        int r, c;
        tie(r, c) = fireball.first;

        for (auto &fb: fireball.second) {
            int m, s, d;
            tie(m, s, d) = fb;

            cout << r << ' ' << c << ' ';
            cout << m << ' ' << s << ' ' << d << '\n';
        }
    }
    cout << '\n';
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int r, c, m, s, d;
        // (r, c), m, s, d
        cin >> r >> c >> m >> s >> d;
        fireballs[make_pair(r - 1, c - 1)].push_back(make_tuple(m, s, d));
    }

    // print_state();
    for (int i = 0; i < k; i++) {
        move();
        // print_state();
    }

    cout << total_mass() << '\n';
}
