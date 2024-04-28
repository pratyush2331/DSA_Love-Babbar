// 938. Range Sum of BST
// LeetCode : https://leetcode.com/problems/range-sum-of-bst/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        int sum = (root->val >= low && root->val <= high) ? root->val : 0;
        int left = rangeSumBST(root->left, low, high);
        int right = rangeSumBST(root->right, low, high);
        return sum + left + right;
    }
};


int main() {

    return 0;
}