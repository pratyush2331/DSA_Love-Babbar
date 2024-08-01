// A. We Need the Zero
// Codeforces : https://codeforces.com/problemset/problem/1805/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    vector<int> a(n);
    int xorSum = 0, cntZero;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        xorSum ^= a[i];
    }

    if(a.size()&1) {
        cout << xorSum << "\n";
    }
    else {
        if(xorSum == 0) cout << 0 << "\n";
        else cout << -1 << "\n";
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