#include <stdio.h>

int N, M, B;
int block[500][500];

int main() {
  scanf("%d", &N);
  scanf("%d", &M);
  scanf("%d", &B);

  int min_level = 255;
  int max_level = 0;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      scanf("%d", &block[i][j]);

      if(min_level > block[i][j]) {
        min_level = block[i][j];
      }
      if(max_level < block[i][j]) {
        max_level = block[i][j];
      }
    }
  }

  int min_cost = 1000000000;
  int level = 0;
  for(int target_level = max_level; target_level >= min_level; target_level--) {
    int cost = 0;
    int inventory = B;

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(target_level > block[i][j]) {
          inventory -= target_level - block[i][j];
          cost += target_level - block[i][j];
        } else if(target_level < block[i][j]) {
          inventory += block[i][j] - target_level;
          cost += 2 * (block[i][j] - target_level);
        }
      }
    }
    
    if(inventory >= 0 && min_cost > cost) {
      min_cost = cost;
      level = target_level;
    }
  }
  
  printf("%d %d\n", min_cost, level);
  return 0;
}
