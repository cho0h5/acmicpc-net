#include <iostream>
int main() {
    int a = 1, b = 1;
    int resp;
    for(; a <= 9; a++){
        std::cout << "? A " << a << std::endl;
        std::cin >> resp;
        if(resp == 1){
            break;
        }
    }
    for(; b <= 9; b++){
        std::cout << "? B " << b << std::endl;
        std::cin >> resp;
        if(resp == 1){
            break;
        }
    }

    std::cout << "! " << a + b << '\n';
}
