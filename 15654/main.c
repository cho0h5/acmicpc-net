#include <stdio.h>
#include <stdlib.h>

int N, M;
int arr[8];
int tmp[8];

void permutation(int, int, int*, int);

int compare(const void *a, const void *b) {
  return *(int*)a > *(int*)b;
  
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++)
    scanf("%d", &arr[i]);

  qsort(arr, N, sizeof(int), compare);

  permutation(N, M, tmp, 0);

  return 0;
}

void print(int *tmp, int len) {
  for(int i = 0; i < len; i++) printf("%d ", tmp[i]);
  printf("\n");
}

void permutation(int N, int M, int *tmp, int len) {
  for(int i = 0; i < N; i++) {
    int flag = 1;
    for(int j = 0; j < len; j++) {
      if(tmp[j] == arr[i]) {
        flag = 0;
        break;
      }
    }
    if(flag == 0) continue;

    tmp[len] = arr[i];
    if(M == len + 1) print(tmp, len + 1);
    else permutation(N, M, tmp, len + 1);
  }
  
}
