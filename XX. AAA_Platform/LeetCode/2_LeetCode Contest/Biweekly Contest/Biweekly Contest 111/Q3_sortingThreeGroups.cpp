// 2826. Sorting Three Groups
// LeetCode : https://leetcode.com/problems/sorting-three-groups/

#include<iostream>
using namespace std;


class Solution {
    // Variation of LIS
    // method-3 : space optimization
    /*
    TC : O(n*n)
    SC : O(2n)
    */
    public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr = n-1; curr >= 0; curr--) {
            for(int prev = curr-1; prev >= -1; prev--) {
                // take
                int take = 0;
                if(prev == -1 || nums[curr] >= nums[prev])
                    take = 1 + nextRow[curr+1];
                
                // not-take
                int notTake = 0 + nextRow[prev+1];

                currRow[prev+1] = max(take, notTake);
            }
            nextRow = currRow;
        }

        return n - nextRow[0]; // return dp[0][-1+1];
    }
};


int main() {
    
    return 0;
}