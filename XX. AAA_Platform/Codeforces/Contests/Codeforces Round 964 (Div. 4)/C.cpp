// 

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void run() {
    ll n, s, m;
    cin >> n >> s >> m;

    vector<pll> taskT(n);
    for(int i = 0; i < n; i++) {
        cin >> taskT[i].F >> taskT[i].S;
    }

    ll lastTaskT = 0;
    for(int i = 0; i < n; i++) {
        ll leftT = taskT[i].F - lastTaskT;
        if(leftT >= s) {
            cout << "YES\n";
            return;
        }
        lastTaskT = taskT[i].S;
    }
    if(m-lastTaskT >= s) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}