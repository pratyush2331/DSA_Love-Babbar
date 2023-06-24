// Left View of Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

#include<iostream>
using namespace std;

/* A binary tree node

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

// Method - 2 : using Recursion
// /*
void solve(Node* root, vector<int> &ans, int level) {
    // base case
    if(root == NULL) return;
    
    if(level == ans.size())
        ans.push_back(root->data);
    
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    solve(root, ans, 0); // solve --> (node, ans, lvl)
    return ans;
}
// */



// Method - 1 : using Level Order - DFS
/*
vector<int> leftView(Node *root)
{
    vector<int> ans;
   
    if(root == NULL) return ans;
    
    map<int, int> leftNode; // map --> (lvl, node->data)
    queue<pair<Node*, int> > q; // pair --> (node, lvl)
    
    q.push(make_pair(root, 0));
    
    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int lvl = temp.second;
        
        if(leftNode.find(lvl) == leftNode.end())
            leftNode[lvl] = frontNode->data;
        
        if(frontNode->left)
            q.push(make_pair(frontNode->left, lvl+1));
        
        if(frontNode->right)
            q.push(make_pair(frontNode->right, lvl+1));
    }
    
    for(auto i : leftNode) {
        ans.push_back(i.second);
    }
    
    return ans;
}
*/

int main() {
    
    return 0;
}