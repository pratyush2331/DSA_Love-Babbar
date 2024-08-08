// 

#include<bits/stdc++.h>
using namespace std;

void run() {
    int l, r;
    cin >> l >> r;

    int p = log2(l) / log2(3);
    p++;

    int ans = 2*p;
    while(l < r) {
        int k = log2(r) / log2(3);
        int q = pow(3,k);
        int cnt = r - max(q, l+1);
        ans += ((k+1) * (cnt+1));
        r = q-1;
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