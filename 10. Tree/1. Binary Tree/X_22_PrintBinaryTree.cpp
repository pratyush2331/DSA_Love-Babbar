// 655. Print Binary Tree
// LeetCode : https://leetcode.com/problems/print-binary-tree

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int maxHeight(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxHeight(root->left), maxHeight(root->right)) + 1;
    }

    void dfsTraversal(TreeNode* root, int row, int col, vector<vector<string>>& ans, int height) {
        if(root == NULL) return;

        ans[row][col] = to_string(root->val);

        int factor = pow(2, height-row-1);

        dfsTraversal(root->left, row+1, col-factor, ans, height);
        dfsTraversal(root->right, row+1, col+factor, ans, height);
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = maxHeight(root);

        int rows = height;
        int cols = (1<<height)-1;
        vector<vector<string>> ans(rows, vector<string>(cols));
        dfsTraversal(root, 0, cols/2, ans, height-1); // acc. to question --> height-1
        return ans;
    }
};


int main() {    

    return 0;
}