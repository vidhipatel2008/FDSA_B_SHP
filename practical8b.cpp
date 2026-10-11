#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int x) {
    if (root == NULL) {
        return createNode(x);
    }
    if (x < root->data) {
        root->left = insert(root->left, x);
    }
    else if (x > root->data) {
        root->right = insert(root->right, x);
    }
    return root;
}
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = NULL;
    int n, x;
    cout << "Enter number of book codes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> x;
        root = insert(root, x);
    }
    cout << "\nInorder sequence: ";
    inorder(root);
    cout << endl;
    return 0;
}
