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

int findClosest(Node* root, int target) {
    int diff = INT_MAX;
    int closest;

    Node* temp = root;
    while (temp != NULL) {
        int current_diff = abs(temp->data - target);

        if (current_diff == 0) {
            return temp->data;
        }

        if (diff > current_diff) {
            diff = current_diff;
            closest = temp->data;
        }

        if (temp->data > target) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    return closest;
}


int main(void) {
    Node* root = NULL;
    int arr[] = {3,7,1,4,9,2,5,6,8};


    for (int num: arr) {
        root = insertNode(root, num);
    }

    printBST(root);
    cout << endl;

    cout << findClosest(root, 6) << endl;



    return 0;
}
