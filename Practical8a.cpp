
#include <iostream>
#include <queue>
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
Node* createTree() {
    int x;
    cout << "Enter data (-1 for no node): ";
    cin >> x;
    if (x == -1) {
        return NULL;
    }
    Node* root = createNode(x);
    cout << "Enter left child of " << x << endl;
    root->left = createTree();
    cout << "Enter right child of " << x << endl;
    root->right = createTree();
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
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelorder(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
}
int main() {
    cout << "Create Binary Tree" << endl;
    Node* root = createTree();
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << "\nLevel Order Traversal: ";
    levelorder(root);
    cout << endl;
    return 0;
}

