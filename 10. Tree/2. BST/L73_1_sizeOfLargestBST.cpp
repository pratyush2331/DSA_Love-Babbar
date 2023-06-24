// Size of Largest BST in Binary Tree [OR] 333. Largest BST Subtree {premium-locked}
// CodeStudio : https://www.codingninjas.com/codestudio/problems/largest-bst-subtree_893103?leftPanelTab=0

/*
Given a binary tree, return the size of the largest BST, where largest means subtree with largest number of nodes in it.

Follow up:
    Can you figure out ways to solve it with O(n) time complexity?
*/

#include <bits/stdc++.h> 
using namespace std;

/************************************************************

Following is the Binary Tree node structure

template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

************************************************************/

// TC : O(n)

class info {
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode<int>* root, int &ans) {
    if(root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    // left aur right ke liye solve kar ke lao
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);
    // isBST or not
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        currNode.isBST = true;
    }
    else {
        currNode.isBST = false;
    }
    // update ans
    if(currNode.isBST) {
        ans = max(ans, currNode.size);
    }
    
    return currNode;
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}


int main() {
    
    return 0;
}