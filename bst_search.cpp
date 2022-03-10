#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->right = this->left = NULL;
    }
};

Node* insertBST(Node* root, int num) {
    if (root == NULL) {
        return new Node(num);
    }

    if (num < root->data) {
        root->left = insertBST(root->left, num);
    }
    else {
        root->right = insertBST(root->right, num);
    }

    return root;
}

bool isPresent(Node* root, int key) {
    bool boolPresent = false;

    if (root == NULL) {
        return false;
    }

    if (root->data > key) {
        boolPresent = isPresent(root->left, key);
    }
    if (root->data < key) {
        boolPresent = isPresent(root->right, key);
    }
    else {
        return true;
    }

    return boolPresent;
}

int main(void) {
    int arr[] = {3,10,2,5,7,1,9};

    Node* root = NULL;
    for (int num: arr) {
        root = insertBST(root, num);
    }

    if (isPresent(root, 12)) {
        cout << "Present" << endl;
    }
    else {
        cout << "Not Present" << endl;
    }

    return 0;
}
