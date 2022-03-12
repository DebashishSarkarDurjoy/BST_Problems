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

void printBST(Node* root) {
    if (root == NULL) return;

    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

Node* insertNode(Node* root, int num) {
    if (root == NULL) {
        return new Node(num);
    }

    if (root->data > num) {
        root->left = insertNode(root->left, num);
    }
    else {
        root->right = insertNode(root->right, num);
    }

    return root;
}

int main(void) {
    Node* root = NULL;
    int arr[] = {3,7,1,4,9,2,5,6,8};

    for (int num: arr) {
        root = insertNode(root, num);
    }

    printBST(root);
    cout << endl;


    return 0;
}
