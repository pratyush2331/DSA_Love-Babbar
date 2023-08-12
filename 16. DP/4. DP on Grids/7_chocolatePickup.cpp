// Chocolate Pickup
// CodeStudio : https://www.codingninjas.com/studio/problems/chocolate-pickup_3125885

#include<iostream>
using namespace std;


#include <bits/stdc++.h>

// method-3 : space optimization
/*
TC : O(M*N*N) * 9
SC : O(N*N)
*/
// /*
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> curr(n, vector<int>(n, 0));
    vector<vector<int>> next(n, vector<int>(n, 0));

    // from base case
    for(int j1 = 0; j1 < n; j1++) {
        for(int j2 = 0; j2 < n; j2++) {
            if(j1 == j2)
                next[j1][j2] = grid[m-1][j1];
            else
                next[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
        }
    }
    
    for(int i = m-2; i >= 0; i--) {
        for(int j1 = 0; j1 < n; j1++) {
            for(int j2 = 0; j2 < n; j2++) {
                // total 9 possibilities : 3 possibilities each
                int maxi = -1e9;
                for(int d1 = -1; d1 <= 1; d1++) {
                    for(int d2 = -1; d2 <= 1; d2++) {
                        int ans;
                        // from base case
                        if(j1+d1 < 0 || j1+d1 >= n || j2+d2 < 0 || j2+d2 >= n)
                            ans = -1e9;
                        else if(j1 == j2)
                            ans = grid[i][j1] + next[j1+d1][j2+d2];
                        else
                            ans = grid[i][j1] + grid[i][j2] + next[j1+d1][j2+d2];
                        maxi = max(maxi, ans);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        next = curr;
    }

    return next[0][n-1];
}
// */



// method-2 : tabulation
/*
TC : O(M*N*N) * 9
SC : O(M*N*N)
*/
/*
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

    // from base case
    for(int j1 = 0; j1 < n; j1++) {
        for(int j2 = 0; j2 < n; j2++) {
            if(j1 == j2)
                dp[m-1][j1][j2] = grid[m-1][j1];
            else
                dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
        }
    }
    
    for(int i = m-2; i >= 0; i--) {
        for(int j1 = 0; j1 < n; j1++) {
            for(int j2 = 0; j2 < n; j2++) {
                // total 9 possibilities : 3 possibilities each
                int maxi = -1e9;
                for(int d1 = -1; d1 <= 1; d1++) {
                    for(int d2 = -1; d2 <= 1; d2++) {
                        int ans;
                        // from base case
                        if(j1+d1 < 0 || j1+d1 >= n || j2+d2 < 0 || j2+d2 >= n)
                            ans = -1e9;
                        else if(j1 == j2)
                            ans = grid[i][j1] + dp[i+1][j1+d1][j2+d2];
                        else
                            ans = grid[i][j1] + grid[i][j2] + dp[i+1][j1+d1][j2+d2];
                        maxi = max(maxi, ans);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][n-1];
}
*/



// method-1 : recursion + memoization
/*
TC : O(M*N*N) * 9
SC : O(M) + O(M*N*N)
*/
/*
int f(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>>& dp) {
    int m = grid.size();
    int n = grid[0].size();
    if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
        return -1e9;
    if(i == m-1) {
        if(j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    
    // total 9 possibilities : 3 possibilities each
    int maxi = -1e9;
    for(int d1 = -1; d1 <= 1; d1++) {
        for(int d2 = -1; d2 <= 1; d2++) {
            int ans;
            if(j1 == j2)
                ans = grid[i][j1] + f(i+1, j1+d1, j2+d2, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + f(i+1, j1+d1, j2+d2, grid, dp);
            maxi = max(maxi, ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

    return f(0, 0, grid[0].size()-1, grid, dp);
}
*/



// method-0 : recursion --> will give TLE
/*
TC : O()
SC : O()
*/
/*
int f(int i, int j1, int j2, vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
        return -1e9;
    if(i == m-1) {
        if(j1 == j2) {
            return grid[i][j1];
        }
        else {
            return grid[i][j1] + grid[i][j2];
        }
    }
    
    // total 9 possibilities : 3 possibilities each
    int maxi = -1e9;
    for(int d1 = -1; d1 <= 1; d1++) {
        for(int d2 = -1; d2 <= 1; d2++) {
            int ans = 0;
            if(j1 == j2)
                ans = grid[i][j1] + f(i+1, j1+d1, j2+d2, grid);
            else
                ans = grid[i][j1] + grid[i][j2] + f(i+1, j1+d1, j2+d2, grid);
            maxi = max(maxi, ans);
        }
    }
    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    return f(0, 0, grid[0].size()-1, grid);
}
*/


int main() {
    
    return 0;
}