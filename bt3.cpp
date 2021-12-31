#include <iostream>

using namespace std;

class leaf {
public:
    int data;
    leaf* left;
    leaf* right;

    leaf(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

leaf* buildTree() {
    int input;
    cin >> input;

    if (input == -1) return NULL;

    leaf* node = new leaf(input);
    node->left = buildTree();
    node->right = buildTree();

    return node;
}

int main(void) {
    leaf* root = buildTree();

    return 0;
}
