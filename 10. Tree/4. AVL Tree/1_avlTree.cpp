// AVL Tree Implementation

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data, height;
    Node *left, *right;

    Node(int val) {
        data = val;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root) {
    if(!root) return 0;
    return root->height;
}

Node* rightRotatation(Node* root) {
    Node* child = root->left;
    Node* childRight = child->right;

    child->right = root;
    root->left = childRight;

    // Update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node* leftRotatation(Node* root) {
    Node* child = root->right;
    Node* childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // Update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node* insert(Node* root, int key) {
    // tree is empty
    if(!root) return new Node(key);

    // tree is not empty
    if(key < root->data) { // Left side
        root->left = insert(root->left, key);
    } else if(key > root->data) { // Right side
        root->right = insert(root->right, key);
    } else { // duplicate values are not allowed
        return root;
    }

    // Update height of current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Balancing check
    int balance = getHeight(root->left) - getHeight(root->right);

    // LL Case
    if(balance > 1 && key < root->left->data) {
        return rightRotatation(root);
    }

    // RR Case
    else if(balance < -1 && key > root->right->data) {
        return leftRotatation(root);
    }

    // LR Case
    else if(balance > 1 && key > root->left->data) {
        root->left = leftRotatation(root->left);
        return rightRotatation(root);
    }

    // RL Case
    else if(balance < -1 && key < root->right->data) {
        root->right = rightRotatation(root->right);
        return leftRotatation(root);
    }

    // No unbalancing: return the (unchanged) node pointer
    return root;
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Handling Duplicate values (not allowed to insert)

    Node* root = NULL;
    
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    cout << "Inorder: ";
    inorder(root);

    return 0;
}