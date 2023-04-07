#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
};
Node* newNode();

Node *root;

void insert(Node * n, int x) {
    if(n->value == 0) {
	n->value = x;
	n->left = newNode();
	n->right = newNode();
	return;
    }
    if(n->value > x) insert(n->left, x);
    if(n->value < x) insert(n->right, x);
}

Node* newNode() {
    Node *node;
    node = (Node*)malloc(sizeof(Node));
    node->value = 0;
    node->left = 0;
    node->right = 0;
    return node;
}

void print(Node *n) {
    if(n->value == 0) return;
    print(n->left);
    print(n->right);
    cout << n->value << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    root = newNode();

    while(!cin.eof()) {
	int input;
	cin >> input;
	insert(root, input);
    }

//    cout << "[debug tree]\n";
//    for(int i = 0; i < 15; i++) cout << tree[i] << ' ';
//    cout << '\n';

    print(root);
}
