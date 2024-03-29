// 662. Maximum Width of Binary Tree
// LeetCode : https://leetcode.com/problems/maximum-width-of-binary-tree

#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;

        if(root == NULL) return ans;

        // idx starts from 0
        queue<pair<TreeNode*,int>> q; // {node, idx}
        q.push({root, 0});
        while(!q.empty()) {
            int x = q.size();
            int first = q.front().second, last = q.back().second;
            ans = max(ans, last-first+1);
            while(x--) {
                TreeNode* node = q.front().first;
                int node_idx = q.front().second - first;
                q.pop();
                if(node->left) q.push({node->left, 2ll * node_idx + 1}); // 2ll is IMP, because it can go out of INT range
                if(node->right) q.push({node->right, 2ll * node_idx + 2});
            }
        }

        return ans;
    }
};


int main() {
    

    return 0;
}