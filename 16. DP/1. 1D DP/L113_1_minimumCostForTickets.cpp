// 983. Minimum Cost For Tickets
// LeetCode : https://leetcode.com/problems/minimum-cost-for-tickets/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    // approach : sliding window
    /*
    TC : O(n)
    SC : O(1)
    */
    // /*
    public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;

        queue<pair<int,int>> week; // queue --> {day, cost}
        queue<pair<int,int>> month; // queue --> {day, cost}

        for(int day : days) {
            // step-1 : remove expired days
            while(!week.empty() && (week.front().first + 7 <= day))
                week.pop();
            while(!month.empty() && (month.front().first + 30 <= day))
                month.pop();
            
            // step-2 : add cost for current day
            week.push({day, ans+costs[1]});
            month.push({day, ans+costs[2]});

            // ans update
            ans = min(ans+costs[0], min(week.front().second, month.front().second));
        }

        return ans;
    }
    // */
    
    
    
    // method-2 : tabulation
    /*
    TC : O(n)
    SC : O(n)
    */
    /*
    public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, INT_MAX); // no need to initialize with any number, as we are traversing from last index to first index and updating inbetween
        dp[n] = 0;
        
        for(int k = n-1; k >= 0; k--) {
            // to increment index for 1 day, 7 day and 30 day accordingly
            int i;

            // 1 day pass
            // for(i = k; i < n && days[i] < days[k] + 1; i++);
            i = k + 1;
            int option1 = costs[0] + dp[i];

            // 7 day pass
            for(i = k; i < n && days[i] < days[k] + 7; i++);
            int option2 = costs[1] + dp[i];

            // 30 day pass
            for(i = k; i < n && days[i] < days[k] + 30; i++);
            int option3 = costs[2] + dp[i];

            dp[k] = min(option1, min(option2, option3));
        }
        
        return dp[0];
    }
    */
    
    
    
    // method-1 : recursion + memoization
    /*
    TC : O(n)
    SC : 2 * O(n)
    */
    /*
    int solve(int n, vector<int>& days, vector<int>& costs, int index, vector<int>& dp) {
        if(index >= n)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        // to increment index for 1 day, 7 day and 30 day accordingly
        int i;

        // 1 day pass
        // for(i = index; i < n && days[i] < days[index] + 1; i++);
        i = index + 1;
        int option1 = costs[0] + solve(n, days, costs, i, dp);

        // 7 day pass
        for(i = index; i < n && days[i] < days[index] + 7; i++);
        int option2 = costs[1] + solve(n, days, costs, i, dp);

        // 30 day pass
        for(i = index; i < n && days[i] < days[index] + 30; i++);
        int option3 = costs[2] + solve(n, days, costs, i, dp);

        dp[index] = min(option1, min(option2, option3));
        return dp[index];
    }

    public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return solve(n, days, costs, 0, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    TC : O(3^n)
    SC : O(n)
    */
    /*
    int solve(int n, vector<int>& days, vector<int>& costs, int index) {
        if(index >= n)
            return 0;
        
        // to increment index for 1 day, 7 day and 30 day accordingly
        int i;

        // 1 day pass
        // for(i = index; i < n && days[i] < days[index] + 1; i++);
        i = index + 1;
        int option1 = costs[0] + solve(n, days, costs, i);

        // 7 day pass
        for(i = index; i < n && days[i] < days[index] + 7; i++);
        int option2 = costs[1] + solve(n, days, costs, i);

        // 30 day pass
        for(i = index; i < n && days[i] < days[index] + 30; i++);
        int option3 = costs[2] + solve(n, days, costs, i);

        return min(option1, min(option2, option3));
    }

    public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solve(n, days, costs, 0);
    }
    */
};


int main() {
    
    return 0;
}