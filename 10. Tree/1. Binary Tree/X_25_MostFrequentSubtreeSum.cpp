// 508. Most Frequent Subtree Sum
// LeetCode : https://leetcode.com/problems/most-frequent-subtree-sum

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int dfsTraversal(TreeNode*root, unordered_map<int, int>& mp, int& maxFreq) {
        if(root == NULL) return 0;
        int left = dfsTraversal(root->left, mp, maxFreq);
        int right = dfsTraversal(root->right, mp, maxFreq);
        int sum = left + right + root->val;
        mp[sum]++;
        maxFreq = max(maxFreq, mp[sum]);
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp; // map --> {sum, freq}
        int maxFreq = INT_MIN;
        dfsTraversal(root, mp, maxFreq);
        vector<int> ans;
        for(auto ele : mp) {
            if(ele.second == maxFreq) ans.push_back(ele.first);
        }
        return ans;
    }
};


int main() {

    return 0;
}