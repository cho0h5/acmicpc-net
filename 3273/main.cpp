#include <iostream>
#include <unordered_set>

using namespace std;
int main() {
    // variables
    int N, thres, count = 0;
    int ns[N];
    unordered_set<int> s;

    // input
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &ns[i]);
    scanf("%d", &thres);

    // solution
    // for(int i = 0; i < N; i++) {
    //     int pair = thres - ns[i];
    //     if(s.find(pair) != s.end()) {
    //         s.erase(pair);
    //         count++;
    //     } else {
    //         s.insert(pair);
    //     }
    // }

    // output
    printf("%d\n", count);
}