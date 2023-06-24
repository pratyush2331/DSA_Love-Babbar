// 653. Two Sum IV - Input is a BST
// LeetCode : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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

// using BSTIterator - TC : O(n), SC : O(2h); h --> height
class BSTIterator {
    stack<TreeNode*> myStack;

    // reverse -> true -> before
    // reverse -> false -> next
    bool reverse = true;

    void pushAll(TreeNode* node) {
        for(; node != NULL; ) {
            myStack.push(node);
            if(reverse == true) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
    }

    public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
};

class Solution {
    public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        // for next
        BSTIterator l(root, false);
        // for before
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next(); //r.before()
        while(i < j) {
            if(i + j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }

        return false;
    }
};

// morris traversal - TC : O(3n + n), SC : O(n); h --> height
/*
class Solution {
    void morrisTraversal(TreeNode* root, vector<int> &arr) {
        if(root == NULL)
            return;
        
        TreeNode *current, *predecessor;
        current = root;
        while(current != NULL) {
            if(current->left == NULL) {
                // cout << current->val << " ";
                arr.push_back(current->val);
                current = current->right;
            }
            else {
                predecessor = current->left;
                while(predecessor->right != NULL && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                // temp link creation
                if(predecessor->right == NULL) {
                    predecessor->right = current;
                    current = current->left;
                }
                // temp link deletion
                else {
                    predecessor->right = NULL;
                    // cout << current->val << " ";
                    arr.push_back(current->val);
                    current = current->right;
                }
            }
        }
    }

    public:
    bool findTarget(TreeNode* root, int k) {
        // store inorder traversal
        vector<int> arr;
        morrisTraversal(root, arr);

        // 2 pointer approach
        int i = 0, j = arr.size()-1;
        while(i < j) {
            int sum = arr[i] + arr[j];
            if(sum == k)
                return true;
            else if(sum > k)
                j--;
            else
                i++;
        }

        return false;
    }
};
*/

// simple inorder traversal - TC : O(n+n), SC : O(n+h); h --> height
/*
class Solution {
    void inorderTraversal(TreeNode* root, vector<int> &arr) {
        if(root == NULL)
            return;
        
        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        // store inorder traversal
        vector<int> arr;
        inorderTraversal(root, arr);

        // 2 pointer approach
        int i = 0, j = arr.size()-1;
        while(i < j) {
            int sum = arr[i] + arr[j];
            if(sum == k)
                return true;
            else if(sum > k)
                j--;
            else
                i++;
        }

        return false;
    }
};
*/

int main() {
    
    return 0;
}