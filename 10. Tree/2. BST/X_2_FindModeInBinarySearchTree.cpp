// 501. Find Mode in Binary Search Tree
// LeetCode : 

#include<bits/stdc++.h>
using namespace std;


// method-1 : using only recursion
/*
TC : O(n)
SC : O(1) //excluding recursive-stack space
*/
class Solution {
    int prevEle = INT_MAX, cnt = 0, maxFreq = 0;
    void inorderTraversal(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;
        inorderTraversal(root->left, ans);
        if(prevEle == root->val) cnt++;
        else {
            cnt = 1;
            prevEle = root->val; // update prevEle
        }
        if(cnt > maxFreq) {
            maxFreq = cnt;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(cnt == maxFreq) {
            ans.push_back(root->val);
        }
        inorderTraversal(root->right, ans);
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inorderTraversal(root, ans); // TC:O(n), SC:O(n)
        return ans;
    }
};



// method-0 : using recursion + hash-map
/*
TC : O(n)
SC : O(n)
*/
/*
class Solution {
    void dfsTraversal(TreeNode* root, unordered_map<int, int>& mp) {
        if(root == NULL) return;
        mp[root->val]++;
        dfsTraversal(root->left, mp);
        dfsTraversal(root->right, mp);
    }

public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp; // SC:O(n)
        dfsTraversal(root, mp); // TC:O(n)
        int maxi = INT_MIN;
        vector<int> ans; // SC:O(1)
        for(auto ele : mp) { // TC:O(n)
            if(ele.second > maxi) {
                maxi = ele.second;
                ans.clear();
            }
            if(ele.second == maxi) {
                ans.push_back(ele.first);
            }
        }
        return ans;
    }
};
*/


int main() {

    return 0;
}