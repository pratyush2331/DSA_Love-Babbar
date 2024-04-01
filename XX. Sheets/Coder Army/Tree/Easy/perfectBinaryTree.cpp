// Perfect Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/perfect-binary-tree/1

#include<bits/stdc++.h>

using namespace std;


class Solution {
    public:
    bool isPerfect(Node *root) {
        
        queue<Node*> q;
        q.push(root);
        
        int totalNodes = 1;
        while(!q.empty()) {
            int x = q.size();
            
            if(x < totalNodes)
                return 0;
            
            totalNodes = totalNodes<<1;
            while(x--) {
                Node* front = q.front();
                q.pop();
                
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
        }
        
        return 1;
    }
};


int main() {
    

    return 0;
}