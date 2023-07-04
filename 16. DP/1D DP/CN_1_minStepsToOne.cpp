// CodingNinjas : Min Steps to 1

/***********************************************************QUESTION***********************************************************
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1.
You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).
******************************************************************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

// Method-3 : 'space optimzation' is not possible, as it's curent value for any number is not dependent on last 3 number.
// It can be random which will be { n-1, if(n%2 == 0)->n/2, if(n%3)->n/3 }

// Method-2 (DP) : bottom-up approach = tabulation
/*
TC : O(n)
SC : O(n)
*/
// /*

int minStepsToOne(int n) {
    // base case
    if(n == 1)
        return 0;

    // step-1
    vector<int> dp(n+1, INT_MAX);

    // step-2
    dp[1] = 0;
    
    for(int i = 2; i <= n; i++) {
        int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;;
        op1 = dp[i-1];
        if(i%2 == 0) op2 = dp[i/2];
        if(i%3 == 0) op3 = dp[i/3];
        dp[i] = min(op1, min(op2, op3)) + 1;
    }
    
    return dp[n];
}
// */



// Method-1 (DP) : top-down approach = recursion + memoization
/*
TC : O(n)
SC : O(2n)
*/
/*
int solve(int n, vector<int>& dp) {
    // base case
    if(n <= 1)
        return 0;
    
    // step-3
    if(dp[n] != INT_MAX)
        return dp[n];

    // step-2
    int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    op1 = solve(n-1, dp);
    if(n%2 == 0)
        op1 = solve(n/2, dp);
    if(n%3 == 0)
        op3 = solve(n/3, dp);
    
    dp[n] = min(op1, min(op2, op3)) + 1;
    return dp[n];
}

int minStepsToOne(int n) {
    // step-1
    vector<int> dp(n+1, INT_MAX);
    return solve(n, dp);
}
*/



// Method-0 : using simple recursion
/*
TC : O(3^n) = O(2^n)
SC : O(n)
*/
/*
int minStepsToOne(int n) {
    if(n <= 1)
        return 0;

    int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    op1 = minStepsToOne(n-1);
    if(n%2 == 0)
        op1 = minStepsToOne(n/2);
    if(n%3 == 0)
        op3 = minStepsToOne(n/3);
    
    return min(op1, min(op2, op3)) + 1;
}
*/

int main() {
    int n;
    cin >> n;

    cout << minStepsToOne(n) << endl;
    
    return 0;
}