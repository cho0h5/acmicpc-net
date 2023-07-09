#include <stdio.h>

char draw(int, int, int, int);
char tri(int, int);
int isHall(int, int, int);

int ghw;

int main() {
  int h;
  scanf("%d", &h);

  ghw = h / 3;

  int w = h / 3 * 6 - 1;


  for(int i = 0; i < h; i++) {
    int padding = (h - i - 1) / 3 * 3;
    for(int k = 0; k < padding; k++) printf(" ");

    for(int j = 0; j < w - padding; j++) {
      printf("%c", draw(h, w, i, j));
    }
    printf("\n");
  }

  return 0;
}

char draw(int h, int w, int i, int j) {
  int ty = h / 3 - (h - i - 1) / 3 - 1;
  int tx = j / 6;
  if(tx > ty) return ' ';

  if(isHall(tx, ty, ghw / 2))
    return tri(j - 6 * tx, i - 3 * ty);
  else return ' ';
}

int isHall(int x, int y, int g) {
  if(g <= 1) return 1;
  
  if(x < g && y < g) return isHall(x, y, g / 2);
  else if(x < g && y >= g) {
    if(y - g < x) return 0;
    else return isHall(x, y - g, g / 2);
  }
  else return isHall(x - g, y - g, g / 2);
}

char tri(int x, int y) {
  if(y == 2 && x < 5) return '*';
  if(y == 1 && (x == 1 || x == 3)) return '*';
  if(y == 0 && x == 2) return '*';
  return ' ';
}
