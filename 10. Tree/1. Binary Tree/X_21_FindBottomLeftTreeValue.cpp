// 513. Find Bottom Left Tree Value
// LeetCode : https://leetcode.com/problems/find-bottom-left-tree-value

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()) {
            int x = q.size();
            bool once = true;
            while(x--) {
                TreeNode* front = q.front();
                q.pop();
                if(once) {
                    ans = front->val;
                    once = false;
                }
                if(front->left) q.emplace(front->left);
                if(front->right) q.emplace(front->right);
            }
        }
        return ans;
    }
};


int main() {

    return 0;
}