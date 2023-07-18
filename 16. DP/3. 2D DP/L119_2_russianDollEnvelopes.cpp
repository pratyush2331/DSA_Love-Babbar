// 354. Russian Doll Envelopes
// LeetCode : https://leetcode.com/problems/russian-doll-envelopes/

#include<iostream>
using namespace std;


class Solution {
    // method-0 : LIS pattern (DP + Binary Search)
    /*
    TC : O(n.logn)
    SC : O(n)
    */
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }

    int lengthOfLIS(vector<vector<int>>& nums) {
        int n = nums.size();
        // no need as n > 0 (in constraint)
        // if(n == 0)
        //     return 0;
        
        vector<int> ans;
        ans.push_back(nums[0][1]);
        
        for(int i = 1; i < n; i++) {
            if(nums[i][1] > ans.back()) {
                ans.push_back(nums[i][1]);
            }
            else {
                // find index of just greater element in ans[] array
                int index = lower_bound(ans.begin(), ans.end(), nums[i][1]) - ans.begin();
                ans[index] = nums[i][1];
            }
        }

        return ans.size();
    }

    public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        return lengthOfLIS(envelopes);
    }
};


int main() {
    
    return 0;
}