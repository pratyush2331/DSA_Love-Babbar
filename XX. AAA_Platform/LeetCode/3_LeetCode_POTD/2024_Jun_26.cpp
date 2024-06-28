// 1382. Balance a Binary Search Tree
// LeetCode : https://leetcode.com/problems/balance-a-binary-search-tree/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    void getInorder(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;
        getInorder(root->left, v);
        v.push_back(root->val);
        getInorder(root->right, v);
    }

    TreeNode* getBBST(vector<int>& v, int s, int e) {
        if(s > e) {
            return NULL;
        }
        int mid = s + (e-s)/2;
        TreeNode* newNode = new TreeNode(v[mid]);
        newNode->left = getBBST(v, s, mid-1);
        newNode->right = getBBST(v, mid+1, e);
        return newNode;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        getInorder(root, v);
        return getBBST(v, 0, v.size()-1);
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}