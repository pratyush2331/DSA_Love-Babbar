// 1824. Minimum Sideway Jumps
// LeetCode : https://leetcode.com/problems/minimum-sideway-jumps/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    /*
    TC : O(n)
    SC : O(1)
    */
    // /*
    public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;

        vector<int> curr(4, 1e9); // 4-rows : 0,1,2,3
        vector<int> next(4, 1e9); // 4-rows : 0,1,2,3
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;
        
        for(int currPos = n-1; currPos >= 0; currPos--) {
            for(int currLane = 1; currLane <= 3; currLane++) {
                if(obstacles[currPos+1] != currLane) {
                    curr[currLane] = next[currLane];
                }
                else {
                    // sideway jumps
                    int ans = 1e9;
                    for(int i = 1; i <= 3; i++) {
                        if(currLane != i && obstacles[currPos] != i) {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[currLane] = ans;
                }
            }
            next = curr;
        }

        return min(next[2], 1 + min(next[1], next[3]));
    }
    // */



    // method-2 : tabulation
    /*
    TC : O(n)
    SC : O(4*n)
    */
    /*
    public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;

        vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9)); // 4-rows : 0,1,2,3
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;
        
        for(int currPos = n-1; currPos >= 0; currPos--) {
            for(int currLane = 1; currLane <= 3; currLane++) {
                if(obstacles[currPos+1] != currLane) {
                    dp[currLane][currPos] = dp[currLane][currPos+1];
                }
                else {
                    // sideway jumps
                    int ans = 1e9;
                    for(int i = 1; i <= 3; i++) {
                        if(currLane != i && obstacles[currPos] != i) {
                            ans = min(ans, 1 + dp[i][currPos+1]);
                        }
                    }
                    dp[currLane][currPos] = ans;
                }
            }
        }

        return min(dp[2][0], 1 + min(dp[1][0], dp[3][0]));
    }
    */



    // method-1 : recursion + memoization
    /*
    TC : O(n)
    SC : O(5n)
    */
    /*
    int solve(vector<int>& obstacles, int currLane, int currPos, vector<vector<int>>& dp) {
        int n = obstacles.size()-1;
        if(currPos == n)
            return 0;
        
        if(dp[currLane][currPos] != -1)
            return dp[currLane][currPos];
        
        if(obstacles[currPos+1] != currLane) {
            return solve(obstacles, currLane, currPos+1, dp);
        }
        else {
            // sideway jumps
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++) { // IMP
                if(currLane != i && obstacles[currPos] != i) { // IMP
                    ans = min(ans, 1 + solve(obstacles, i, currPos, dp)); // IMP
                }
            }
            dp[currLane][currPos] = ans;
            return dp[currLane][currPos];
        }
    }

    public:
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1)); // 4-rows : 0,1,2,3
        return solve(obstacles, 2, 0, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    TC : O(2^n)
    SC : O(n)
    */
    /*
    int solve(vector<int>& obstacles, int currLane, int currPos) {
        int n = obstacles.size()-1;
        if(currPos == n)
            return 0;
        
        if(obstacles[currPos+1] != currLane) {
            return solve(obstacles, currLane, currPos+1);
        }
        else {
            // sideway jumps
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++) { // IMP
                if(currLane != i && obstacles[currPos] != i) { // IMP
                    ans = min(ans, 1 + solve(obstacles, i, currPos)); // IMP
                }
            }
            return ans;
        }
    }

    public:
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles, 2, 0);
    }
    */
};


int main() {
    
    return 0;
}