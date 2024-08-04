#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    ll n;
    cin >> n;

    vector<ll> even, odd;
    for(ll i = 0; i < n; i++) {
        ll data;
        cin >> data;
        if(data&1) odd.push_back(data);
        else even.push_back(data);
    }

    if(even.empty() || odd.empty()) {
        cout << 0 << "\n";
        return;
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    ll last = odd.back();
    for(ll i = 0; i < even.size(); i++) {
        if(last > even[i]) {
            last += even[i];
        }
        else {
            cout << even.size()+1 << "\n";
            return;
        }
    }
    cout << even.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while(t--) run();
        
    return 0;
}