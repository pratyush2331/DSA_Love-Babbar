// A. Forbidden Integer
// Codeforces : https://codeforces.com/problemset/problem/1845/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n, k, x;
    cin >> n >> k >> x;

    bool flag = 0;
    if(x != 1) {
        cout << "YES\n" << n << "\n";
        for(int i = 1; i <= n; i++) {
            cout << 1 << " ";
        }
        cout << "\n";
    }
    else if(k == 1) cout << "NO\n";
    else if(n&1) {
        if(k < 3) cout << "NO\n";
        else {
            cout << "YES\n" << n/2 << "\n";
            for(int i = 1; i < n/2; i++) {
                cout << 2 << " ";
            }
            cout << 3 << "\n";
        }
    }
    else {
        cout << "YES\n" << n/2 << "\n";
        for(int i = 1; i <= n/2; i++) {
            cout << 2 << " ";
        }
        cout << "\n";
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