// Burning Tree [OR] Minimum time to burn the entire Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/burning-tree/1

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

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// TC : O(n), SC : O(n)
class Solution {
    // creae mapping
    // create target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {
        Node* res = NULL;
        
        // level order tarversal
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            if(front->data == target) {
                res = front;
            }
            
            if(front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        
        return res;
    }
    
    int burnTree(Node* root, map<Node*, Node*> &nodeToParent) {
        map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(root);
        visited[root] = true;
        
        int ans = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            bool flag = 0;
            for(int i = 0; i < size; i++) {
                // process neighbouring nodes
                Node* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]) {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                
                if(front->right && !visited[front->right]) {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                
                if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            
            if(flag == 1) { // matlab queue me element ADD hua hai
                ans++;
            }
        }
        
        return ans;
    }
    
    public:
    int minTime(Node* root, int target) 
    {
        // algo
        // step-1 : create to nodeToParent mapping
        // step-2 : find target node
        // step-3 : burn the tree in min time
        
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        int ans = burnTree(targetNode, nodeToParent);
        
        return ans;
    }
};

int main() {
    
    return 0;
}