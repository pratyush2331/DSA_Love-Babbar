// 108. Convert Sorted Array to Binary Search Tree
// LeetCode : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

#include<bits/stdc++.h>
using namespace std;


class Solution {
    TreeNode* dfsTraversal(vector<int>& ans, int s, int e) {
        if(s > e) return NULL;
        int mid = s + (e-s)/2;
        TreeNode* node = new TreeNode(ans[mid]);
        node->left = dfsTraversal(ans, s, mid-1);
        node->right = dfsTraversal(ans, mid+1, e);
        return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfsTraversal(nums, 0, nums.size()-1);
    }
};


int main() {

    return 0;
}