// 1691. Maximum Height by Stacking Cuboids
// LeetCode : https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

#include<iostream>
using namespace std;


class Solution {
    bool check(vector<int>& prevBox, vector<int>& newBox) {
        if(newBox[0] <= prevBox[0] && newBox[1] <= prevBox[1] && newBox[2] <= prevBox[2])
            return true;
        else
            return false;
    }

    // modification in length of LIS using tabulation method
    int solve(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr = n-1; curr >= 0; curr--) {
            for(int prev = curr-1; prev >= -1; prev--) {
                // take
                int take = 0;
                if(prev == -1 || check(nums[curr], nums[prev]))
                    take = nums[curr][2] + nextRow[curr+1];
                
                // not-take
                int notTake = 0 + nextRow[prev+1];

                currRow[prev+1] = max(take, notTake);
            }
            nextRow = currRow;
        }

        return nextRow[0]; // return dp[0][-1+1];
    }

    public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // step-1 : sort all dimensions for every cuboid
        for(auto &a : cuboids) {
            sort(a.begin(), a.end());
        }

        // step-2 : sort all cuboids basis on w or l
        sort(cuboids.begin(), cuboids.end());

        // step-3 : use LIS logic
        return solve(cuboids);
    }
};


int main() {
    
    return 0;
}