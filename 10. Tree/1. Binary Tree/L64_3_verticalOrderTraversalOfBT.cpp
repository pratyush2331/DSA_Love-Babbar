// Vertical Traversal of Binary Tree
// LeetCode : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree
// GFG : https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

#include<iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        map<int, map<int, multiset<int>>> mp; // {x,y,list} for mapping val corresponding to x & y
        queue<pair<TreeNode*, pair<int, int>>> q; // {node,x,y} for level order traversal
        q.push({root,{0,0}});
        while(!q.empty()) {
            pair<TreeNode*, pair<int, int>> front = q.front();
            q.pop();
            TreeNode* node = front.first;
            int x = front.second.first, y = front.second.second;
            mp[x][y].insert(node->val);
            if(node->left) q.push({node->left, {x-1, y+1}});
            if(node->right) q.push({node->right, {x+1, y+1}});
        }

        for(auto ele : mp) {
            vector<int> col;
            for(auto abc : ele.second) {
                for(auto val : abc.second) {
                    col.push_back(val);
                }
            }
            ans.push_back(col);
        }

        return ans;
    }
};


int main() {
    
    return 0;
}