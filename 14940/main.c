#include <stdio.h>

#define INF 1000000000

int H, W;
int map[1002][1002];
int cost[1002][1002];

struct element {
  int h;
  int w;
  int cost;
};

struct element queue[10000000];
int front;
int rear;

void push(struct element e) {
  if(map[e.h][e.w] == 0) return;
  if(cost[e.h][e.w] <= e.cost) return;
  queue[front++] = e;
}

struct element pop() {
  return queue[rear++];
}

int isEmpty() {
  return front == rear;
}

int encoding(int h, int w) {
  return h * 10000 + w;
}

int decodingh(int e) {
  return e / 10000;
}

int decodingw(int e) {
  return e % 10000;
}

int targetH, targetW;

int main() {
  scanf("%d %d", &H, &W);
  for(int i = 1; i <= H; i++) {
    for(int j = 1; j <= W; j++) {
      scanf("%d", &map[i][j]);

      if(map[i][j] == 2) {
        targetH = i;
        targetW = j;
      }

      cost[i][j] = INF;
    }
  }


  struct element e;
  e.h = targetH;
  e.w = targetW;
  e.cost = 0;
  push(e);

  while(!isEmpty()) {
    struct element e = pop();

    if(e.cost < cost[e.h][e.w]) {
      cost[e.h][e.w] = e.cost;

      struct element nn;
      nn.h = e.h - 1;
      nn.w = e.w;
      nn.cost = e.cost + 1;
      push(nn);

      struct element ne;
      ne.h = e.h;
      ne.w = e.w + 1;
      ne.cost = e.cost + 1;
      push(ne);

      struct element ns;
      ns.h = e.h + 1;
      ns.w = e.w;
      ns.cost = e.cost + 1;
      push(ns);

      struct element nw;
      nw.h = e.h;
      nw.w = e.w - 1;
      nw.cost = e.cost + 1;
      push(nw);
    }

    
  }
  
  for(int i = 1; i <= H; i++) {
    for(int j = 1; j <= W; j++) {
      if(map[i][j] == 0) cost[i][j] = 0;
      else if(map[i][j] == 1 && cost[i][j] == INF) cost[i][j] = -1;
    }
  }

  for(int i = 1; i <= H; i++) {
    for(int j = 1; j <= W; j++) {
      printf("%d ", cost[i][j]);
    }
    printf("\n");
  }
  

  
  return 0;
}
