// 

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void run() {
    int n;
    cin >> n;
    
    int count_y0 = 0, count_y1 = 0;
    set<ll> y0, y1;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (y == 0) {
            y0.insert(x);
        } else {
            y1.insert(x);
        }
    }

    ll ans = 0;
    // when both sets have same x
    for (const auto& x : y0) {
        if (y1.find(x) != y1.end()) ans += y0.size() + y1.size() - 2;
    }

    // base in y0 set
    for (const auto& x : y0) {
        if (y1.find(x + 1) != y1.end() && y0.find(x + 2) != y0.end()) ans++;
    }

    // base in y1 set
    for (const auto& x : y1) {
        if (y1.find(x + 1) != y1.end() && y0.find(x - 1) != y0.end()) ans++;
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