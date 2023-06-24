// Find K-th smallest Element in BST
// GFG : https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

#include<iostream>
using namespace std;

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// using Morris Traversal (Inorder) - TC : O(n), SC : O(1)
class Solution {
    int morrisTraversal(Node* root, int k) {
        if(root == NULL)
            return -1;
    
        Node *current, *predecessor;
        current = root;
    
        int i = 0;
    
        while(current != NULL) {
            if(current->left == NULL) {
                i++;
                if(i == k)
                    return current->data;
                // cout << current->data << " ";
                current = current->right;
            }
            else {
                predecessor = current->left;
                while(predecessor->right != NULL && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
    
                // temp link creation
                if(predecessor->right == NULL) {
                    predecessor->right = current;
                    current = current->left;
                }
                // temp link deletion
                else {
                    predecessor->right = NULL;
                    i++;
                    if(i == k) {
                        return current->data;
                    }
                    // cout << current->data << " ";
                    current = current->right;
                }
            }
        }
        
        return -1;
    }
    
    public:
    int KthSmallestElement(Node* root, int k) {
        return morrisTraversal(root, k);
    }
};




// using recursion (Inorder) - TC : O(n), SC : O(h)
/*
class Solution {
    int solve(Node* root, int &i, int k) {
        // base case
        if(root == NULL) {
            return -1;
        }
    
        // L
        int left = solve(root->left, i, k);
    
        if(left != -1) {
            return left;
        }
    
        // N
        i++;
        if(i == k) {
            return root->data;
        }
    
        // R
        return solve(root->right, i, k);
        
    }
    
    public:
    int KthSmallestElement(Node* root, int k) {
        int i = 0;
        return solve(root, i, k);
    }
};
*/

int main() {
    
    return 0;
}