#include <stdio.h>
#define INF 1000000000

int ts[101];
int graph[101][101];

int main() {
  // input
  int n, m, r;
  scanf("%d %d %d", &n, &m, &r);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &ts[i]);
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      graph[i][j] = INF;
    }
    graph[i][i] = 0;
  }

  for(int i = 0; i < r; i++) {
    int a, b, l;
    scanf("%d %d %d", &a, &b, &l);
    graph[a][b] = l;
    graph[b][a] = l;
  }


  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(graph[i][j] > graph[i][k] + graph[k][j]) {
          graph[i][j] = graph[i][k] + graph[k][j];
          if(graph[i][j] > INF) graph[i][j] = INF;
        }
      }
    }
  }

  
    
  int max_score = 0;
  for(int i = 1; i <= n; i++) {

    int current_score = 0;
    for(int j = 1; j <= n; j++) {
      if(graph[i][j] <= m) current_score += ts[j];
    }

    if(current_score > max_score) max_score = current_score;
  }

  printf("%d\n", max_score);
  
  return 0;
}
