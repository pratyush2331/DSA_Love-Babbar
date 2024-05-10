// 99. Recover Binary Search Tree
// LeetCode : https://leetcode.com/problems/recover-binary-search-tree

#include<bits/stdc++.h>
using namespace std;


// method-2 : optimal-approach
/*
TC : O(n)
SC : O(1) // excluding recursive stack space
*/
class Solution {
    TreeNode *big = NULL;
    TreeNode *small = NULL;
    TreeNode* prev = NULL;
    bool found = 0;

    void changeTree(TreeNode* root) {
        if(root == NULL) return;
        changeTree(root->left);
        if(found && prev && prev->val > root->val) { // non-adjacent
            small = root;
        }
        else if(prev && prev->val > root->val) { // adjacent
            big = prev;
            small = root;
            found = 1;
        }
        prev = root;
        changeTree(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        changeTree(root); // TC:O(n)
        cout << big->val << " " << small->val;
        swap(big->val, small->val);
    }
};



// method-1 : better-approach
/*
TC : O(3n)
SC : O(n) // excluding recursive stack space
*/
/*
class Solution {
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if(root == NULL) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    void changeTree(TreeNode* root, int big, int small) {
        if(root == NULL) return;
        changeTree(root->left, big, small);
        if(root->val == big) root->val = small;
        else if(root->val == small) root->val = big;
        changeTree(root->right, big, small);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<int> inorder; // SC:O(n)
        inorderTraversal(root, inorder); // TC:O(n) ; but, here, inorder will not be sorted
        int big, small;
        bool flag = 0;
        for(int i = 0; i < inorder.size()-1; i++) { // TC:O(n)
            if(flag == 1 && inorder[i] > inorder[i+1]) {
                small = inorder[i+1];
                break;
            }
            if(flag == 0 && inorder[i] > inorder[i+1]) {
                big = inorder[i];
                small = inorder[i+1];
                flag = 1;
            }
        }
        changeTree(root, big, small); // TC:O(n)
    }
};
*/



// method-0 : brute-force : using inorder array
/*
TC : O(2n) + O(n.logn) = O(n.logn)
SC : O(n) // excluding recursive stack space
*/
/*
class Solution {
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if(root == NULL) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    void changeTree(TreeNode* root, int& idx, vector<int>& inorder) {
        if(root == NULL) return;
        changeTree(root->left, idx, inorder);
        root->val = inorder[idx++];
        changeTree(root->right, idx, inorder);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<int> inorder; // SC:O(n)
        inorderTraversal(root, inorder); // TC:O(n) ; but, here, inorder will not be sorted
        sort(begin(inorder), end(inorder)); // TC:O(n.logn), SC:O(logn)
        int idx = 0;
        changeTree(root, idx, inorder); // TC:O(n)
    }
};
*/


int main() {
    
    return 0;
}