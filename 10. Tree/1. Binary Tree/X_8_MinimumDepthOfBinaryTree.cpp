// 111. Minimum Depth of Binary Tree
// LeetCode : https://leetcode.com/problems/minimum-depth-of-binary-tree

#include<bits/stdc++.h>

using namespace std;


// method-1 : BFS
/*
TC : O(min_depth)
SC : O(min_depth)
*/
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int x = q.size();
            ans++;
            while(x--) {
                TreeNode* front = q.front();
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                if(front->left == NULL && front->right == NULL) return ans;
            }
        }

        return ans;
    }
};


// method-0 : DFS
/*
TC : O(max_depth)
SC : O(max_depth)
*/
/*
class Solution {
    int solve(TreeNode* root) {
        if(root == NULL) return INT_MAX;
        if(root->left == NULL && root->right == NULL) return 1;
        int left = solve(root->left);
        int right = solve(root->right);
        return 1 + min(left, right);
    }

public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return solve(root);
    }
};
*/


int main() {
    

    return 0;
}