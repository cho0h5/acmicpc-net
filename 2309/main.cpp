#include <iostream>

using namespace std;
int main() {
    int ns[9];
    int result[7];
    int a = 0;
    int total = 0;
    for(int i = 0; i < 9; i++) {
        cin >> ns[i];
        total += ns[i];
    }

    for(int i = 0; i < 9; i++) {
        for(int j = i + 1; j < 9; j++) {
            if(total - ns[i] - ns[j] == 100) {

                for(int k = 0; k < i; k++) result[a++] = ns[k];
                for(int k = i + 1; k < j; k++) result[a++] = ns[k];
                for(int k = j + 1; k < 9; k++) result[a++] = ns[k];

                sort(result, result+7);
                for(int b = 0; b < 7; b++) cout << result[b] << '\n';
                return 0;
            }
        }
    }

}