// Determine if Two Trees are Identical
// GFG : https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
// LeetCode : https://leetcode.com/problems/same-tree/

#include<iostream>
using namespace std;

/*
TC : O(n)
SC : O(n)
*/
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) return 1;
    if(p == NULL || q == NULL) return 0;
    bool left =  isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    return (p->val == q->val) && left && right;
}

int main() {
    
    return 0;
}