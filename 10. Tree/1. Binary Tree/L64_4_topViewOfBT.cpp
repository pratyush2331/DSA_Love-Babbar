// Top View of Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

/*
INTERVIEW QUESTION : Can we use recursion ?
ANSWER : NO
*/

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

// level-order-traversal
/*
TC : O(n)
SC : O(n)
*/
class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        map<int, int> mp; // {vertical, val}
        queue<pair<Node*, int>> q; // {node, vertical}
        q.push({root, 0});
        while(!q.empty()) {
            pair<Node*, int> front = q.front();
            q.pop();
            Node* node = front.first;
            int vertical = front.second;
            if(mp.find(vertical) == mp.end()) mp[vertical] = node->data;
            if(node->left) q.push({node->left, vertical-1});
            if(node->right) q.push({node->right, vertical+1});
        }
        
        for(auto ele : mp) {
            ans.push_back(ele.second);
        }
        
        return ans;
    }

};

int main() {
    
    return 0;
}