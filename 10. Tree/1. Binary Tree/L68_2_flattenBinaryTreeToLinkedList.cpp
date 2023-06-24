// Flatten binary tree to linked list
// GFG : https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
// LeetCode : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/*
Given the root of a binary tree, flatten the tree into a "linked list":
    1. The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
    2. The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

#include<iostream>
using namespace std;

// TC : O(n), SC : O(1)
class Solution
{
    public:
    void flatten(Node *root)
    {
        // not needed as, n >= 1
        // if(root ==  NULL) return;
        
        Node *current, *predecessor;
        current = root;
        
        while(current != NULL) {
            if(current->left != NULL) {
                predecessor = current->left;
                while(predecessor->right != NULL) {
                    predecessor = predecessor->right;
                }
                
                predecessor->right = current->right;
                current->right = current->left;
                current->left = NULL;
            }
            current = current->right;
        }
    }
};

int main() {
    
    return 0;
}