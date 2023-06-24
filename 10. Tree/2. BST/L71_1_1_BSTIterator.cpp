// 173. Binary Search Tree Iterator
// LeetCode : https://leetcode.com/problems/binary-search-tree-iterator/

/*
Follow up:
    Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?
*/

#include<iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// next() and hasNext()
class BSTIterator {
    stack<TreeNode*> myStack;

    void pushAll(TreeNode* node) {
        for(; node != NULL; myStack.push(node), node = node->left);
    }

    public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    // return whether we have a next smallest number
    bool hasNext() {
        return !myStack.empty();
    }
    
    // returns the next smallest number
    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->val;
    }
};

// HW - before() and hasBefore()
/*
class BSTIterator {
    stack<TreeNode*> myStack;

    void pushAll(TreeNode* node) {
        for(; node != NULL; myStack.push(node), node = node->right);
    }

    public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    // return whether we have a next smallest number
    bool hasBefore() {
        return !myStack.empty();
    }
    
    // returns the next smallest number
    int before() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        pushAll(temp->left);
        return temp->val;
    }
};
*/

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    
    return 0;
}