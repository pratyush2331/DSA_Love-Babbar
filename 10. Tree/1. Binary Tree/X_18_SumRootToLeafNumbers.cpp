// 129. Sum Root to Leaf Numbers
// LeetCode : https://leetcode.com/problems/sum-root-to-leaf-numbers

#include<bits/stdc++.h>
using namespace std;


class Solution {
    void dfsTraversal(TreeNode* root, string str, int& sum) {
        if(root == NULL) return;

        str += to_string(root->val);

        if(root->left == NULL && root->right == NULL) {
            sum += stoi(str);
        }
        
        dfsTraversal(root->left, str, sum);
        dfsTraversal(root->right, str, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string str;
        dfsTraversal(root, str, sum);
        return sum;
    }
};


int main() {

    return 0;
}