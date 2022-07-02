#include <cstdio>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> q;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if(x == 0) {
            if(q.empty()) printf("%d\n", 0);
            else printf("%d\n", q.top()), q.pop();
        } else {
            q.push(x);
        }
    }
    return 0;
}