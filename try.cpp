// Digit DP
// 1 <= L <= R <= 10^18

#include<iostream>
#include<cstring>
using namespace std;

int dp[101][181][2];
int solveDP(string& num, int n, int x, int tight) {
    if(x < 0) return 0;
    if(n == 1) {
        if(x >= 0 && x <= 9)
            return 1;
        return 0;
    }

    int ans = 0;
    int ub = tight ? (num[num.length() - n] - '0') : 9;
    for(int digit = 0; digit <= ub; digit++) {
        ans += solveDP(num, n-1, x - digit, tight & (digit == ub));
    }

    return ans;
}

int main() {
    string num;
    cout << "Enter upper value : ";
    cin >> num;

    int x;
    cout << "Enter x : ";
    cin >> x;

    memset(dp, -1, sizeof(dp));
    cout << solveDP(num, num.length(), x, 1) << endl;
    
    return 0;
}