#include <stdio.h>

int stack[100000];
int top;

int main() {
  int n;
  scanf("%d", &n);

  while(n--) {
    int num;
    scanf("%d", &num);
    if(num) stack[top++] = num;
    else top--;
  }

  int sum = 0;
  for(int i = 0; i < top; i++) sum += stack[i];

  printf("%d\n", sum);
}
