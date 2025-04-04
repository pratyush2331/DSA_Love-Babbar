// 1123. Lowest Common Ancestor of Deepest Leaves
// LeetCode : https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if(!root) return {NULL, 0};

        // kind of post order traversal...
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.second > right.second) return {left.first, left.second + 1};
        else if (left.second < right.second) return {right.first, right.second + 1};
        else return {root, left.second + 1};
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};


int main() {
    
    return 0;
}