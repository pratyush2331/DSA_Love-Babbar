// Ninja’s Training
// CodeStudio : https://www.codingninjas.com/studio/problems/ninja-s-training_3621003

#include<iostream>
using namespace std;


// method-3 : space optimization
/*
TC : O(N*4*3) = O(N)
SC : O(2*4) = O(1)
*/
// /*
int ninjaTraining(int n, vector<vector<int>> &points) {
    // Write your code here.
    vector<int> prev(4, 0);
    vector<int> curr(4, 0);

    // from base case
    for(int last = 0; last < 4; last++) {
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                prev[last] = max(prev[last], points[0][task]);
            }
        }
    }

    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 4; last++) {
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + prev[task];
                    curr[last] = max(curr[last], point);
                }
            }
        }
        prev = curr;
    }

    return prev[3];
}
// */



// method-2 : tabulation
/*
TC : O(N*4*3) = )(N)
SC : O(N*4) = O(N)
*/
/*
int ninjaTraining(int n, vector<vector<int>> &points) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // from base case
    for(int last = 0; last < 4; last++) {
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                dp[0][last] = max(dp[0][last], points[0][task]);
            }
        }
    }

    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 4; last++) {
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n-1][3];
}
*/



// method-1 : recursion + memoization
/*
TC : O(N*4*3) = O(N)
SC : O(N) + O(N*4) = O(N)
*/
/*
int f(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
    if(day == 0) {
        int maxi = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1)
        return dp[day][last];

    int maxi = 0;

    for(int task = 0; task < 3; task++) {
        if(task != last) {
            int point = points[day][task] + f(day-1, task, points, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n-1, 3, points, dp);
}
*/



// method-0 : recursion --> will give TLE
/*
int f(int day, int last, vector<vector<int>>& points) {
    if(day == 0) {
        int maxi = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    int maxi = 0;

    for(int task = 0; task < 3; task++) {
        if(task != last) {
            int point = points[day][task] + f(day-1, task, points);
            maxi = max(maxi, point);
        }
    }

    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    // Write your code here.
    return f(n-1, 3, points);
}
*/


int main() {
    
    return 0;
}