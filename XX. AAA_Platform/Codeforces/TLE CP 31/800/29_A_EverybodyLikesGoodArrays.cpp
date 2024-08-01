// A. Everybody Likes Good Arrays
// Codeforces : https://codeforces.com/problemset/problem/1777/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    for(int i = 0; i < n-1; i++) {
        if((a[i]&1) == (a[i+1]&1)) cnt++;
    }

    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}