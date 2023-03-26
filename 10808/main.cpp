#include <iostream>

using namespace std;
int main() {
    int result[26] = { 0, };
    char str[100];
    scanf("%s", str);

    for(int i = 0; str[i]; i++) {
        result[str[i] - 'a'] += 1;
    }
    
    for(int i = 0; i < 26; i++)
        printf("%d ", result[i]);
}