// 653. Two Sum IV - Input is a BST
// LeetCode : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

#include<iostream>
using namespace std;


// method-2 : using BSTIterator - TC : O(n), SC : O(2h); h --> height
class BSTIterator {
    stack<TreeNode*> myStack;
    bool reverse; // reverse ? before() : next()

    void pushAll(TreeNode* root) {
        while(root) {
            myStack.push(root);
            if(!reverse) root = root->left;
            else root = root->right;
        }
    }

    public:
    BSTIterator(TreeNode* root, bool reverse) {
        this->reverse = isReverse;
        pushAll(root);
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
        BSTIterator l(root, false); // for next
        BSTIterator r(root, true); // for before

        int s = l.next();
        int e = r.next(); //r.before()
        while(s < e) {
            if(s + e == k) return true;
            else if(s+e < k) s = l.next();
            else e = r.next();
        }
        return false;
    }
};


// method-1 : morris traversal - TC : O(3n + n), SC : O(n); h --> height
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


// method-0 : simple inorder traversal - TC : O(n+n), SC : O(n+h); h --> height
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