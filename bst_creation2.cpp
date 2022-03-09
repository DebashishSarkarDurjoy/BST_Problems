#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node* insert(Node* root, int num) {
    if (root == NULL) {
        return new Node(num);
    }

    if (root->data < num) {
        root->right = insert(root->right, num);
    }
    else {
        root->left = insert(root->left, num);
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
    int arr[] = {3, 9, 1, 7, 10, 2, 5, 6};

    Node* root = NULL;

    for (int num: arr) {
        root = insert(root, num);
    }

    printBST(root);
    cout << endl;

    return 0;
}
