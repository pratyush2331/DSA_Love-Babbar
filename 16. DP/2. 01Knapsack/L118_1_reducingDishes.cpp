// 1402. Reducing Dishes
// LeetCode : https://leetcode.com/problems/reducing-dishes/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    /*
    TC : O(n*n)
    SC : O(2n)
    */
    // /*
    public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int index = n-1; index >= 0; index--) {
            for(int time = index; time >= 0; time--) {
                int include = satisfaction[index] * (time+1) + next[time+1];
                int exclude = 0 + next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }

        return next[0];
    }
    // */



    // method-2 : tabulation
    /*
    TC : O(n*n)
    SC : O(n*n)
    */
    /*
    public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int index = n-1; index >= 0; index--) {
            for(int time = index; time >= 0; time--) {
                int include = satisfaction[index] * (time+1) + dp[index+1][time+1];
                int exclude = 0 + dp[index+1][time];

                dp[index][time] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
    */



    // method-1 : recursion + memoization
    /*
    TC : O(n*n)
    SC : O(n*n)
    */
    /*
    int solve(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dp) {
        int n = satisfaction.size();
        if(index == n)
            return 0;
        
        if(dp[index][time] != -1)
            return dp[index][time];
        
        int include = satisfaction[index] * (time+1) + solve(satisfaction, index+1, time+1, dp);
        int exclude = 0 + solve(satisfaction, index+1, time, dp);

        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }

    public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(satisfaction, 0, 0, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    TC : O(2^n)
    SC : O(n)
    */
    /*
    int solve(vector<int>& satisfaction, int index, int time) {
        if(index == satisfaction.size())
            return 0;
        
        int include = satisfaction[index] * (time+1) + solve(satisfaction, index+1, time+1);
        int exclude = 0 + solve(satisfaction, index+1, time);

        return max(include, exclude);
    }

    public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 0);
    }
    */
};


int main() {
    
    return 0;
}