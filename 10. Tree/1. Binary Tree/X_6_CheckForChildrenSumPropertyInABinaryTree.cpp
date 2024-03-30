// Check for Children Sum Property in a Binary Tree
// GFG : https://www.geeksforgeeks.org/problems/children-sum-parent/1

#include<bits/stdc++.h>

using namespace std;


class Solution{
    void solve(Node* root, bool& ans) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        int left = root->left ? root->left->data : 0;
        int right = root->right ? root->right->data : 0;
        if(left + right != root->data) ans = 0; // it's not following children-sum property
        solve(root->left, ans);
        solve(root->right, ans);
    }
    
public:
    int isSumProperty(Node *root) {
        bool ans = 1; // assuming it's following children-sum property
        solve(root, ans);
        return ans;
    }
};


int main() {
    

    return 0;
}