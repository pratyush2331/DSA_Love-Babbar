// Lowest Common Ancestor in a Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// LeetCode : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include<iostream>
using namespace std;

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// Optimal Solution - TC : O(n), SC : O(h); h --> height of BT
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 ) 
    {
        if(root == NULL) return NULL;
        
        if(root->data == n1 || root->data == n2) return root;
        
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);
        
        if(leftAns != NULL && rightAns != NULL) return root;
        else if(leftAns != NULL && rightAns == NULL) return leftAns;
        else if(leftAns == NULL && rightAns != NULL) return rightAns;
        else return NULL;
    }
};

// Naive Solution - TC : O(3n), SC : O(2n + h); h-->height of BT
/*
class Solution
{
    bool getPath(Node* root, int n, vector<Node*> &ans) {
        if(root == NULL) return false;
        
        ans.push_back(root);
        
        if(root->data == n) return true;
        
        if(getPath(root->left, n, ans) || getPath(root->right, n, ans)) return true;
        
        ans.pop_back();
        return false;
    }
    
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        Node* ans;
        if(root == NULL) return ans;
        
        vector<Node*> path1;
        getPath(root, n1, path1);
        
        vector<Node*> path2;
        getPath(root, n2, path2);
        
        int i = 0, j = 0;
        while(i < path1.size() && j < path2.size()) {
            if(path1[i] == path2[j]) {
                ans = path1[i];
            }
            else {
                return ans;
            }
            i++; j++;
        }
        
        return ans;
    }
};
*/

int main() {
    
    return 0;
}