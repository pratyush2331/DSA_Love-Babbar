// B2. Bouquet (Hard Version)
// Codeforces : https://codeforces.com/contest/1995/problem/B2
    
#include<bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << '(' << #__VA_ARGS__ << '):', dbg_out(__VA_ARGS__)

using ll = long long;

void run() {
    ll n, m;
    cin >> n >> m;

    vector<ll> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    unordered_map<ll, ll> mp;
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        mp[v[i]] = data;
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    for(int i = 0; i < n; i++) { // individual flower
        ans = max(ans, min((m/v[i]), mp[v[i]]) * v[i]);
    }

    for(int i = 0; i < n-1; i++) { // Two flowers with difference <= 1
        if(v[i+1] - v[i] != 1) continue;
        ll temp = m;
        ll smaller = min((m/v[i]), mp[v[i]]);
        temp -= smaller*v[i];
        ll larger = min(temp/v[i+1], mp[v[i+1]]);
        temp -= larger * v[i+1];
        ll c = min(temp, min(mp[v[i+1]]-larger, smaller));
        temp -= c;
        ans = max(ans, m - temp);
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