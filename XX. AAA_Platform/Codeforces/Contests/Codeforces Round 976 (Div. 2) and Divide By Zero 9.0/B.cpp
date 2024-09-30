// B. Brightness Begins
// Codeforces : https://codeforces.com/contest/2020/problem/B

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void run() {
    ll n;
    cin >> n;

    ll s = n, e = 2e18;
    ll ans = 0LL;
    while(s <= e) {
        ll mid = s + (e-s) / 2;

        ll rt = sqrt(mid);
        while(rt * rt > mid) rt--;
        while((rt + 1) * (rt + 1) <= mid) rt++;

        ll x = mid - rt;
        if(x >= n) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}