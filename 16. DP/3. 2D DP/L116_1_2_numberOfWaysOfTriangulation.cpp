// Number of Ways of Triangulation
// pepcoding video : https://www.youtube.com/watch?v=jSGW3YKkyHQ

#include<iostream>
#include<vector>
using namespace std;

int catalanNumber(int n) {
    vector<int> dp(n+1, 0);

    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j]*dp[i-j-1];
        }
    }

    return dp[n];
}

int numberOfWaysOfTriangulation(int n) {
    if(n <= 2)
        return 0;
    
    return catalanNumber(n-2);
}

int main() {
    int n;
    cin >> n;

    cout << "Number of ways of triangulation of " << n << " = " << numberOfWaysOfTriangulation(n) << endl;
    
    return 0;
}