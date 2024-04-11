// 563. Binary Tree Tilt
// LeetCode : https://leetcode.com/problems/binary-tree-tilt

#include<bits/stdc++.h>

using namespace std;


class Solution {
    int solve(TreeNode* root, int& ans) {
        if(root == NULL) return 0;

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        ans += abs(left-right);

        return root->val + left + right;
    }

public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};


int main() {

    return 0;
}