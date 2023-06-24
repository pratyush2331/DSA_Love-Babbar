// Path to Given Node
// InterviewBit : https://www.interviewbit.com/problems/path-to-given-node/

/*
Given a Binary Tree A containing N nodes.
You need to find the path from Root to a given node B.

NOTE:
    No two nodes in the tree have same data values.
    You can assume that B is present in the tree A and a path always exists.
*/

#include<iostream>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/

bool getPath(TreeNode* root, int B, vector<int> &ans) {
    if(root == NULL) return false;
    
    ans.push_back(root->val);
    
    if(root->val == B) return true;
    
    if(getPath(root->left, B, ans) || getPath(root->right, B, ans)) return true;
    
    ans.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    getPath(A, B, ans);
    return ans;
}

int main() {
    
    return 0;
}