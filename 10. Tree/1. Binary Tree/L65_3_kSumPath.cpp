// 437. Path Sum III
// LeetCode : https://leetcode.com/problems/path-sum-iii/
// GFG (K Sum Path) : https://practice.geeksforgeeks.org/problems/k-sum-paths/1

/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// TC : O(n), SC : O(n)
class Solution {
    unordered_map<long,int> preSum;

    void solve(TreeNode* root, int k, long sum, int &count) {
        if(root == NULL) return;

        sum += root->val;

        if(preSum.find(sum-k) != preSum.end()) {
            count += preSum[sum-k];
            // here, `count++` will not work. Why ?
        }

        preSum[sum]++;
        
        solve(root->left, k, sum, count);
        solve(root->right, k, sum, count);

        preSum[sum]--;
    }

    public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        preSum[0] = 1;
        solve(root, targetSum, 0, count);
        return count;
    }
};

// TC : O(n^2), SC : O(n)
/*
class Solution {
    void solve(TreeNode* root, int targetSum, vector<long> path, int &count) {
        if(root == NULL) return;

        path.push_back(root->val);

        solve(root->left, targetSum, path, count);
        solve(root->right, targetSum, path, count);

        int size = path.size();
        long sum = 0;
        for(int i = size-1; i >= 0; i--) {
            sum += path[i];
            if(sum == targetSum) count++;
        }

        path.pop_back();
    }

    public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        vector<long> path;
        solve(root, targetSum, path, count);
        return count;
    }
};
*/