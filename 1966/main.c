#include <stdio.h>

typedef struct _element {
    int index;
    int priority;
} element;

element q[10000];
int front, rear;

void initq() {
    front = rear = 0;
}

void pushq(element e) {
    q[rear++] = e;
}

element popq() {
    return q[front++];
}

element topq() {
    return q[front];
}


int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        initq();
        int n, query;
        scanf("%d %d", &n, &query);

        for(int i = 0; i < n; i++) {
            element e;
            e.index = i;
            scanf("%d", &e.priority);
            pushq(e);
        }

        int count = 0;
        while(1) {
            element tope = topq();
            int flag = 0;
            for(int i = front; i < rear; i++)
                if(tope.priority < q[i].priority) flag = 1;

            if(flag) {
                pushq(popq());
            } else {
                if(tope.index == query) break;
                else {
                    popq();
                    count++;
                }
            }
        }

        printf("%d\n", count + 1);
    }
    return 0;
}
