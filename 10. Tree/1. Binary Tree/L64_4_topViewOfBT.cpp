// Top View of Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include<iostream>
using namespace std;

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        map<int, int> topNode; // map --> (hd, node->data)
        queue<pair<Node*, int> > q; // queue --> (node, hd)
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            if(topNode.find(hd) == topNode.end()) // checking if `hd` doesn't exist in the map
                topNode[hd] = frontNode->data;
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left,hd-1));
            
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto i : topNode) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}