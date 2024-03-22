// Height of Binary Tree OR Maximum Depth of Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
// LeetCode : https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include<iostream>
using namespace std;

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

// using recursion
/*
TC : O(n)
SC : O(height)
*/
class Solution{
public:
    int height(struct Node* node){
        if(node == NULL) return 0;
        
        int left = height(node->left);
        int right = height(node->right);
        
        return 1 + max(left, right);
    }
};

int main() {
    
    return 0;
}