// A. Find Minimum Operations
// Codeforces : https://codeforces.com/contest/2020/problem/A

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void run() {
    ll n, k;
    cin >> n >> k;

    if(k == 1) { // special case
        cout << n << "\n";
        return;
    }

    ll cnt = 0LL;
    while(n) {
        cnt += n%k;
        cout << n%k << " ";
        n /= k;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}