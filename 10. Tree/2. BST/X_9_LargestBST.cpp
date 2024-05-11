// Largest BST
// GFG : https://www.geeksforgeeks.org/problems/largest-bst/1
// LeetCode : https://leetcode.com/problems/largest-bst-subtree/

#include<bits/stdc++.h>
using namespace std;


// method-1 : optimal-approach : using {size, mini, maxi} for every node with post-order-traversal
/*
TC : O(n)
SC : O(n) // including recursive stack space
*/
class Solution{
    public:
    vector<int> postOrder(Node* root) { // {maxBSTSizeTillNow, mini, maxi}
        if(root == NULL) return {0, INT_MAX, INT_MIN};
        vector<int> left = postOrder(root->left);
        vector<int> right = postOrder(root->right);
        if(root->data > left[2] && root->data < right[1]) {
            return {left[0] + right[0] + 1, min(left[1], root->data), max(right[2], root->data)};
        }
        else {
            return {max(left[0], right[0]), INT_MIN, INT_MAX};
        }
    }
    
    int largestBst(Node *root)
    {
    	return postOrder(root)[0];
    }
};



// method-0 : brute-force : check for every node for valid BST
/*
TC : O(n^2)
SC : O(n) // including recursive stack space
*/


int main() {

    return 0;
}