// 257. Binary Tree Paths
// leetCode : https://leetcode.com/problems/binary-tree-paths

#include<bits/stdc++.h>

using namespace std;


class Solution {
    void solve(TreeNode* root, string path, vector<string>& ans) {
        if(root == NULL) return;
        if(!path.empty()) path += "->";
        path += to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }
        solve(root->left, path, ans);
        solve(root->right, path, ans);
        path.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, "", ans);
        return ans;
    }
};


int main() {
    

    return 0;
}