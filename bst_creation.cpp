#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = this->right = NULL;
    }
};

Node* buildBST(Node* root, int num) {
    if (root == NULL) {
        return new Node(num);
    }

    if (num < root->data) {
        root->left = buildBST(root->left, num);
    }
    if (num > root->data) {
        root->right = buildBST(root->right, num);
    }

    return root;
}

void printBST(Node* root) {
    if (root == NULL) {
        return;
    }

    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);

}

int main(void) {
    Node* root = NULL;
    int a[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int num : a) {
        root = buildBST(root, num);
    }

    printBST(root);
    cout << endl;

    return 0;
}
