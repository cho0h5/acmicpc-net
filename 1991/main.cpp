#include <iostream>

using namespace std;

void prefix(int);
void middlefix(int);
void postfix(int);

int graph[26][2];
int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i++) {
        char x, y, z;
        cin >> x >> y >> z;
        x -= 'A';
        y -= 'A';
        z -= 'A';
        graph[x][0] = y;
        graph[x][1] = z;
    }

//    for(int i = 0; i < t; i++) {
//        cout << i;
//        cout << '\t';
//        cout << graph[i][0];
//        cout << '\t';
//        cout << graph[i][1];
//        cout << '\n';
//    }

    prefix(0);
    cout << '\n';
    middlefix(0);
    cout << '\n';
    postfix(0);
    cout << '\n';
}

void prefix(int root) {
    if(root == -19) return;
    cout << (char)(root + 'A');
    prefix(graph[root][0]);
    prefix(graph[root][1]);
}
void middlefix(int root) {
    if(root == -19) return;
    middlefix(graph[root][0]);
    cout << (char)(root + 'A');
    middlefix(graph[root][1]);
}
void postfix(int root) {
    if(root == -19) return;
    postfix(graph[root][0]);
    postfix(graph[root][1]);
    cout << (char)(root + 'A');
}
