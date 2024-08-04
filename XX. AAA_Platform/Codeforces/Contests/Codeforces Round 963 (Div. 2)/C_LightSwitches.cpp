// C. Light Switches
// Codeforces : https://codeforces.com/contest/1993/problem/C

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool allLightsOn(ll T, ll k, const vector<ll>& a) {
    for (ll time : a) {
        ll diff = T - time;
        if ((diff / k)&1) {
            return false;
        }
    }
    return true;
}

void run() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans = -1;
    for(int i = 0; i < k; i++) {
        if(allLightsOn(a[n-1]+i, k, a)) {
            ans = a[n-1]+i;
            break;
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