// Burning Tree [OR] Minimum time to burn the entire Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/burning-tree/1

// 2385. Amount of Time for Binary Tree to Be Infected
// LeetCode : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected

/*
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.
*/

/*
Example 1:
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7

Example 2:
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5
*/

#include<iostream>
using namespace std;


// method-1 : DFS [in one pass]
/*
TC : O(n)
SC : O(n)
*/
class Solution {
    int DFS(Node* root, int target, int& ans) {
        if(root == NULL) return 0;
        
        int left = DFS(root->left, target, ans);
        int right = DFS(root->right, target, ans);
        
        if(root->data == target) {
            ans = max(left, right);
            return -1;
        }
        else if(left >= 0 && right >= 0) {
            return max(left, right) + 1;
        }
        else {
            int d = abs(left) + abs(right);
            ans = max(ans, d);
            return min(left, right) - 1;
        }
        return 0;
    }
    
  public:
    int minTime(Node* root, int target) {
        int ans = 0;
        DFS(root, target, ans); // TC:O(n), SC:O(n)
        return ans;
    }
};



// method-0 : BFS
// logic : simple BFS (LoT) from target node, just like bfs in undirected graph
/*
TC : O(n)
SC : O(n)
*/
class Solution {
    void getTargetAndParent(Node* root, int target, Node* &targetPtr, unordered_map<Node*, Node*>& parent) { // simple BFS [LoT] from root node
        queue<Node*> q; // SC:O(n)
        q.push(root);
        while(!q.empty()) { // TC:O(n)
            Node* front = q.front();
            q.pop();
            if(front->data == target) targetPtr = front; // stored target's address in targetPtr
            if(front->left) {
                parent[front->left] = front; // marking parent
                q.push(front->left);
            }
            if(front->right) {
                parent[front->right] = front; // marking parent
                q.push(front->right);
            }
        }
    }
    
public:
    int minTime(Node* root, int target) {
        Node* targetPtr = NULL;
        unordered_map<Node*, Node*> parent; // SC:O(n)
        getTargetAndParent(root, target, targetPtr, parent);
        
        unordered_map<Node*, bool> vis; // SC:O(n)
        queue<Node*> q; // SC:O(n)
        q.push(targetPtr);
        vis[targetPtr] = true;
        int time = 0;
        while(!q.empty()) { // TC:O(n)
            int x = q.size();
            bool flag = 0;
            while(x--) {
                Node* front = q.front();
                q.pop();
                if(front->left && !vis[front->left]) { // left
                    vis[front->left] = true;
                    q.push(front->left);
                    flag = 1; // tree's leaf burnt
                }
                if(front->right && !vis[front->right]) { // right
                    vis[front->right] = true;
                    q.push(front->right);
                    flag = 1; // tree's leaf burnt
                }
                if(parent[front] && !vis[parent[front]]) { // up
                    vis[parent[front]] = true;
                    q.push(parent[front]);
                    flag = 1; // tree's leaf burnt
                }
            }
            if(flag) time++; // increment time, if tree's leaf burnt
        }
        return time;
    }
};


int main() {
    
    return 0;
}