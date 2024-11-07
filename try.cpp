// 

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void run() {
    int a = 9999999;
    while(a) {
        cout << (a&1) << " ";
        a >>= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while(t--) run();
    
    return 0;
}