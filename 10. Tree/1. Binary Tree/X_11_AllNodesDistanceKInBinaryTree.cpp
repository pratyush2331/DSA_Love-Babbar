// 863. All Nodes Distance K in Binary Tree
// LeetCode : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

#include<bits/stdc++.h>

using namespace std;


// logic : turned BT to undirected graph and did BFS from target node
/*
TC : O(n)
SC : O(n)
*/
class Solution {
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) { // BFS from root [LoT]
        queue<TreeNode*> q; // SC:O(n)
        q.push(root);
        while(!q.empty()) { // TC:O(n)
            TreeNode* front = q.front();
            q.pop();
            if(front->left) {
                parent[front->left] = front;
                q.push(front->left);
            }
            if(front->right) {
                parent[front->right] = front;
                q.push(front->right);
            }
        }
    }

public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent; // SC:O(n)
        markParent(root, parent);

        unordered_map<TreeNode*, bool> vis; // SC:O(n)
        queue<TreeNode*> q; // SC:O(n)
        q.push(target);
        vis[target] = true;
        int currLvl = 0;
        while(!q.empty()) { // TC:O(n)
            int x = q.size();
            if(currLvl == k) break;
            currLvl++;
            while(x--) {
                TreeNode* front = q.front();
                q.pop();
                if(front->left && !vis[front->left]) { // left
                    vis[front->left] = true;
                    q.push(front->left);
                }
                if(front->right && !vis[front->right]) { // right
                    vis[front->right] = true;
                    q.push(front->right);
                }
                if(parent[front] && !vis[parent[front]]) { // up
                    vis[parent[front]] = true;
                    q.push(parent[front]);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()) { // ele stored in queue is the answer
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};


int main() {

    return 0;
}