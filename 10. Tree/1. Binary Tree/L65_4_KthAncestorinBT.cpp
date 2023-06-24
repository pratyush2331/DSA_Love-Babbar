// Kth Ancestor in a Tree
// GFG : https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

/*
Constraints:
1<=N<=104
1<= K <= 100
*/

#include<iostream>
using namespace std;

Node* solve(Node* root, int &k, int node) {
    if(root == NULL) return NULL;
    
    if(root->data == node) return root;
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if(leftAns != NULL && rightAns == NULL) {
        k--;
        if(k == 0) {
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k == 0) {
            return root;
        }
        return rightAns;
    }
    
    return NULL;
}

// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

// TC : o(n), SC : O(h)
/*
bool getPath(Node* root, int node, vector<int> &path) {
    if(root == NULL) return false;
    
    path.push_back(root->data);
    
    if(root->data == node) return true;
    
    if(getPath(root->left, node, path) || getPath(root->right, node, path)) return true;
    
    path.pop_back();
    return false;
}

// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    getPath(root, node, path);
    
    int size = path.size();
    if(k < size) return path[size-k-1];
    else return -1;
}
*/

int main() {
    
    return 0;
}