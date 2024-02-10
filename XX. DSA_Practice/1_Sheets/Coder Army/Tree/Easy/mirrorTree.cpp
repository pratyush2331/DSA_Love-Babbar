// Mirror Tree
// GFG : https://practice.geeksforgeeks.org/problems/mirror-tree/1

#include<bits/stdc++.h>

using namespace std;


class Solution {
    public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == NULL)
            return;
        
        // processing...
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        mirror(node->left);
        mirror(node->right);
    }
};


int main() {
    

    return 0;
}