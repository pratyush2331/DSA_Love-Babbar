// 1130. Minimum Cost Tree From Leaf Values
// LeetCode : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

#include<iostream>
using namespace std;


class Solution {
    // method-2 : tabulation
    /*
    TC : more than O(n^3)
    SC : O(n^2)
    */
    public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        // initializing map
        map<pair<int,int>, int> maxi;
        for(int i = 0; i < n; i++) {
            maxi[{i,i}] = arr[i];
            for(int j = i+1; j < n; j++) {
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int left = n-1; left >= 0; left--) {
            for(int right = left+1; right <= n-1; right++) {
                
                int mini = INT_MAX;
                for(int i = left; i < right; i++) {
                    mini = min(mini, maxi[{left,i}] * maxi[{i+1,right}] + dp[left][i] + dp[i+1][right]);
                }

                dp[left][right] = mini;
            }
        }

        return dp[0][n-1];
    }



    // method-1 : recursion + memoization
    /*
    int solve(vector<int>& arr, map<pair<int,int>, int>& maxi, int left, int right, vector<vector<int>>& dp) {
        // when it is leaf node
        if(left == right)
            return 0;
        
        if(dp[left][right] != -1)
            return dp[left][right];
        
        int mini = INT_MAX;
        for(int i = left; i < right; i++) {
            mini = min(mini, maxi[{left,i}] * maxi[{i+1,right}] + solve(arr, maxi, left, i, dp) + solve(arr, maxi, i+1, right, dp));
        }

        return dp[left][right] = mini;
    }

    public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        // initializing map
        map<pair<int,int>, int> maxi;
        for(int i = 0; i < n; i++) {
            maxi[{i,i}] = arr[i];
            for(int j = i+1; j < n; j++) {
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(arr, maxi, 0, n-1, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    int solve(vector<int>& arr, map<pair<int,int>, int>& maxi, int left, int right) {
        // when it is leaf node
        if(left == right)
            return 0;
        
        int mini = INT_MAX;
        for(int i = left; i < right; i++) {
            mini = min(mini, maxi[{left,i}] * maxi[{i+1,right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i+1, right));
        }

        return mini;
    }

    public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        // initializing map
        map<pair<int,int>, int> maxi;
        for(int i = 0; i < n; i++) {
            maxi[{i,i}] = arr[i];
            for(int j = i+1; j < n; j++) {
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }

        // just checking whether map has stored correct values or not
        // for(int i = 0; i < n; i++) {
        //     for(int j = i; j < n; j++) {
        //         cout << i << "->" << j << " max is : " << maxi[{i,j}] << endl;
        //     }
        // }
        // return 0;

        return solve(arr, maxi, 0, n-1);
    }
    */
};


int main() {
    
    return 0;
}