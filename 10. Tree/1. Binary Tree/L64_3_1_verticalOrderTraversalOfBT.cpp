// Vertical Traversal of Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

#include<iostream>
using namespace std;

class Solution
{
public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans; // for storing ans   
        if(root == NULL) return ans;

        // create map and queue
        map<int, map<int, vector<int>>> nodes; // map(hd, lvl, {nodes->data})
        queue<pair<Node*, pair<int,int>>> q; // queue(node*, hd, lvl)
        
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()) {
            pair<Node*, pair<int, int> > temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
            
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
        
        for(auto i : nodes) {
            for(auto j : i.second) {
                for(auto k : j.second) {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}