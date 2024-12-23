// 2471. Minimum Number of Operations to Sort a Binary Tree by Level
// LeetCode : https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

#include<bits/stdc++.h>
using namespace std;


// method : level order traversal + greedy
/*
TC : O(n.logn) // as for each level, it's O(k.logk); k = 1,2,4,8..., so for all levels --> it'll be O(n.logn)
SC : O(n)
*/
class Solution {
    int minOps(vector<int>& arr) {
        vector<int> sorted_arr = arr; // SC:O(k)
        sort(sorted_arr.begin(), sorted_arr.end()); // TC:O(k.logk)
        unordered_map<int, int> mp; // {old_val, idx}, SC:O(k)
        for(int i = 0; i < arr.size(); i++) { // TC:O(k)
            mp[arr[i]] = i;
        }

        // count swaps
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) { // TC:O(k)
            if(arr[i] != sorted_arr[i]) { // arr[i] is not in correct place
                cnt++;

                // yaha pr kaun se value ko dalna hai ?
                int correct_idx = mp[sorted_arr[i]]; // first, rectify in idx/mp
                mp[arr[i]] = correct_idx;
                swap(arr[i], arr[correct_idx]); // then, rectify in arr
            }
        }
        return cnt;
    }

public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        // level order traversal
        queue<TreeNode*> q; // SC:O(n)
        q.push(root);
        while(!q.empty()) { // TC:O(n.logn)
            int x = q.size();
            vector<int> arr;
            while(x--) {
                TreeNode* front = q.front();
                q.pop();

                arr.emplace_back(front->val);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans += minOps(arr);
        }
        return ans;
    }
};


int main() {
    
    return 0;
}