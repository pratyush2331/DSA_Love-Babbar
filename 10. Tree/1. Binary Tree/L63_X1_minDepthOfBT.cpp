// Minimum Depth of a Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/minimum-depth-of-a-binary-tree/1

#include<iostream>
using namespace std;

/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution{
public:
    int minDepth(Node *root) {
        if(root == NULL) return 1e9; // ans can't be from the null side of the node, so return 1e9
        if(root->left == NULL && root->right == NULL) return 1; // ans will be from here, i.e. from leaf node
        
        int left = solve(root->left, cnt);
        int right = solve(root->right, cnt);
        
        return 1 + min(left, right);
    }
};

int main() {
    
    return 0;
}