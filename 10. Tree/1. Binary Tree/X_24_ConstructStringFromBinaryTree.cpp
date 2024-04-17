// 606. Construct String from Binary Tree
// LeetCode : https://leetcode.com/problems/construct-string-from-binary-tree

#include<bits/stdc++.h>
using namespace std;


class Solution {
    void dfsTraversal(TreeNode* root, string& ans) {
        if(root == NULL) return;

        ans += to_string(root->val);

        // condn for root->left
        if(root->left == NULL && root->right) {
            ans += '(';
            ans += ')';
        }
        else if(root->left) {
            ans += '(';
            dfsTraversal(root->left, ans);
            ans += ')';
        }

        // condn for root->right
        if(root->right) {
            ans += '(';
            dfsTraversal(root->right, ans);
            ans += ')';
        }
    }

public:
    string tree2str(TreeNode* root) {
        string ans;
        dfsTraversal(root, ans);
        return ans;
    }
};


int main() {

    return 0;
}