// Diameter of a Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// LeetCode : https://leetcode.com/problems/diameter-of-binary-tree/description/

#include<iostream>
using namespace std;

/**********************************************************
Tree node structure  used in the program

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

**********************************************************/


// Intuition : height wale function call ko hatana hai {STRIVER approach}
/*
TC : O(n)
SC : O(h)
*/
class Solution {
    int solve(TreeNode* root, int& diameter) {
        if(root == NULL) return 0;
        int left = solve(root->left, diameter);
        int right = solve(root->right, diameter);
        diameter = max(diameter, left+right);
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        solve(root, diameter);
        return diameter;
    }
};



// Intuition : height wale function call ko hatana hai {CHUTIYA & COMPLEX approach}
/*
TC : O(n)
SC : O(h)
*/
/*
class Solution {
  private:
    // pair --> {diameter, height}
    pair<int,int> diameterFast(Node* root) {
        if(root == NULL) return {0,0};

        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + 1 + right.second;

        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
    
  public:
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};
*/


// naive approach
/*
TC : O(n^2), SC : O(h)
*/
/*
class Solution {
  private:
    int height(Node* node) {
        if(node == NULL) return 0;
        
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        return ans;
    }
    
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == NULL) return 0;
        
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + 1 + height(root->right);
        
        int ans = max(op1, max(op2, op3));
        return ans;
    }
};
*/

int main() {
    
    return 0;
}