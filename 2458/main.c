#include <stdio.h>

int n, m;
int graph[501][501];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
			}
		}
	}

//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			printf("%d ", graph[i][j]);
//		}
//		printf("\n");
//	}

	int count = 0;
	for (int k = 1; k <= n; k++) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (graph[i][k]) sum++;
		}
		for (int j = 1; j <= n; j++) {
			if (graph[k][j]) sum++;
		}
		if (sum == n - 1) count++;
	}
	printf("%d\n", count);
}
