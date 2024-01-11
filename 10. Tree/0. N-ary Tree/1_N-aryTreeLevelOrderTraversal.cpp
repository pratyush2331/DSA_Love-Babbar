// 429. N-ary Tree Level Order Traversal
// LeetCode : https://leetcode.com/problems/n-ary-tree-level-order-traversal/

#include<iostream>
using namespace std;


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int x = q.size();

            vector<int> temp;
            while(x--) {
                Node* top = q.front();
                q.pop();
                temp.push_back(top->val);
                for(auto ele : top->children) {
                    // cout << ele->val << " ";
                    q.push(ele);
                }
            }
            ans.push_back(temp);
            // cout << endl;
        }

        return ans;
    }
};


int main() {
    
    return 0;
}