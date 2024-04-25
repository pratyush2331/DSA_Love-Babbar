// 700. Search in a Binary Search Tree
// LeetCode : https://leetcode.com/problems/search-in-a-binary-search-tree

#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root->val == val) return root;
        if(root->val > val) { // root->left me hai
            return searchBST(root->left, val);
        }
        else { // root->right me hai
            return searchBST(root->right, val);
        }
    }
};


int main() {
    
    return 0;
}