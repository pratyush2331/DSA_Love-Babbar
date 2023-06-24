// SUM TREE
// GFG : https://practice.geeksforgeeks.org/problems/sum-tree/1

#include<iostream>
using namespace std;

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// TC : O(n), SC : O(h)
// Should return true if tree is Sum Tree, else false
class Solution
{
    // pair<bool,int> --> {isEqual, sum}
    pair<bool,int> isSumTreeFast(Node* root) {
        if(root == NULL) {
            return {true, 0};
        }
        if(root->left == NULL && root->right == NULL) { // leaf node ke liye
            return {true, root->data};
        }
        
        pair<bool,int> left = isSumTreeFast(root->left);
        pair<bool,int> right = isSumTreeFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool isEqual = root->data == (left.second + right.second);
        
        pair<bool,int> ans;
        if(leftAns && rightAns && isEqual) {
            ans.first = true;
            ans.second = left.second + right.second + root->data; // OR 2 * root->data;
        }
        else {
            ans.first = false;
        }
        return ans;
    }

public:
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};

int main() {
    
    return 0;
}