// Right View of Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

#include<iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    // Method - 2 : using Recursion
    // /*
    void solve(Node* root, vector<int> &ans, int level) {
        if(root == NULL) return;
        
        if(level == ans.size())
            ans.push_back(root->data);
        
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }
    
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
    // */
    
    
    
    // Method - 1 : using Level Order - BFS
    /*
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        map<int, int> rightNode; // map --> (lvl, node->data)
        queue<pair<Node*, int> > q; // pair --> (node, lvl)
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int lvl = temp.second;
            
            rightNode[lvl] = frontNode->data;
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, lvl+1));
            
            if(frontNode->right)
                q.push(make_pair(frontNode->right, lvl+1));
        }
        
        for(auto i : rightNode) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
    */
};

int main() {
    
    return 0;
}