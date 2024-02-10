// Maximum Node Level
// GFG : https://practice.geeksforgeeks.org/problems/maximum-node-level/1

#include<bits/stdc++.h>

using namespace std;


// Assumption : Return the level (0-indexed) with maximum number of nodes.
// Logic : level-order-traversal
int maxNodeLevel(Node *root) {
    int ans = INT_MIN;
    
    queue<Node*> q;
    q.push(root);
    
    int lvl = 0, maxNodes = 0;
    while(!q.empty()) {
        int x = q.size();
        
        // processing...
        if(x > maxNodes) {
            ans = lvl;
            maxNodes = x;
        }
        
        while(x--) {
            Node* front = q.front();
            q.pop();
            
            if(front->left)
                q.push(front->left);
            
            if(front->right)
                q.push(front->right);
        }
        
        lvl++;
    }
    
    return ans;
}


int main() {
    

    return 0;
}