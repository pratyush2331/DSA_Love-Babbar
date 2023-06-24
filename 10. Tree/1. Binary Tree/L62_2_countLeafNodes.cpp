// Count Leaf Nodes
// CodeStudio : https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055

#include<iostream>
using namespace std;

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
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
    
***********************************************************/

int noOfLeafNodes(BinaryTreeNode<int> *root){
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) return 1;

    return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
}

/*
void solve(BinaryTreeNode<int>* root, int &ans) { //using preorder traversal
    if(root == NULL) {
        return;
    }

    if(root->left == NULL && root->right == NULL) ans++;
    solve(root->left, ans);
    solve(root->right, ans);
}

int noOfLeafNodes(BinaryTreeNode<int> *root) {
    int ans = 0;
    solve(root, ans);
    return ans;
}
*/

int main() {
    
    return 0;
}