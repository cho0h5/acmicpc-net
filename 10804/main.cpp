#include <iostream>

using namespace std;

void print_cards(int *cards) {
    for(int i = 1; i < 21; i++) printf("%d ", cards[i]);
}

void flip_cards(int *cards, int n, int m) {
    for(; n < m; n++, m--) {
        int tmp = cards[n];
        cards[n] = cards[m];
        cards[m] = tmp;
    }
}

int main() {
    int cards[21];
    for(int i = 0; i < 21; i++) cards[i] = i;

    int n, m, t = 10;
    while(t--) {
        scanf("%d %d", &n, &m);
        flip_cards(cards, n, m);
    }

    print_cards(cards);
}