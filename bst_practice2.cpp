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

Node* insertIntoBST(int data, Node* root) {
    if (root == NULL) {
        return new Node(data);
    }

    if (root->data > data) {
        root->left = insertIntoBST(data, root->left);
    }
    else {
        root->right = insertIntoBST(data, root->right);
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
    int arr[] = {8,10,3,5,6,11,9,7,1,13,15,4};

    for (int num: arr) {
        root = insertIntoBST(num, root);
    }
    printBST(root);
    cout << endl;

    return 0;
}
