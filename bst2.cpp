#include <iostream>

using namespace std;

class Node {
public:
    int d;
    Node* left;
    Node* right;

    Node(int d) {
        this->d = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* build_tree() {
    int d;
    cin >> d;

    if (d == -1) return NULL;

    Node* node = new Node(d);
    node->left = build_tree();
    node->right = build_tree();

    return node;
}

int main(void) {
    Node* root = build_tree();

    return 0;
}
