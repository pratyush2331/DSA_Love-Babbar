// 993. Cousins in Binary Tree
// LeetCode : https://leetcode.com/problems/cousins-in-binary-tree

/*
Given, a binary tree with unique values ==> x & y are unique
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int parX = 0, parY = 0;
            while(size--) {
                TreeNode* front = q.front();
                q.pop();
                if(front->left) {
                    q.push(front->left);
                    if(front->left->val == x) parX = front->val;
                    if(front->left->val == y) parY = front->val;
                }
                if(front->right) {
                    q.push(front->right);
                    if(front->right->val == x) parX = front->val;
                    if(front->right->val == y) parY = front->val;
                }
            }
            if(parX || parY) { // we got the final answer
                return (parX && parY && parX != parY);
            }
        }
        return 0;
    }
};


int main() {    

    return 0;
}