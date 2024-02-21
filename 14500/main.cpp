#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

typedef struct s_tet {
	int h;
	int w;
	int shape[4][4];
} t_tet;

vector<t_tet> tets;

void init_tets() {
	t_tet t1;
	t1.h = 1;
	t1.w = 4;
	t1.shape[0][0] = 1;
	t1.shape[0][1] = 1;
	t1.shape[0][2] = 1;
	t1.shape[0][3] = 1;
	tets.push_back(t1);

	t_tet t2;
	t2.h = 2;
	t2.w = 2;
	t2.shape[0][0] = 1;
	t2.shape[0][1] = 1;
	t2.shape[1][0] = 1;
	t2.shape[1][1] = 1;
	tets.push_back(t2);

	t_tet t3;
	t3.h = 3;
	t3.w = 2;
	t3.shape[0][0] = 1;
	t3.shape[0][1] = 0;
	t3.shape[1][0] = 1;
	t3.shape[1][1] = 0;
	t3.shape[2][0] = 1;
	t3.shape[2][1] = 1;
	tets.push_back(t3);

	t_tet t4;
	t4.h = 3;
	t4.w = 2;
	t4.shape[0][0] = 1;
	t4.shape[0][1] = 0;
	t4.shape[1][0] = 1;
	t4.shape[1][1] = 1;
	t4.shape[2][0] = 0;
	t4.shape[2][1] = 1;
	tets.push_back(t4);

	t_tet t5;
	t5.h = 2;
	t5.w = 3;
	t5.shape[0][0] = 1;
	t5.shape[0][1] = 1;
	t5.shape[0][2] = 1;
	t5.shape[1][0] = 0;
	t5.shape[1][1] = 1;
	t5.shape[1][2] = 0;
	tets.push_back(t5);

	t_tet t6;
	t6.h = 3;
	t6.w = 2;
	t6.shape[0][0] = 0;
	t6.shape[0][1] = 1;
	t6.shape[1][0] = 0;
	t6.shape[1][1] = 1;
	t6.shape[2][0] = 1;
	t6.shape[2][1] = 1;
	tets.push_back(t6);

	t_tet t7;
	t7.h = 3;
	t7.w = 2;
	t7.shape[0][0] = 0;
	t7.shape[0][1] = 1;
	t7.shape[1][0] = 1;
	t7.shape[1][1] = 1;
	t7.shape[2][0] = 1;
	t7.shape[2][1] = 0;
	tets.push_back(t7);
}

void print_tet(const t_tet &t) {
	for (int i = 0; i < t.h; i++) {
		for (int j = 0; j < t.w; j++) {
			if (t.shape[i][j] != 0)
				cout << t.shape[i][j] << ' ';
			else cout << "  ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_tets() {
	cout << "--------\n";
	for (auto i = tets.begin(); i != tets.end(); i++)
		print_tet(*i);
	cout << "--------\n";
}

void turn_tet(t_tet &t) {
	int tmp_shape[4][4];

	for (int i = 0; i < t.h; i++) {
		for (int j = 0; j < t.w; j++) {
			tmp_shape[j][i] = t.shape[i][j];
		}
	}
	swap(t.h, t.w);
	for (int i = 0; i < t.h; i++) {
		for (int j = t.w - 1; j >= 0; j--) {
			t.shape[i][t.w - 1 - j] = tmp_shape[i][j];
		}
	}
}

int n, m;
int mp[500][500];

int unit_case(int x, int y, const t_tet &t) {
	int sum = 0;
	for (int i = 0; i < t.h; i++) {
		for (int j = 0; j < t.w; j++) {
			if (t.shape[i][j] == 1)
				sum += mp[x + i][y + j];
		}
	}
	return sum;
}

int search(const t_tet &t) {
	int maxx = 0;
	for (int i = 0; i <= n - t.h; i++) {
		for (int j = 0; j <= m - t.w; j++) {
			int ret = unit_case(i, j, t);
			// print_tet(t);
			// cout << "debug: " << ret << '\n';
			maxx = max(maxx, ret);
		}
	}
	return maxx;
}

int main() {
	fastio();
	init_tets();

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
		}
	}

	int maxx = 0;
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < (int)tets.size(); b++) {
			int ret = search(tets[b]);
			maxx = max(maxx, ret);
		}
		for (auto i = tets.begin(); i != tets.end(); i++)
			turn_tet(*i);
	}
	cout << maxx << '\n';
}

