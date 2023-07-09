#include <stdio.h>
#include <stdlib.h>

int data[300000];
int len;

int compare(const void *a, const void *b) {
  return *(int*)a < *(int*)b;
}

int main() {
  scanf("%d", &len);

  if(len == 0) {
    printf("0");
    return 0;
  }

  
  for(int i = 0; i < len; i++) {
    scanf("%d", &data[i]);
  }

  qsort(data, len, sizeof(int), compare);


  int cut = 10 * len;
  cut *= 0.15;
  cut += 5;
  cut /= 10;
  

  int avg = 0;
  for(int i = cut; i < len - cut; i++) {
    avg += data[i];
  }
  avg *= 10;
  avg /= len - cut * 2;
  avg += 5;
  avg /= 10;

  printf("%d\n", avg);


  return 0;
}
