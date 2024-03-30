// 222. Count Complete Tree Nodes
// LeetCode : https://leetcode.com/problems/count-complete-tree-nodes

#include<bits/stdc++.h>

using namespace std;


// using property of CBT
/*
TC : O( (logn)^2 )
SC : O(logn)
*/
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        // compute left & right height
        int lh = 0, rh = 0;
        TreeNode* curr = root;
        while(curr) {
            lh++;
            curr = curr->left;
        }
        root = root;
        while(curr) {
            rh++;
            curr = curr->right;
        }

        if(lh == rh) return (1<<lh) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


int main() {
    

    return 0;
}