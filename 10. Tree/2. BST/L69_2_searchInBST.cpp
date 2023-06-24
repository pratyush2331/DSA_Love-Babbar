// Search In BST
// CodeStudio : https://www.codingninjas.com/codestudio/problems/search-in-bst_1402878

#include <bits/stdc++.h> 
using namespace std;

/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

// using iteration - TC : O(h), SC : O(1)
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *temp = root;

    while(temp != NULL) {
        if(x == temp->data)
            return true;
        
        if(x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    return false;
}

// using recursion - TC : O(h), SC : O(n)
/*
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // base case - 1
    if(root == NULL)
        return false;
    
    // base case - 2
    if(x == root->data)
        return true;
    
    // left part me
    if(x < root->data)
        return searchInBST(root->left, x);
    // right part me
    else
        return searchInBST(root->right, x);

}
*/

int main() {
    
    return 0;
}