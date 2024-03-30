// Convert an arbitrary Binary Tree to a tree that holds Children Sum Property
// GFG [article] : https://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property

/*
You can only increment data values in any node (You cannot change the structure of the tree and cannot decrement the value 
of any node).
*/

#include<bits/stdc++.h> 
using namespace std;
 
class node {
public:
    int data;
    node* left;
    node* right;
    
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};



// method-0 : Brute Force
/*
TC : O(n^2)
SC : O(n)
*/
// This function changes a tree to hold children sum property
void convertTree(node* root) { // post-order logic --> LRN
    if(root == NULL) return;
    
    // diff ke according update krdo, recursion ke pehle
    int left_data = 0, right_data = 0, diff = 0;
    if(root->left) left_data = root->left->data;
    if(root->right) right_data = root->right->data;
    diff = left_data + right_data - root->data; // child - parent
    if(diff > 0) {
        root->data = (left_data + right_data);
    }
    else if(diff < 0) {
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }

    // left aur right ke liye recursion call krdo
    convertTree(root->left);
    convertTree(root->right);

    // wapas aane ke baad, ab root->data ko update krdo
    if(root->left) left_data = root->left->data;
    if(root->right) right_data = root->right->data;
    if(root->left || root->right) { // for non-leaf node ONLY
        root->data = (left_data + right_data);
    }
}



// method-0 : Brute Force
/*
TC : O(n^2)
SC : O(n)
*/
/*
void increment(node* root, int diff) { /// will increment the child...
    if(root->left) {
        root->left->data += diff;
        increment(root->left, diff);
    }
    else if(root->right) {
        root->right->data += diff;
        increment(root->right, diff);
    }
}
 
// This function changes a tree to hold children sum property
void convertTree(node* root) { // post-order logic --> LRN
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;

    convertTree(root->left);
    convertTree(root->right);

    int left_data = 0, right_data = 0, diff = 0;
    if(root->left) left_data = root->left->data;
    if(root->right) right_data = root->right->data;
    diff = left_data + right_data - root->data; // child - parent
    if(diff > 0) root->data += diff;
    else if(diff < 0) increment(root, -diff);
}
*/



void levelOrderTraversal(node* root) {
    if (root == NULL) return;
    
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        int x = q.size();
        while(x--) {
            node* front = q.front();
            q.pop();
            cout << front->data << " ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        cout << endl;
    }
} 


int main() {
    node *root = new node(50);
    root->left = new node(7);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(1);
    root->right->right = new node(30);
    
    cout << "\nLevel-order-traversal before conversion: " << endl;
    levelOrderTraversal(root);
    
    convertTree(root);
    
    cout << "\nLevel-order-traversal after conversion: " << endl;
    levelOrderTraversal(root);
    return 0;
}