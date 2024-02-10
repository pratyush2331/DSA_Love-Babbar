// Find the Node with maximum GCD of the siblings of a Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/find-the-node-with-maximum-gcd-of-the-siblings-of-a-binary-tree/1

#include<bits/stdc++.h>

using namespace std;


class Solution {
    public:
    int maxGCD( Node* root) {
        pair<int, int> p = {0, 0};
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int x = q.size();
            
            while(x--) {
                Node* front = q.front();
                q.pop();
                
                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
                
                // processing...
                // finding gcd if possible
                if(front->left && front->right) {
                    int gcd = __gcd(front->left->data, front->right->data);
                    
                    // updating gcd for every level
                    if(gcd && (gcd >= p.first)) {
                        if(gcd == p.first) {
                            p.second = max(front->data, p.second);
                        }
                        else {
                            p.first = gcd;
                            p.second = front->data;
                        }
                    }
                }
            }
        }
        
        return p.second;
    }
};


int main() {
    

    return 0;
}