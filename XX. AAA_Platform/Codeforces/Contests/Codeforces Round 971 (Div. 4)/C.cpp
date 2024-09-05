// 

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void run() {
    int x, y, k;
    cin >> x >> y >> k;

    ll cnt = 0;
    ll divx = (x % k == 0) ? x/k : (x/k) + 1;
    ll divy = (y % k == 0) ? y/k : (y/k) + 1;
    ll ans = divx + divy + abs(divx - divy);
    if(divx > divy) {
        ans--;
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