// C. Good Prefixes
// Codeforces : https://codeforces.com/contest/1985/problem/C

#include<bits/stdc++.h>
using namespace std;

using ll = long long;


// method-1 : w/o using extra arrays
void run() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll cnt = 0;
    ll preMax = -1, preSum = 0;
    for(int i = 0; i < n; i++) {
        preSum += a[i];
        preMax = max(preMax, a[i]);

        if(preSum == (2*preMax)) cnt++;
    }

    cout << cnt << "\n";
}


// method-0 : using extra 2 arrays
/*
void run() {
    ll n;
    cin >> n;

    vector<ll> a(n), pre(n, 0), maxEle(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0) {
            pre[i] = a[i];
            maxEle[i] = a[i];
        }
        else {
            pre[i] = pre[i-1] + a[i];
            maxEle[i] = max(maxEle[i-1], a[i]);
        }
    }

    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        if(pre[i] == (2*maxEle[i])) cnt++;
    }

    cout << cnt << "\n";
}
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}