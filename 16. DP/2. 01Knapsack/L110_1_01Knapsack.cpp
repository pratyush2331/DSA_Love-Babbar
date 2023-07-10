// 0 1 Knapsack
// CodeStudio : https://www.codingninjas.com/studio/problems/0-1-knapsack_920542

#include <bits/stdc++.h>
using namespace std;


// Method4 (Dp) : further space optimization
/*
TC : O(n*W)
SC : O(W)
*/
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	// Write your code here

	// just need 2 arrays - for curr_row and prev_row
	vector<int> prev(maxWeight+1, 0);

	// handling base case
	for(int W = wt[0]; W <= maxWeight; W++)
		prev[W] = val[0];

	for(int index = 1; index < n; index++) { // TC: O(n*W)
		for(int W = maxWeight; W >= 0; W--) {
			int include = 0;
			if(wt[index] <= W)
				include = val[index] + prev[W - wt[index]];
			int exclude = 0 + prev[W];
			prev[W] = max(include, exclude);
		}
	}

	return prev[maxWeight];
}



// Method3 (Dp) : space optimization
/*
TC : O(n*W)
SC : O(2W)
*/
/*
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	// Write your code here

	// just need 2 arrays - for curr_row and prev_row
	vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0); // SC: O(2W)

	// handling base case
	for(int W = wt[0]; W <= maxWeight; W++)
		prev[W] = val[0];

	for(int index = 1; index < n; index++) { // TC: O(n*W)
		for(int W = 0; W <= maxWeight; W++) {
			int include = 0;
			if(wt[index] <= W)
				include = val[index] + prev[W - wt[index]];
			int exclude = 0 + prev[W];
			curr[W] = max(include, exclude);
		}
		// prev_row will become curr_row for next iteration
		prev = curr;
	}

	return prev[maxWeight];
}
*/



// Method2 (Dp) : tabulation
/*
TC : O(n*W)
SC : O(n*W)
*/
/*
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	// Write your code here

	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

	// handling base case
	for(int W = wt[0]; W <= maxWeight; W++) // TC: O(W)
		dp[0][W] = val[0];

	for(int index = 1; index < n; index++) { // TC: O(n*W)
		for(int W = 0; W <= maxWeight; W++) {
			int include = 0;
			if(wt[index] <= W)
				include = val[index] + dp[index-1][W - wt[index]];
			int exclude = 0 + dp[index-1][W];
			dp[index][W] = max(include, exclude);
		}
	}

	return dp[n-1][maxWeight];
}
*/


// Method 1 (DP) : Top Down approach : recursion + memoization
/*
TC : O(n * W)
SC : O(n*W) + O(n)
*/
/*
int solve(int index, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) { // TC: O(n*W)
	// base case
	if(index == 0) {
		if(wt[0] <= W)
			return val[0];
		return 0;
	}

	if(dp[index][W] != -1)
		return dp[index][W];

	int include = 0;
	if(wt[index] <= W)
		include = val[index] + solve(index-1, W - wt[index], wt, val, dp);
	int exclude = 0 + solve(index-1, W, wt, val, dp);

	dp[index][W] = max(include, exclude);
	return dp[index][W];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here

	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1)); // SC: O(n*W)

	return solve(n-1, maxWeight, weight, value, dp); // SC: O(n) --> for 'n' recursive calls
}
*/



// Method 0 : using simple recursion --> will give TLE
/*
TC : O(2^n)
SC : O(n)
*/
/*
int solve(int index, int W, vector<int>& wt, vector<int>& val) {
	// base case
	if(index == 0) {
		if(wt[0] <= W)
			return val[0];
		return 0;
	}

	// include
	int include = 0;
	if(wt[index] <= W)
		include = val[index] + solve(index-1, W - wt[index], wt, val);
	
	// exclude
	int exclude = 0 + solve(index-1, W, wt, val);

	return max(include, exclude);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here

	return solve(n-1, maxWeight, weight, value);
}
*/


int main() {
    
    return 0;
}