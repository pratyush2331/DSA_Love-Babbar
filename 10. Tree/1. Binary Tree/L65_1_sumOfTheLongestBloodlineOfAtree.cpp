// Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)
// GFG : https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

/*
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.
*/

/*
TC : O(n)
SC : O(h)
*/

#include<iostream>
using namespace std;

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
        if(root == NULL) { // base case
            if(len > maxLen) { // update karo maxLen aur maxSum ko
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen) { // maxSum me max(sum,maxSum) store kro
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        sum += root->data;
        
        solve(root->left, sum, maxSum, len+1, maxLen);
        solve(root->right, sum, maxSum, len+1, maxLen);
    }

public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int sum = 0;
        int maxSum = 0;
        
        int len = 0;
        int maxLen = 0;
        
        solve(root, sum, maxSum, len, maxLen);
        
        return maxSum;
    }
};

int main() {
    
    return 0;
}