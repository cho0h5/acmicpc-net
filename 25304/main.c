#include <stdio.h>

int main() {
    int given_total;
    int n;
    int calculated_total = 0;

    scanf("%d", &given_total);
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int price, number;
        scanf("%d %d", &price, &number);
        calculated_total += price * number;
    }
    
    if(given_total == calculated_total) {
        printf("Yes\n");
    } else {
        printf("No");
    }

    return 0;
}