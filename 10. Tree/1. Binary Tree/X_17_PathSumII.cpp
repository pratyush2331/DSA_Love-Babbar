// 113. Path Sum II
// LeetCode : https://leetcode.com/problems/path-sum-ii

#include<bits/stdc++.h>
using namespace std;


class Solution {
    void dfsTraversal(TreeNode* root, int targetSum, vector<int> path, vector<vector<int>>& ans) {
        if(root == NULL) return;

        path.push_back(root->val);
        targetSum -= root->val;

        if(root->left == NULL && root->right == NULL && targetSum == 0) {
            ans.push_back(path);
            return;
        }

        dfsTraversal(root->left, targetSum, path, ans);
        dfsTraversal(root->right, targetSum, path, ans);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfsTraversal(root, targetSum, path, ans);
        return ans;
    }
};


int main() {

    return 0;
}