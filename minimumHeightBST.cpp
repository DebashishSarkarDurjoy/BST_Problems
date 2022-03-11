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
    if (root == NULL) {
        return ;
    }

    printBST(root->left);
    cout << root->data;
    printBST(root->right);
}

Node* minHeightBST(vector<int> &arr, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node* current = new Node(arr[mid]);

    current->left = minHeightBST(arr, start, mid-1);
    current->right = minHeightBST(arr, mid+1, end);

    return current;
}

int main(void) {
    vector<int> arr = {1,2,3,4,5,6,7};

    Node* root = minHeightBST(arr, 0, arr.size()-1);

    return 0;
}
