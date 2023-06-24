// Convert BST to Min Heap
// CodeStudio : https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498?leftPanelTab=0
// GFG : https://www.geeksforgeeks.org/convert-bst-min-heap/

/***********************************************************QUESTION*************************************************************
Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the
condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node.
This condition is applied to all the nodes, in the resultant converted Min Heap.
*********************************************************************************************************************************/

/*
TC : O(n), SC : O(n)
*/

#include <bits/stdc++.h> 
using namespace std;

/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/

void inorderTraversal(BinaryTreeNode* root, vector<int> &arr) { // TC : O(n), SC : O(h)
	if(root == NULL)
		return;
	
	inorderTraversal(root->left, arr);
	arr.push_back(root->data);
	inorderTraversal(root->right, arr);
}

void fillPreorder(BinaryTreeNode* root, vector<int> &arr, int &index) { // TC : O(n), SC : O(h)
	if(root == NULL)
		return;
	
	root->data = arr[index++];
	fillPreorder(root->left, arr, index);
	fillPreorder(root->right, arr, index);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.

	// step-1: array me inorder store karlo
	vector<int> arr;
	inorderTraversal(root, arr);

	// step-2: preorder me value update kar do arr se
	int index = 0;
	fillPreorder(root, arr, index);

	return root;
}

int main() {
    
    return 0;
}