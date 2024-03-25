// 112. Path Sum
// LeetCode : https://leetcode.com/problems/path-sum

#include<bits/stdc++.h>

using namespace std;


class Solution {
    bool solve(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return sum - root->val == 0;
        return solve(root->left, sum-root->val) || solve(root->right, sum-root->val);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};


int main() {
    

    return 0;
}