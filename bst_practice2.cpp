#include <iostream>
#include <vector>
#include <algorithm>
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

bool search(int num, Node* root) {
    bool found = false;

    if (root == NULL) {
        return false;
    }

    if (root->data > num) {
        found = search(num, root->left);
    }
    else if (root->data < num) {
        found = search(num, root->right);
    }
    else {
        return true;
    }

    return found;
}

Node* minHeight(vector<int> arrv, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node* newNode = new Node(arrv[mid]);
    newNode->left = minHeight(arrv, start, mid-1);
    newNode->right = minHeight(arrv, mid+1, end);

    return newNode;
}

int closest(Node* root, int target) {
    int closest;
    int diff = INT_MAX;

    Node* temp = root;

    while (temp != NULL) {
        int current_diff = abs(temp->data - target);

        if (current_diff == 0) {
            return temp->data;
        }

        if (current_diff < diff) {
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

class Pair {
public:
    Node* head;
    Node* tail;
};

Pair bst2ll(Node* root) {
    Pair newPair;

    if (root == NULL) {
        newPair.head = newPair.tail = NULL;
        return newPair;
    }

    if (root->left == NULL && root->right == NULL) {
        newPair.head = root;
        newPair.tail = root;
        return newPair;
    }

    else if(root->left != NULL && root->right == NULL) {
        Pair ll_l = bst2ll(root->left);
        ll_l.tail->right = root;
        newPair.head = ll_l.head;
        newPair.tail = root;

        return newPair;
    }

    else if(root->left == NULL && root->right != NULL) {
        Pair ll_r = bst2ll(root->right);
        root->right = ll_r.head;
        newPair.head = root;
        newPair.tail = ll_r.tail;

        return newPair;
    }

    else {
        Pair ll_l = bst2ll(root->left);
        Pair ll_r = bst2ll(root->right);

        ll_l.tail->right = root;
        root->right = ll_r.head;

        newPair.head = ll_l.head;
        newPair.tail = ll_r.tail;

        return newPair;
    }

}



int main(void) {
    Node* root1 = NULL;
    int arr[] = {8,10,3,5,6,11,9,7,1,13,15,4};

    for (int num: arr) {
        root1 = insertIntoBST(num, root1);
    }
    printBST(root1);
    cout << endl;

    if (search(12, root1)) {
        cout << "found" << endl;
    }
    else {
        cout << "not found" << endl;
    }


    vector<int> arrv = {8,10,3,5,6,11,9,7,1,13,15,4,12};
    sort(begin(arrv), end(arrv));
    Node* root2 = minHeight(arrv, 0, arrv.size() - 1);
    printBST(root2);
    cout << endl;

    cout << closest(root2, 0) << endl;

    Pair p = bst2ll(root2);
    Node* temp = p.head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;

    return 0;
}
