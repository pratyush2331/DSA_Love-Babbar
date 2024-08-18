// A. Find K Distinct Points with Fixed Center

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void run() {
    ll xc, yc, k;
    cin >> xc >> yc >> k;

    if(k&1) { // odd
        cout << xc << " " << yc << "\n";
        k--;
    }

    int cnt = 1;
    while(k) { // even
        cout << (xc-cnt) << " " << yc << "\n";
        cout << (xc+cnt) << " " << yc << "\n";
        
        cnt++;
        k -= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}