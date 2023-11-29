// Sum of digits eqauls X

// Tutorial : 

// Q. Find the count of the numbers b/w L and R which have sum of digits = X.
// Constraints : 1 <= L <= R <= 10^18;     1 <= X <= 180


#include<iostream>
#include<cstring>

using namespace std;



// method-0 : Brute Force --> will give TLE
// TC : O((R - L+1) * log(R))
// SC : O(1)
// ----------------------------------------------------------------------------------------------------
bool check(int num, int X) {
    int sum_digit = 0;
    while(num) {
        sum_digit += num%10;
        num /= 10;
    }
    return sum_digit == X;
}

int bruteForce(int L, int R, int X) {
    if(X < 0) return 0;
    int cnt = 0;
    for(int num = L; num <= R; num++) {
        if(check(num, X)) cnt++;
    }
    return cnt;
}
// ----------------------------------------------------------------------------------------------------


// using recursion --> will work for log(R) <= 8
// TC : O(10 ^ log(R))
// ----------------------------------------------------------------------------------------------------
// For unrestricted range tight = 0
int solve(string& num, int n, int x, bool tight) {
    if(x < 0) return 0;
    if(n == 1) {
        if(x >= 0 && x <= 9)
            return 1;
        return 0;
    }

    int ans = 0;
    int ub = tight ? (num[(num.length() - n)] - '0') : 9;
    for(int digit = 0; digit <= ub; digit++) {
        ans += solve(num, n-1, x-digit, (tight & (digit == ub)));
    }

    return ans;
}
// ----------------------------------------------------------------------------------------------------


// Digit DP using recursion + memoization
// TC : O(X * log(R))
// SC : O(X * log(R))
// ----------------------------------------------------------------------------------------------------
int dp[101][181][2];

int solveDP(string& num, int n, int x, bool tight) {
    if(x < 0) return 0;
    if(n == 1) {
        if(x >= 0 && x <= 9)
            return 1;
        return 0;
    }

    if(dp[n][x][tight] != -1)
        return dp[n][x][tight];

    int ans = 0;
    int ub = tight ? (num[(num.length() - n)] - '0') : 9;
    for(int digit = 0; digit <= ub; digit++) {
        ans += solveDP(num, n-1, x-digit, (tight & (digit == ub)));
    }

    return dp[n][x][tight] = ans;
}
// ----------------------------------------------------------------------------------------------------



int main() {
    string L = "1", R = "1504456740987654456789876548956789098765567323456123456789789045678904567889751234567890";
    int X = 5;

    // Brute Force --> will give TLE
    // cout << bruteForce(stoi(L), stoi(R), X) << endl;

    // using recursion --> will give TLE
    // cout << solve(R, R.length(), X, 1) << endl;

    // using dp (recursion + memoization)
    memset(dp, -1, sizeof(dp));
    cout << solveDP(R, R.length(), X, 1) << endl;
    
    return 0;
}