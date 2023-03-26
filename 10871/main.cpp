#include <iostream>

int main() {
    int N, X, n;
    std::cin >> N >> X;

    for(int i = 0; i < N; i++) {
        std::cin >> n;
        if(n < X) std::cout << n << ' ';
    }

    std::cout << '\n';

    return 0;
}