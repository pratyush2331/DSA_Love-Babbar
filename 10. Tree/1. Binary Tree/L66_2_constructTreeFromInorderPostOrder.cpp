// Tree from Postorder and Inorder
// GFG : https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

#include<iostream>
using namespace std;

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

int findPosition(int in[], int ele, int inStart, int inEnd) {
    for(int i = inStart; i <= inEnd; i++) {
        if(in[i] == ele)
            return i;
    }
    return -1;
}

Node* solve(int in[], int post[], int n, int &postIndex, int inStart, int inEnd) {
    if(postIndex < 0 || inStart > inEnd)
        return NULL;
    
    int ele = post[postIndex--];
    Node* root = new Node(ele);
    int position = findPosition(in, ele, inStart, inEnd);
    
    // incase of postorder and inorder, we build first right subtree
    root->right = solve(in, post, n, postIndex, position+1, inEnd);
    root->left = solve(in, post, n, postIndex, inStart, position-1);
    
    return root;
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    int postIndex = n-1;
    Node* ans = solve(in, post, n, postIndex, 0, n-1);
    return ans;
}

int main() {
    
    return 0;
}