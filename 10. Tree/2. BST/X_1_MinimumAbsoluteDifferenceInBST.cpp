// 530. Minimum Absolute Difference in BST
// LeetCode : https://leetcode.com/problems/minimum-absolute-difference-in-bst
// LeetCode : https://leetcode.com/problems/minimum-distance-between-bst-nodes

// Revisit

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int mini = INT_MAX;
    TreeNode* prev = NULL;
    void dfsTraversal(TreeNode* root) {
        if(root == NULL) return;
        dfsTraversal(root->left);
        if(prev) mini = min(mini, root->val - prev->val);
        prev = root;
        dfsTraversal(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        dfsTraversal(root);
        return mini;
    }
};


int main() {

    return 0;
}