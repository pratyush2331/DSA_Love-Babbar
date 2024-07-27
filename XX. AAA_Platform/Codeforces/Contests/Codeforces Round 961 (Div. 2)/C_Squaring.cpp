// C. Squaring
// Codeforces : https://codeforces.com/contest/1995/problem/C

#include<bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << '] (' << #__VA_ARGS__ << '):', dbg_out(__VA_ARGS__)

using ll = long long;

void run() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<ll> ops(n, 0);
    for(int i = 1; i < n; i++) {
        ll v1 = v[i-1];
        ll v2 = v[i];

        if(v1 > 1 && v2 == 1) { // impossible case
            cout << "-1\n";
            return;
        }

        ll extra = 0;
        while(v1 != 1 && v1*v1 <= v2) {
            extra--;
            v1 *= v1;
        }
        while(v2 < v1) {
            extra++;
            v2 *= v2;
        }

        ops[i] = max(0ll, ops[i-1] + extra);
    }

    ll ans = 0;
    for(auto ele : ops) {
        ans += ele;
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