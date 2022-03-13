#include <iostream>
#include <vector>
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

class Pair {
public:
    Node* head;
    Node* tail;
};

Pair bst2ll(Node* root) {
    Pair p;

    if (root == NULL) {
        p.head = p.tail = NULL;
        return p;
    }

    // 4 cases
    if (root->left == NULL && root->right == NULL) {
        p.head = p.tail = root;
    }

    else if (root->left != NULL && root->right == NULL) {
        Pair leftList = bst2ll(root->left);
        leftList.tail->right = root;
        p.head = leftList.head;
        p.tail = root;
    }

    else if (root->left == NULL && root->right != NULL) {
        Pair rightList = bst2ll(root->right);
        root->right = rightList.head;
        p.head = root;
        p.tail = rightList.tail;
    }

    else {
        Pair leftList = bst2ll(root->left);
        Pair rightList = bst2ll(root->right);

        p.head = leftList.head;
        p.tail = rightList.tail;

        leftList.tail->right = root;
        root->right = rightList.head;
    }

    return p;
}

int main(void) {
    Node* root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for (int num: arr) {
        root = insertNode(root, num);
    }
    printBST(root);
    cout << endl;

    Pair p = bst2ll(root);
    Node* temp = p.head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;


    return 0;
}
