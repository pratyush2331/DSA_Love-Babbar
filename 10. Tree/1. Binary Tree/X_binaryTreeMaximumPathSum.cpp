// 124. Binary Tree Maximum Path Sum
// LeetCode : https://leetcode.com/problems/binary-tree-maximum-path-sum

#include<bits/stdc++.h>

using namespace std;


// LOGIC : maximum height of a BT
/*
TC : O(n)
SC : O(n)
*/
class Solution {
    int solve(TreeNode* root, int& ans) {
        if(root == NULL) return 0;

        int left = solve(root->left, ans);
        left = max(0, left);
        int right = solve(root->right, ans);
        right = max(0, right);

        ans = max(ans, left + right + root->val);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
        solve(root, ans);
        return ans;
    }
};


int main() {
    

    return 0;
}