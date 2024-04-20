// 337. House Robber III
// LeetCode : https://leetcode.com/problems/house-robber-iii

#include<bits/stdc++.h>
using namespace std;


// method : take & not-take
/*
TC : O(n)
SC : O(n)
*/
class Solution {
    pair<int,int> dfsTraversal(TreeNode* root) {
        if(root == NULL) return {0,0};
        pair<int,int> left = dfsTraversal(root->left);
        pair<int,int> right = dfsTraversal(root->right);
        int take = root->val + left.second + right.second;
        int notTake = max(left.first, left.second) + max(right.first, right.second);
        return {take, notTake};
    }

public:
    int rob(TreeNode* root) {
        pair<int,int> ans = dfsTraversal(root);
        return max(ans.first, ans.second);
    }
};


int main() {

    return 0;
}