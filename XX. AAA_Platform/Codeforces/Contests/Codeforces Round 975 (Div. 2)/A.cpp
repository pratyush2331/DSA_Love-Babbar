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

    vector<int> a(n);
    int maxEven = 0, maxOdd = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if((i+1)&1) maxOdd = max(maxOdd, a[i]);
        else maxEven = max(maxEven, a[i]);
    }
    
    cout << max(maxOdd + (n+1)/2, maxEven + n/2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}