// Minimum Depth of a Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/minimum-depth-of-a-binary-tree/1

#include<iostream>
using namespace std;

/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution{
  public:
    /*You are required to complete this method*/
    int minDepth(Node *root) {
        if(root == NULL) return 0;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(left == 0 || right == 0) {
            return max(left, right) + 1;
        }
        else {
            return min(left, right) + 1;
        }
    }
};

int main() {
    
    return 0;
}