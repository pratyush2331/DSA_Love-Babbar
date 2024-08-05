// E. Secret Box
// Codeforces : https://codeforces.com/contest/1985/problem/E

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

/*
TC : O(x*y)
SC : O(1)
*/
void run() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;

    ll ans = 0;
    for(ll a = 1; a <= x; a++) {
        if(k%a == 0) { // k is divisible by a
            for(ll b = 1; b <= y; b++) {
                if(k%b == 0) { // k is divisble b
                    if(k%(a*b) == 0) { // k is divisible by c
                        ll c = k / (a*b);
                        if(c <= z) { // c <= z
                            // found possible a, b and c
                            ans = max(ans, (x-a+1) * (y-b+1) * (z-c+1)); // ans = maximum possibilities of storing
                        }
                    }
                }
            }
        }
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