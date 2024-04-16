// 515. Find Largest Value in Each Tree Row
// LeetCode : https://leetcode.com/problems/find-largest-value-in-each-tree-row

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int x = q.size();
            int maxi = INT_MIN;
            while(x--) {
                TreeNode* front = q.front();
                q.pop();
                maxi = max(maxi, front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};


int main() {

    return 0;
}