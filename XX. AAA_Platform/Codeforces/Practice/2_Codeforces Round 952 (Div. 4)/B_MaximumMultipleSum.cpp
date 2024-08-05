// B. Maximum Multiple Sum
// Codeforces : https://codeforces.com/contest/1985/problem/B

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    int maxSum = -1;
    int ans = 0;
    for(int x = 2; x <= n; x++) {
        int sum = 0;
        for(int i = x; i <= n; i += x) {
            sum += i;
        }

        if(sum > maxSum) {
            maxSum = sum;
            ans = x;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}