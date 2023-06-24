// Merge Two BSTs
// CodeStudio : https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/

// Method-1 - TC : O(n+m), SC : O(h1+h2); h --> height of BST

void convertIntoSortedDLL(TreeNode<int> *root, TreeNode<int> *&head) { // SC : O(h)
    // base cse
    if(root == NULL)
        return;
    
    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if(head != NULL) {
        head->left = root;
    }
    head = root;

    convertIntoSortedDLL(root->left, head);
}

TreeNode<int> *mergeLinkedList(TreeNode<int> *head1, TreeNode<int> *head2) { // SC : O(1)
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            if(head == NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else { // inserta at end/tail
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else {
            if(head == NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else { // inserta at end/tail
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(TreeNode<int> *head) { // TC : O(m+n), SC : O(1)
    int cnt = 0;
    TreeNode<int> *temp = head;
    while(temp != NULL) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode<int> *sortedLLToBST(TreeNode<int>* &head, int n) {
    // base case
    if(n <= 0 || head == NULL)
        return NULL;
    
    TreeNode<int> *left = sortedLLToBST(head, n/2);

    TreeNode<int> *root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head, n-n/2-1);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2) {
    // step-1: convert BST to sorted DLL in-place
    TreeNode<int> *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode<int> *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // step-2: merge 2 sorted LL
    TreeNode<int> *head = mergeLinkedList(head1, head2);

    // step-3: conver sorted LL to BST
    return sortedLLToBST(head, countNodes(head));
}











// Method-2 - TC : O(n+m), SC : O(n+m)
/*
void inorderTraversal(TreeNode<int> *root, vector<int> &arr) {
    if(root == NULL)
        return;
    
    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}

vector<int> mergeArrays(vector<int> &arr1, vector<int> &arr2) {
    int n = arr1.size();
    int m = arr2.size();
    vector<int> ans; // (n+m) size ka array ans ko store karne ke liye

    int i = 0, j = 0;
    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) {
            ans.push_back(arr1[i++]);
        }
        else {
            ans.push_back(arr2[j++]);
        }
    }
    while(i < n) {
        ans.push_back(arr1[i++]);
    }
    while(j < m) {
        ans.push_back(arr2[j++]);
    }

    return ans;
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> &arr) {
    // base case
    if(s > e)
        return NULL;
    
    int mid = s + (e-s)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = inorderToBST(s, mid-1, arr);
    root->right = inorderToBST(mid+1, e, arr);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2) {
  // Write your code here.

  // step-1: store the inorder in 2 arrays - TC : O(n) + O(m), SC : O(n) + O(m)
  vector<int> arr1;
  inorderTraversal(root1, arr1);
  vector<int> arr2;
  inorderTraversal(root2, arr2);

  // step-2: merge 2 sorted arrays - TC : O(max(n,m)), SC : O(n+m)
  vector<int> mergedArray = mergeArrays(arr1, arr2);

  // step-3: create BST from the inorder and return root of it - TC : O(n+m), SC : O(n+m)
  return inorderToBST(0, mergedArray.size() - 1, mergedArray);
}
*/

int main() {
    
    return 0;
}