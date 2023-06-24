// Binary Tree Creation
/*
Different Traversal Techniques:-
1. Level Order Traversal - BFS
2. In Order Traversal - DFS
3. Pre Order Traversal - DFS
4. Post Order Traversal - DFS
*/

#include<iostream>
#include<queue>
using namespace std;

class node {
  public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    cout << "Enter the data : ";
    int data;
    cin >> data;
    
    // base case
    if(data == -1) { // -1 ko NULL man rha hun
        return NULL;
    }

    root = new node(data);

    cout << "Enter data to insert in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data to insert in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root) { // BFS - Breadth First Search
    if(root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        int x = q.size();
        
        while(x--) {
            node* frontNode = q.front();
            q.pop();

            if(frontNode->left) {
                q.push(frontNode->left);
            }
            if(frontNode->right) {
                q.push(frontNode->right);
            }

            cout << frontNode->data << " ";
        }
        cout << endl;
    }
}

// HOMEWORK : reverse level order traversal
/*
void reverseLevelOrderTraversal(node* root) {
    
}
*/

void inorder(node* root) { // LNR
    // base case
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root) { // NLR
    // base case
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) { // NLR
    // base case
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(node* &root) {
    int data;
    cout << "Enter data for root node : ";
    cin >> data;

    if(data == -1) return;

    root = new node(data);

    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter data for left node of " << temp -> data << " : ";
        cin >> leftData;
        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        int rightData;
        cout << "Enter data for right node of " << temp -> data << " : ";
        cin >> rightData;
        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
}

int main() {
    node* root = NULL;

    // creating a Tree (Levelorder)
    buildFromLevelOrder(root);

    // /*
    // creating a Tree (Preorder)
    // root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // */

    cout << "Level order traversal : " << endl;
    levelOrderTraversal(root);

    cout << "Inorder traversal : ";
    inorder(root);
    cout << endl;
    
    cout << "Preorder traversal : ";
    preorder(root);
    cout << endl;
    
    cout << "Postorder traversal : ";
    postorder(root);
    cout << endl;

    return 0;
}