// 

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

    ll s = 1, e = n;
    ll ans = LLONG_MAX;
    while(s <= e) {
        ll mid = s + (e-s) / 2;

        ll preSum = (mid * (2 * k + mid - 1)) / 2;

        ll suffSum = ((n - mid) * (2 * (k + mid) + (n - mid - 1))) / 2;

        ll diff = preSum - suffSum;

        ans = min(ans, abs(diff));

        if (diff >= 0) {
            e = mid - 1;
        } else {
            s = mid + 1;
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