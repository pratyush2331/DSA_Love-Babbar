// Check for Balanced Tree
// GFG : https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
// LeetCode : https://leetcode.com/problems/balanced-binary-tree/

/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.
*/

#include<iostream>
using namespace std;

/* A binary tree node structure

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


// Method - 3
/*
TC : O(n)
SC : O(n) --> aux recursive stack space
*/

class Solution{
    int height(Node* root) {
        if(root == NULL)
            return 0;
        
        int left = height(root->left, flag);
        if(left == -1) return -1; // to avoid unnecessay recursive calls
        int right = height(root->right, flag);
        if(right == -1) return -1; // to avoid unnecessay recursive calls
        
        // check condn...
        if(abs(left - right) > 1)
            return -1;
        
        return max(left, right) + 1;
    }
    
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root) {
        return height(root, flag) != -1;
    }
};


// Method - 2
// Intuition : height wale function call ko hatana hai
// TC : O(n)
class Solution{
    private:
    // pair<bool, int> --> {isBalancedFast(T/F), height}
    pair<bool, int> isBalancedFast(Node* root) {
        if(root == NULL) return {true, 0};
        
        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool, int> ans;
        if(leftAns && rightAns && diff) {
            ans.first = true;
        }
        else {
            ans.first = false;
        }
        ans.second = max(left.second, right.second) + 1; // ans.second me height store kr rhe hai

        return ans;
    }
    
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root) {
        return isBalancedFast(root).first;
    }
};


// Method - 1
// TC : O(n^2)
class Solution{
private:
    int height(Node* root) {
        if(root == NULL) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        int ans = max(left, right) + 1;
        return ans;
    }
    
public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root) {
        if(root == NULL) return 1;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        
        if(left && right && diff) {
            return 1;
        }
        else {
            return 0;
        }
    }
};


int main() {
    
    return 0;
}