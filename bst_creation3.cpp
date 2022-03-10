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

void printBST(Node* root) {
    if (root == NULL) {
        return ;
    }

    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

int main(void) {

    Node* root = NULL;

    int arr[] = {3,10,2,5,7,1,9};

    for (int num: arr) {
        root = insertBST(root, num);
    }

    printBST(root);
    cout << endl;

    return 0;
}
