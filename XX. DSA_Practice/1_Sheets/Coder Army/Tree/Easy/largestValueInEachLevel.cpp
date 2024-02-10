// Largest value in each level
// GFG : https://practice.geeksforgeeks.org/problems/largest-value-in-each-level/1

#include<bits/stdc++.h>

using namespace std;


class Solution
{
    public:
    vector<int> largestValues(Node* root) {
        vector<int> ans;
        
        // processing...
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int x = q.size();
            
            int maxi = INT_MIN;
            while(x--) {
                Node* front = q.front();
                q.pop();
                
                maxi = max(maxi, front->data);
                
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            ans.push_back(maxi);
        }
        
        return ans;
    }
};


int main() {
    

    return 0;
}