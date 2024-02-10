// Nodes at Odd Levels
// GFG : https://practice.geeksforgeeks.org/problems/nodes-at-odd-levels/1

#include<bits/stdc++.h>

using namespace std;


class Solution {
    public:
    vector<Node *> nodesAtOddLevels(Node *root) {
        vector<Node*> ans;
        
        // using level order traversal
        queue<Node*> q;
        q.push(root);
        
        int lvl = 1;
        while(!q.empty()) {
            int x = q.size();
            
            while(x--) {
                Node* front = q.front();
                q.pop();
                
                // check for lvl
                if(lvl&1) ans.push_back(front);
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            
            lvl++;
        }
        
        return ans;
    }
};


int main() {
    

    return 0;
}