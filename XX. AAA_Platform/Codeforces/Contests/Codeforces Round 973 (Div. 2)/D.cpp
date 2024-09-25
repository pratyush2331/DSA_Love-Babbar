// D. Minimize the Difference
// Codeforces : https://codeforces.com/contest/2013/problem/D

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

    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    // ans = minimizeMaximum - maximizeMinimum
    ll minimizeMaximum, maximizeMinimum;

    // calculating minimizeMaximum
    ll s = -1e13;
    ll e = 1e13;
    while( s <= e) {
        ll mid = s + (e-s)/2;
        vector<ll> helper = a;
        for(ll i = 0; i < n-1; i++) {
            if(helper[i] > mid) {
                ll extra = helper[i] - mid;
                helper[i] -= extra;
                helper[i+1] += extra;
            }
        }
        if(helper[n-1] <= mid) { // possible minimizeMaximum
            minimizeMaximum = mid;
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }
    
    // calculating maximizeMinimum
    s = -1e13;
    e = 1e13;
    while( s <= e) {
        ll mid = s + (e-s)/2;
        vector<ll> helper = a;
        for(ll i = n-1; i > 0; i--) {
            if(helper[i] < mid) {
                ll extra = mid - helper[i];
                helper[i] += extra;
                helper[i-1] -= extra;
            }
        }
        if(helper[0] >= mid) { // possible maximizeMinimum
            maximizeMinimum = mid;
            s = mid+1;
        }
        else {
            e = mid-1;
        }
    }

    cout << (minimizeMaximum - maximizeMinimum) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}