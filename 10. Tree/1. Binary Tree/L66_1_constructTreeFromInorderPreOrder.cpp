// Construct Tree from Inorder & Preorder
// GFG : https://practice.geeksforgeeks.org/problems/construct-tree-1/1
// LeetCode : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include<iostream>
using namespace std;

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

// TC : O(n^2), SC : O(h)
class Solution{
    int findPosition(int in[], int ele, int inStart, int inEnd) {
        for(int i = inStart; i <= inEnd; i++) {
            if(in[i] == ele)
                return i;
        }
        return -1;
    }
    
    Node* solve(int in[], int pre[], int n, int &preIndex, int inStart, int inEnd) {
        if(preIndex >= n || inStart > inEnd)
            return NULL;
        
        int ele = pre[preIndex++];
        Node* root = new Node(ele);
        int position = findPosition(in, ele, inStart, inEnd);
        
        root->left = solve(in, pre, n, preIndex, inStart, position-1);
        root->right = solve(in, pre, n, preIndex, position+1, inEnd);
        
        return root;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex = 0;
        Node* ans = solve(in, pre, n, preIndex, 0, n-1);
        return ans;
    }
};

int main() {
    
    return 0;
}