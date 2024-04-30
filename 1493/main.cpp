#include <iostream>

using namespace std;

int x, y, z;
int n;
int cubes[20];

int solution(int x, int y, int z) {
	// cout << "help me\n";
	if (x == 0 || y == 0 || z == 0) return 0;

	for (int i = 19; i >= 0; i--) {
		if (cubes[i] == 0) continue;

		int cube_size = 1 << i;
		if (x >= cube_size && y >= cube_size && z >= cube_size) {
			cubes[i] -= 1;

			int count1 = solution(x, y, z - cube_size);
			if (count1 == -1) return -1;

			int count2 = solution(x, y - cube_size, cube_size);
			if (count2 == -1) return -1;

			int count3 = solution(x - cube_size, cube_size, cube_size);
			if (count3 == -1) return -1;

			return 1 + count1 + count2 + count3;
		}
	}
	return -1;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y >> z;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int j, m;
		cin >> j >> m;
		cubes[j] = m;
	}
	
	cout << solution(x, y, z) << '\n';
}
