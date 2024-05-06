// 1305. All Elements in Two Binary Search Trees
// LeetCode : https://leetcode.com/problems/all-elements-in-two-binary-search-trees

#include<bits/stdc++.h>
using namespace std;


// method-1 : better-soln : using stack
/*
TC : O(n)
SC : O(height)
*/
class Solution {
    void pushAll(TreeNode* root, stack<TreeNode*>& st) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans; // SC:O(1)
        stack<TreeNode*> st1, st2; // SC:O(height)
        pushAll(root1, st1);
        pushAll(root2, st2);
        while(!st1.empty() && !st2.empty()) { // TC:O(n)
            TreeNode *top1 = st1.top(), *top2 = st2.top();
            if(top1->val <= top2->val) {
                ans.push_back(top1->val);
                st1.pop();
                pushAll(top1->right, st1);
            }
            else {
                ans.push_back(top2->val);
                st2.pop();
                pushAll(top2->right, st2);
            }
        }
        while(!st1.empty()) {
            TreeNode *top1 = st1.top();
            ans.push_back(top1->val);
            st1.pop();
            pushAll(top1->right, st1);
        }
        while(!st2.empty()) {
            TreeNode *top2 = st2.top();
            ans.push_back(top2->val);
            st2.pop();
            pushAll(top2->right, st2);
        }
        return ans;
    }
};



// method-0 : brute-force : simple dfs traversal for 2 bst
/*
TC : O(n.logn)
SC : O(logn)
*/
/*
class Solution {
    void inorderTraversal(TreeNode* root, vector<int>& ans) { // any traversal will work
        if(root == NULL) return;
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans; // SC:O(1)
        inorderTraversal(root1, ans); // TC:O(n), SC:O(height)
        inorderTraversal(root2, ans); // TC:O(n), SC:O(height)
        sort(begin(ans), end(ans)); // TC:O(n.logn), SC:O(logn)
        return ans;
    }
};
*/


int main() {

    return 0;
}