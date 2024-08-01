// A. Coins
// Codeforces : https://codeforces.com/problemset/problem/1814/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// method-1
void run() {
    ll n, k;
    cin >> n >> k;

    if(n&1 && k%2 == 0) cout << "NO\n";
    else cout << "YES\n";
}

// method-0
/*
void run() {
    ll n, k;
    cin >> n >> k;

    if(n%2 == 0 || n%k == 0) cout << "YES\n";
    else {
        int res = n - k;
        if(res % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}