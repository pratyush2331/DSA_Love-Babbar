// B. Battle for Survive
// Codeforces : https://codeforces.com/contest/2013/problem/B

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

    vector<int> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        if(i <= n-3) sum += a[i];
    }

    cout << a[n-1] - (a[n-2] - sum) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}